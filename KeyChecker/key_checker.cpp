#include "key_checker.h"

#include <iostream>
#include <thread>


#ifdef __unix__ /* __unix__ is usually defined by compilers targeting Unix systems */
	/**
	 Linux (POSIX) implementation of _kbhit().
	 Morgan McGuire, morgan@cs.brown.edu
	 */
	#include <stdio.h>
	#include <sys/select.h>
	#include <termios.h>
	#include <stropts.h>
	#include <sys/ioctl.h>

	static int _kbhit() {
		static const int STDIN = 0;
		static bool initialized = false;

		if (! initialized) {
			// Use termios to turn off line buffering
			termios term;
			tcgetattr(STDIN, &term);
			term.c_lflag &= ~ICANON;
			tcsetattr(STDIN, TCSANOW, &term);
			setbuf(stdin, NULL);
			initialized = true;
		}

		int bytesWaiting;
		ioctl(STDIN, FIONREAD, &bytesWaiting);
		return bytesWaiting;
	}
#elif defined(_WIN32) || defined(WIN32)	 /* _Win32 is usually defined by compilers targeting 32 or   64 bit Windows systems */

	#include <conio.h>

#endif	

namespace KeyChecker
{
	KeyChecker::KeyChecker()
		: mProcessThread()
		, mKeysQueue()
		, mKeysQueueLock()
	{
		mProcessThread = std::make_unique<std::thread>([this](){
											while(1)
											{
												char res = -1;
												int bytesWaiting = _kbhit();
												if(bytesWaiting == 1)
												{
													res = getchar();
													this->UpdateKeysQueue(res);
												}
												else
												{
													//erase non-ASCII symbol
													while(bytesWaiting > 0)
													{
														getchar();
														bytesWaiting--;
													}
												}

											}
										});
	}
	std::deque<char> KeyChecker::GetKeysQueue()
	{
		std::lock_guard<std::mutex> lock(mKeysQueueLock);
		std::deque<char> res = mKeysQueue;
		mKeysQueue.clear();
		return res;
	}
		
	void KeyChecker::UpdateKeysQueue(char key)
	{
		std::lock_guard<std::mutex> lock(mKeysQueueLock);
		mKeysQueue.push_back(key);
	}
}//namespace KeyChecker
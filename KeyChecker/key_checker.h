#ifndef KEY_CHECKER_H
#define KEY_CHECKER_H

#include <memory>
#include <thread>
#include <mutex>

#include <deque>

namespace KeyChecker
{
	class KeyChecker
	{
	public:
		KeyChecker();
		std::deque<char> GetKeysQueue();
		
	private:
		void UpdateKeysQueue(char);

	private:
		std::unique_ptr<std::thread> mProcessThread;
		std::deque<char> mKeysQueue;
		std::mutex mKeysQueueLock;
	};
}//namespace KeyChecker


#endif //KEY_CHECKER_H
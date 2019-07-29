#ifndef KEY_CHECKER_H
#define KEY_CHECKER_H

#include <memory>
#include <thread>
#include <mutex>
#include <atomic>

#include <deque>

namespace KeyChecker
{
	class KeyChecker
	{
	public:
		KeyChecker();
		~KeyChecker();
		std::deque<char> GetKeysQueue();
		
	private:
		void UpdateKeysQueue(char);
		bool ProcessThreadShutdown(){ return mProcessThreadShutdown; };

	private:
		std::unique_ptr<std::thread> mProcessThread;
		std::deque<char> mKeysQueue;
		std::mutex mKeysQueueLock;
		std::atomic_bool mProcessThreadShutdown;
	};
}//namespace KeyChecker


#endif //KEY_CHECKER_H
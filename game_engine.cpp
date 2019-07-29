#include "game_engine.h"

#include <iostream>

GameEngine::GameEngine()
	:mKeyChecker()
	{}

void GameEngine::StartGame()
{
	bool endGame = false;
	while(!endGame)
	{
		std::deque<char> res = mKeyChecker.GetKeysQueue();
		while(res.size() > 0)
		{
			switch(res.front())
			{
				case 'w':
					std::cout << "Key pressed: " << res.front() << std::endl;
					break;
				case 'q':
					endGame = true;
					std::cout << "User requested quit." << std::endl;
					break;
				default:
					break;
			}
			
			res.pop_front();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}
}
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
		auto start = std::chrono::system_clock::now();

		//check user input
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

		// calculate player

		// calculate world

		// check collisions


		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> diff = end-start;
		auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
		std::this_thread::sleep_for(std::chrono::milliseconds(5 - duration_ms));
	}
}
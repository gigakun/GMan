#include "game_engine.h"

#include <iostream>

GameEngine::GameEngine()
	: mKeyChecker()
	, mPlayer()
	, mWorld()
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
					mPlayer.Up();
					break;
				case 's':
					mPlayer.Down();
					break;
				case 'a':
					mPlayer.Left();
					break;
				case 'd':
					mPlayer.Right();
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
		mPlayer.Refresh();
		int playerX = -1;
		int playerY = -1;
		mPlayer.GetCurrentPos(playerX, playerY);

		// calculate world
		mWorld.SetPlayerPos(playerX, playerY);
		mWorld.Refresh();

		// check collisions


		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> diff = end-start;
		auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
		std::this_thread::sleep_for(std::chrono::milliseconds(100 - duration_ms));
	}
}
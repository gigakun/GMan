#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "KeyChecker/key_checker.h"

class GameEngine
{
public:
	GameEngine();
	void StartGame();
private:
	KeyChecker::KeyChecker mKeyChecker;
};

#endif //GAME_ENGINE_H
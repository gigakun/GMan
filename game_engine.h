#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "KeyChecker/key_checker.h"
#include "player.h"
#include "world.h"


class GameEngine
{
public:
	GameEngine();
	void StartGame();
private:
	KeyChecker::KeyChecker mKeyChecker;
	Player mPlayer;
	World mWorld;
};

#endif //GAME_ENGINE_H
all:
	g++ -pthread main.cpp player.cpp world.cpp game_engine.cpp KeyChecker/key_checker.cpp KeyChecker/key.cpp -o GMan.out
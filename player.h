#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
	Player()
		: x(0)
		, y(0)
		{}
	void Left();
	void Right();
	void Up();
	void Down();
	void Jump();
	void Refresh();
	void GetCurrentPos(int &outX, int &outY);
private:
	int x;
	int y;


};

#endif //PLAYER_H
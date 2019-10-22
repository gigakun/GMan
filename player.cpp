#include "player.h"

void Player::Jump()
{

}
void Player::Refresh()
{
	
}
void Player::Left()
{
	x--;
}
void Player::Right()
{
	x++;
}
void Player::Up()
{
	y--;
}
void Player::Down()
{
	y++;
}
void Player::GetCurrentPos(int &outX, int &outY)
{
	outX = x;
	outY = y;
}

#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <string>
#include <deque>

class World
{
public:
	World();
	void SetPlayerPos(int x, int y);
	void Refresh();

	int GetWidth(){ return m_Width; }
	int GetHeight(){ return m_Height; }
private:
	char GetBlock(int x, int y);
	std::string GetLine(int y);
private:
	int m_Width;
	int m_Height;
	std::deque<std::string> m_DisplayedWorld;

	int m_PlayerX;
	int m_PlayerY;
};

#endif //WORLD_H
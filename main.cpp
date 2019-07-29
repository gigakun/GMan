#include <iostream>

#include <chrono>
#include <thread>

#include <deque>
#include <string>

#include "game_engine.h"

using namespace std;

class World
{
public:
	World()
		: m_Width(64)
		, m_Height(16)
		, m_DisplayedWorld()
	{
		string str = "    *       *     ";

		for(int line = 0; line < m_Width; line++)
		{
			m_DisplayedWorld.push_back(str);
		}
	}
	~World(){};
	char GetBlock(int x, int y)
	{
		char res = -1;
		if(x < m_DisplayedWorld.size() && y < m_DisplayedWorld.at(0).length())
		{
			if((x == 0) 
			    || (y == 0) 
				|| (x == (m_Width - 1))
			    || (y == (m_Height - 1)))
		    {
		    	res = '+';
		    }
		    else
		    {
				res = m_DisplayedWorld.at(x).at(y);
		    }
		}
		return res;
	}
	string GetLine(int y)
	{
		string res = "";
		if(y < m_DisplayedWorld.at(0).length())
		{
			for(int x = 0; x < m_DisplayedWorld.size(); x++)
			{
		    	char block = GetBlock(x, y);
		    	if(block != -1)
				{
					res += block;
				}
				else 
				{
					cout << "GetLine(int y): ERROR: x = " << x << ", y = " << y << " result is -1" << endl;
				}
		    }
		}
		return res;
	}

	int GetWidth(){ return m_Width; }
	int GetHeight(){ return m_Height; }



private:
	int m_Width;
	int m_Height;
	deque<string> m_DisplayedWorld;
};

int main(int argc, char const *argv[])
{
	/*system("clear");
	World world;
	for(int y = 0; y < world.GetHeight(); y++)
	{
		for(int x = 0; x < world.GetWidth(); x++)
		{
			char block = world.GetBlock(x, y);
			if(block != -1)
			{
				cout << block;
			}
			else 
			{
				cout << "main(int argc, char const *argv[]): ERROR: x = " << x << ", y = " << y << " result is -1" << endl;
			}
		}
		cout << endl;
	}
	for(int y = 0; y < world.GetHeight(); y++)
	{
		string line = world.GetLine(y);
		if(line != "")
		{
			cout << line << endl;
		}
		else 
		{
			cout << "main(int argc, char const *argv[]): ERROR: y = " << y << ", line is invalid" << endl;
		}
	
	}*/

	GameEngine game;
	
	game.StartGame();

	return 0;
}

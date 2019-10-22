#include "world.h"

#include <cstdlib>

using std::string;
using std::cout;
using std::endl;

World::World()
		: m_Width(64)
		, m_Height(16)
		, m_DisplayedWorld()
		, m_PlayerX(-1)
		, m_PlayerY(-1)
	{
		string str = "    *       *     ";

		for(int line = 0; line < m_Width; line++)
		{
			m_DisplayedWorld.push_back(str);
		}
	}



void World::SetPlayerPos(int x, int y)
{
	m_PlayerX = x;
	m_PlayerY = y;
}

void World::Refresh()
{
	std::system("clear");
	for(int y = 0; y < GetHeight(); y++)
	{
		string line = GetLine(y);
		if(line != "")
		{
			cout << line << endl;
		}
		else 
		{
			cout << "main(int argc, char const *argv[]): ERROR: y = " << y << ", line is invalid" << endl;
		}
	
	}
}

char World::GetBlock(int x, int y)
{
	char res = -1;
	if(x < m_DisplayedWorld.size() && y < m_DisplayedWorld.at(0).length())
	{
		if((x == m_PlayerX)
			&& (y == m_PlayerY))
		{
			res = 'G';
		}
		else if((x == 0) 
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
std::string World::GetLine(int y)
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
#ifndef _HEXMAP_

#define _HEXMAP_

#include "hexPanel.h"

class hexMap
{
private:
	hexPanel** hexBoard;
	unsigned short boardSize;
	unsigned short xCur;
	unsigned short yCur;

public:
	hexMap(unsigned short size = 1):xCur(0), yCur(0), boardSize(size)
	{
		hexBoard = new hexPanel*[boardSize];
		for(int i = 0; i < boardSize; i++){
			hexBoard[i] = new hexPanel[boardSize];
		}
	}
	~hexMap(){}
	void setPanel(unsigned short x, unsigned short y, short data)
	{
		hexBoard[y][x].setPanel(x, y, data);
	}
	hexPanel* getPanel(unsigned short x, unsigned short y)
	{
		return hexBoard[y][x].getPanel();
	}
};

#endif // !_HEXMAP_

#ifndef _HEXBOARD_

#define _HEXBOARD_

#include "hexPanel.h"

class hexBoard
{
private:
	unsigned short boardSize;
	hexPanel** gameBoard;
	hexPanel* player;

public:
	hexBoard(unsigned short size):boardSize(size)
	{
		gameBoard = new hexPanel*[boardSize];
		for(int i = 0; i < boardSize; i++){
			gameBoard[i] = new hexPanel[boardSize];
		}

		player = new hexPanel[2];
	}
	~hexBoard()
	{
		for(int i = 0; i < boardSize; i++){
			delete [] gameBoard[i];
		}
		delete [] gameBoard;
	}
	int isWinner();	//	is there a winner?
	int setPanel(unsigned short xpos, unsigned short ypos, unsigned short color);	//	set a panel in the game board
};


#endif // !_HEXBOARD_

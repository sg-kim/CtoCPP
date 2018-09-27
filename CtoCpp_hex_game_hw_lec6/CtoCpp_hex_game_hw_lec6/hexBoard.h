#ifndef _HEXBOARD_

#define _HEXBOARD_

#include "hexPanel.h"
#include "hexList.h"
#include "hexListList.h"

class hexBoard
{
private:
	unsigned short boardSize;
	hexPanel** gameBoard;
	hexPanel* player;
	hexListList* pathList;

public:
	hexBoard(unsigned short size):boardSize(size)
	{
		gameBoard = new hexPanel*[boardSize];
		for(int i = 0; i < boardSize; i++){
			gameBoard[i] = new hexPanel[boardSize];
		}

		player = new hexPanel[2];
		pathList = new hexListList[2];
	}
	~hexBoard()
	{
		for(int i = 0; i < boardSize; i++){
			delete [] gameBoard[i];
		}
		
		delete [] gameBoard;

		delete [] player;

		delete [] pathList;
	}
	int isWinner();	//	is there a winner?
	void setPanel(unsigned short xpos, unsigned short ypos, unsigned short color);	//	set a panel in the game board
	bool updatePath(hexPanel panel);	//	update path info whenever a player newly occupies a panel
	void displayBoard();
	void displayPath();
};


#endif // !_HEXBOARD_

#ifndef _HEXBOARD_

#define _HEXBOARD_

#include <iostream>

#include "hexPanel.h"
#include "hexList.h"
#include "hexListList.h"

using std::cout;
using std::endl;

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
		for(int y = 0; y < boardSize; y++){
			gameBoard[y] = new hexPanel[boardSize];
		}

		player = new hexPanel[2];
		pathList = new hexListList[2];
	}
	~hexBoard()
	{
		for(int y = 0; y < boardSize; y++){
			delete [] gameBoard[y];
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

int hexBoard::isWinner()
{
	int win = -1;

	bool edgeTop = false;
	bool edgeBottom = false;
	bool edgeLeft = false;
	bool edgeRight = false;

	edgeStatus edge;

	hexList* curPath;
	hexPanel* curPanel;

	//	consider all players
	for(int i = 0; i < 2; i++){

		pathList[i].resetCursor();	//	move to the head element in a given list of paths

		curPath = pathList[i].getList();

		//	traversing all paths
		while(curPath != nullptr){

			curPath->resetCursor();		//	move to the head element in a given list(= path)

			curPanel = curPath->getHexPanel();

			//	traversing panels in a path
			while(curPanel != nullptr){

				edge = curPanel->getEdgeStatus();

				if((edge == edgeStatus::TOP) || (edge == edgeStatus::TOPLEFT) || (edge == edgeStatus::TOPRIGHT)){
					edgeTop = true;
					curPanel = curPanel->getNext();
					continue;
				}
				if((edge == edgeStatus::BOTTOM) || (edge == edgeStatus::BOTTOMLEFT) || (edge == edgeStatus::BOTTOMRIGHT)){
					edgeBottom = true;
					curPanel = curPanel->getNext();
					continue;
				}
				if((edge == edgeStatus::LEFT) || (edge == edgeStatus::TOPLEFT) || (edge == edgeStatus::BOTTOMLEFT)){
					edgeLeft = true;
					curPanel = curPanel->getNext();
					continue;
				}
				if((edge == edgeStatus::RIGHT) || (edge == edgeStatus::TOPRIGHT) || (edge == edgeStatus::BOTTOMRIGHT)){
					edgeRight = true;
					curPanel = curPanel->getNext();
					continue;
				}

				curPanel = curPanel->getNext();

			}	//	traversing all panels in a path

			if((edgeTop == true && edgeBottom == true) || (edgeLeft == true && edgeRight == true)){
				win = i;
				break;
			}

			curPath = curPath->getNext();	//	move to the next path

			edgeTop = false;
			edgeBottom = false;
			edgeLeft = false;
			edgeRight = false;

		}	//	traversing all paths

	}	//	consider all players

	return win;
}    

void hexBoard::setPanel(unsigned short xpos, unsigned short ypos, unsigned short color)
{
	hexPanel panel;

	panel.setXPos(xpos, boardSize);
	panel.setYPos(ypos, boardSize);
	panel.setColor(color);
	panel.setNext(nullptr);

	//	set position(x, y) and color of a hex panel in the board
	gameBoard[ypos][xpos].setXPos(xpos, boardSize);
	gameBoard[ypos][xpos].setYPos(ypos, boardSize);
	gameBoard[ypos][xpos].setColor(color);

	//	include the new panel in the path list
	updatePath(panel);
}

bool hexBoard::updatePath(hexPanel panel)
{
	unsigned short color = panel.getColor();
	unsigned short xPos = panel.getXpos();
	unsigned short yPos = panel.getYpos();
	bool newPath = true;
	hexList* curPath;
	hexPanel* curPanel = nullptr;

	//	examine whether or not there are neighbor friendly hex panel by examining a player(= color)'s paths graphs
	pathList[color].resetCursor();

	curPath = pathList[color].getList();

	//	if there is a friendly hexPanel, expand the player's path graph or create new graph

	//	basic hex formation
	//
	//	    | UL| UR|
	//	  | L | * | R |
	//		| BL| BR|
	//
	while(curPath != nullptr){		//	visit all paths

		//	left neighbor
		if((xPos - 1) >= 0){

			curPanel = curPath->search((xPos - 1), yPos, color);

			if(curPanel != nullptr){
				newPath = false;
				curPath->append(&panel, boardSize);
				curPath = curPath->getNext();
				continue;
			}
		}

		//	upper-left neighbor
		if((xPos - 1) >= 0 && (yPos - 1) >= 0){

			curPanel = curPath->search((xPos - 1), (yPos - 1), color);

			if(curPanel != nullptr){
				newPath = false;
				curPath->append(&panel, boardSize);
				curPath = curPath->getNext();
				continue;
			}
		}

		//	upper-right neighbor
		if((yPos - 1) >= 0){

			curPanel = curPath->search(xPos, (yPos - 1), color);

			if(curPanel != nullptr){
				newPath = false;
				curPath->append(&panel, boardSize);
				curPath = curPath->getNext();
				continue;
			}
		}



		//	right neighbor
		if((xPos + 1) <= (boardSize - 1)){

			curPanel = curPath->search((xPos + 1), yPos, color);

			if(curPanel != nullptr){
				newPath = false;
				curPath->append(&panel, boardSize);
				curPath = curPath->getNext();
				continue;
			}
		}

		//	bottom-right neighbor
		if((yPos + 1) <= (boardSize - 1)){

			curPanel = curPath->search(xPos, (yPos + 1), color);

			if(curPanel != nullptr){
				newPath = false;
				curPath->append(&panel, boardSize);
			}
		}

		//	bottom - left neighbor
		if((xPos - 1) >= 0 && (yPos + 1) <= (boardSize - 1)){

			curPanel = curPath->search((xPos - 1), (yPos + 1), color);

			if(curPanel != nullptr){
				newPath = false;
				curPath->append(&panel, boardSize);
				curPath = curPath->getNext();
				continue;
			}
		}

		curPath = curPath->getNext();
	}	//	visit all paths

	if(newPath == true){
		pathList[color].append(&panel, boardSize);
	}

	return newPath;
}

void hexBoard::displayBoard()
{
	//for(int i = 0; i < boardSize; i++){
	//	for(int j = 0; j < boardSize; j++){
	//		cout << "(" << gameBoard[j][i].getXpos() << ", " << gameBoard[j][i].getYpos() << ", " << gameBoard[j][i].getColor() << ")" << "\t";
	//	}
	//	cout << endl;
	//}
	//cout << endl;

	for(int y = 0; y < boardSize; y++){
		if(y%2 == 1){
			cout << "  ";
		}
		for(int x = 0; x < boardSize; x++){
			cout << "| ";
			if(gameBoard[y][x].getColor() < 0){
				cout << "_" << " ";
			}
			else{
				cout << gameBoard[y][x].getColor() << " ";
			}
		}
		cout << "|" << endl;
	}
	cout << endl;
}

void hexBoard::displayPath()
{
	pathList[0].display();
	pathList[1].display();
}

#endif // !_HEXBOARD_

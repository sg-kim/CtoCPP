
#include <iostream>

#include "hexBoard.h"
#include "hexPanel.h"
#include "hexList.h"
#include "hexListList.h"

using namespace std;

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
	gameBoard[xpos][ypos].setXPos(xpos, boardSize);
	gameBoard[xpos][ypos].setYPos(ypos, boardSize);
	gameBoard[xpos][ypos].setColor(color);

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
	hexPanel* curPanel;

	//	examine whether or not there are neighbor friendly hex panel by examining a player(= color)'s paths graphs
	pathList[color].resetCursor();

	curPath = pathList[color].getList();

	//	if there is a friendly hexPanel, expand the player's path graph or create new graph

	while(curPath != nullptr){		//	visit all paths

		////	upper-left neighbor
		//if((xPos - 1) >= 0 && (yPos - 1) >= 0){

		//	curPanel = curPath->search((xPos - 1), (yPos - 1), color);

		//	if(curPanel != nullptr){
		//		newPath = false;
		//		curPath->append(&panel, boardSize);
		//		continue;
		//	}
		//}

		////	upper-right neighbor
		//if((xPos + 1) <= (boardSize - 1) && (yPos - 1) >= 0){

		//	curPanel = curPath->search((xPos + 1), (yPos - 1), color);

		//	if(curPanel != nullptr){
		//		newPath = false;
		//		curPath->append(&panel, boardSize);
		//		continue;
		//	}
		//}

		////	left neighbor
		//if((xPos - 1) >= 0){

		//	curPanel = curPath->search((xPos - 1), yPos, color);

		//	if(curPanel != nullptr){
		//		newPath = false;
		//		curPath->append(&panel, boardSize);
		//		continue;
		//	}
		//}

		////	right neighbor
		//if((xPos + 1) <= (boardSize - 1)){

		//	curPanel = curPath->search((xPos + 1), yPos, color);

		//	if(curPanel != nullptr){
		//		newPath = false;
		//		curPath->append(&panel, boardSize);
		//		continue;
		//	}
		//}

		////	bottom-left neighbor
		//if((xPos - 1) >= 0 && (yPos + 1) <= (boardSize - 1)){

		//	curPanel = curPath->search((xPos - 1), (yPos + 1), color);

		//	if(curPanel != nullptr){
		//		newPath = false;
		//		curPath->append(&panel, boardSize);
		//		continue;
		//	}
		//}

		////	bottom-right neighbor
		//if((xPos + 1) <= (boardSize - 1) && (yPos + 1) <= (boardSize - 1)){

		//	curPanel = curPath->search((xPos + 1), (yPos + 1), color);

		//	if(curPanel != nullptr){
		//		newPath = false;
		//		curPath->append(&panel, boardSize);
		//	}
		//}
		
		curPath = curPath->getNext();
	}	//	visit all paths

	if(newPath == true){
		pathList[color].append(&panel, boardSize);
	}

	return newPath;
}

void hexBoard::displayBoard()
{
	for(int i = 0; i < boardSize; i++){
		for(int j = 0; j < boardSize; j++){
			cout << "(" << gameBoard[j][i].getXpos() << ", " << gameBoard[j][i].getYpos() << ", " << gameBoard[j][i].getColor() << ")" << "\t";
		}
		cout << endl;
	}
	cout << endl;
}


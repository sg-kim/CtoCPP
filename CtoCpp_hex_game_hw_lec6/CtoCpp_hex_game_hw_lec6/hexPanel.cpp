#include "hexPanel.h"

void hexPanel::examineEdge(unsigned short boardSize)
{
	if(xPos == 0){
		edgeLeft = true;
	}
	else{
		edgeLeft = false;
	}

	if(xPos == (boardSize - 1)){
		edgeRight = true;
	}
	else{
		edgeRight = false;
	}

	if(yPos == 0){
		edgeTop = true;
	}
	else{
		edgeTop = false;
	}

	if(yPos == (boardSize - 1)){
		edgeBottom = true;
	}
	else{
		edgeBottom = false;
	}
}

void hexPanel::setXPos(unsigned short xpos, unsigned short boardSize)
{
	if(xPos >= boardSize){
		xPos = (boardSize - 1);
	}

	xPos = xpos;
	examineEdge(boardSize);
}

void hexPanel::setYPos(unsigned short ypos, unsigned short boardSize)
{
	if(yPos >= boardSize){
		yPos = (boardSize - 1);
	}

	yPos = ypos;
	examineEdge(boardSize);
}

void hexPanel::setColor(unsigned short c)
{
	color = c;
}

unsigned short hexPanel::getXpos()
{
	return xPos;
}

unsigned short hexPanel::getYpos()
{
	return yPos;
}

short hexPanel::getColor()
{
	return color;
}


#include <iostream>

#include "hexList.h"

using namespace std;

void hexList::append(hexPanel* panel, unsigned short boardSize)
{
	if(head == nullptr){
		head = new hexPanel(panel->getXpos(), panel->getYpos(), panel->getColor(), nullptr, boardSize);
		cursor = head;
	}
	else{
		resetCursor();

		while(cursor->getNext() != nullptr){
			cursor = cursor->getNext();
		}

		cursor->setNext(new hexPanel(panel->getXpos(), panel->getYpos(), panel->getColor(), nullptr, boardSize));
	}
}

int hexList::getLength()
{
	int count = 0;

	resetCursor();

	while(cursor != nullptr){
		
		cursor = cursor->getNext();
		count++;
	}

	return count;
}

hexPanel* hexList::getHexPanel()
{
	return cursor;
}

hexList* hexList::getNext()
{
	return next;
}

void hexList::setNext(hexList* nextPtr)
{
	next = nextPtr;
}

hexPanel* hexList::search(unsigned short xPos, unsigned short yPos, short color)
{
	hexPanel* retVal = nullptr;
	
	resetCursor();

	while(cursor != nullptr){

		if((cursor->getXpos() == xPos) && (cursor->getYpos() == yPos) && (cursor->getColor() == color)){
			retVal = cursor;
			break;
		}

		cursor = cursor->getNext();
	}

	return retVal;
}

void hexList::resetCursor()
{
	cursor = head;
}

void hexList::display()
{
	resetCursor();

	while(cursor != nullptr){

		cout << "(" << cursor->getXpos() << ", " << cursor->getYpos() << ", " << cursor->getColor() << ")";
		cout << "-->";

		cursor = cursor->getNext();
	}
}
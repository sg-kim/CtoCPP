
#include "hexList.h"

void hexList::append(hexPanel* panel, unsigned short boardSize)
{
	cursor = head;

	while(cursor->getNext() != nullptr){
		cursor = cursor->getNext();
	}

	cursor->setNext(new hexPanel(panel->getXpos(), panel->getYpos(), panel->getColor(), nullptr, boardSize));
}

int hexList::getLength()
{
	cursor = head;
	int count = 0;

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

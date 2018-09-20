
#include "hexListList.h"

void hexListList::append(hexPanel* panel, unsigned short boardSize)
{
	cursor = new hexList();

	cursor->append(panel, boardSize);
}

hexPanel* hexListList::getPanel()
{
	return cursor->getHexPanel();
}

int hexListList::getLength()
{
	int count = 0;

	cursor = head;

	while(cursor != nullptr){

		count++;

		cursor = cursor->getNext();
	}

	return count;
}

void hexListList::resetCursor()
{
	cursor = head;
}

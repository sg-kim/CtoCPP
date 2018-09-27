
#include <iostream>

#include "hexListList.h"

using namespace std;

void hexListList::append(hexPanel* panel, unsigned short boardSize)
{
	if(head == nullptr){
		head = new hexList();
		cursor = head;
		cursor->append(panel, boardSize);
	}
	else{
		resetCursor();

		while(cursor->getNext() != nullptr){
			cursor = cursor->getNext();
		}

		cursor->setNext(new hexList());
		cursor = cursor->getNext();	//	newly created list
		cursor->append(panel, boardSize);
	}
}

hexList* hexListList::getList()
{
	return cursor;
}

int hexListList::getLength()
{
	int count = 0;

	resetCursor();

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

void hexListList::display()
{
	resetCursor();

	while(cursor != nullptr){
		cout << "{ ";
		cursor->display();
		cout << " } ==> ";

		cursor = cursor->getNext();
	}
	cout << endl;
}
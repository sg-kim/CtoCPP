#ifndef _HEXLISTLIST_

#define _HEXLISTLIST_

#include <iostream>

#include "hexList.h"

using std::cout;
using std::endl;

class hexListList
{
private:
	hexList* head;
	hexList* cursor;

public:
	hexListList():head(nullptr), cursor(nullptr){}
	~hexListList()
	{
		cursor = head;

		while(head != nullptr){

			cursor = cursor->getNext();

			delete head;

			head = cursor;
		}
	}
	void append(hexPanel* panel, unsigned short boardSize);
	hexList* getList();
	int getLength();
	void resetCursor();
	void display();
	void deleteList(hexList* targetList);
};

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

void hexListList::deleteList(hexList* targetList)
{
	hexList* prevList = nullptr;

	if(targetList == head){
		head = targetList->getNext();
		delete targetList;
	}
	else{
		resetCursor();

		while(cursor != nullptr){

			if(cursor == targetList){
				break;
			}
			else{
				prevList = cursor;
				cursor = cursor->getNext();
			}
		}

		if(cursor != nullptr){
			prevList->setNext(cursor->getNext());
			delete cursor;
		}
	}
}

#endif // !_HEXLISTLIST_


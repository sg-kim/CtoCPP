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
	hexList* connectedList;

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
	void removeLink(hexList* targetList);
	bool collectConnectedPath(hexPanel* targetPanel);
	void mergeList(hexList* dst, hexList* src, unsigned short boardSize);
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

void hexListList::removeLink(hexList* targetList)
{
	hexList* prevList = nullptr;

	if(targetList == head){
		head = targetList->getNext();
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
		}
	}
}

bool hexListList::collectConnectedPath(hexPanel* targetPanel)
{
	hexPanel* foundPanel;
	bool retVal = false;
	
	connectedList = nullptr;
	resetCursor();

	while(cursor != nullptr){

		foundPanel = cursor->search(targetPanel->getXpos(), targetPanel->getYpos(), targetPanel->getColor());
		if((foundPanel->getXpos() == targetPanel->getXpos()) &&
			(foundPanel->getYpos() == targetPanel->getYpos()) &&
			(foundPanel->getColor() == targetPanel->getColor())){

				retVal = true;

				if(connectedList == nullptr){
					connectedList = cursor;
					removeLink(cursor);
				}
				else{
					connectedList->setNext(cursor);
					removeLink(cursor);
				}
		}

		cursor = cursor->getNext();
	}

	return retVal;
}

void hexListList::mergeList(hexList* dst, hexList* src, unsigned short boardSize)
{
	hexPanel* srcCursor;
	hexPanel* foundPanel;

	src->resetCursor();
	srcCursor = src->getHexPanel();

	while(srcCursor != nullptr){

		foundPanel = dst->search(srcCursor->getXpos(), srcCursor->getYpos(), srcCursor->getColor());

		if(foundPanel == nullptr){	//	dst list does not have the panel under test
			dst->append(foundPanel, boardSize);
		}

		srcCursor = srcCursor->getNext();
	}
}

#endif // !_HEXLISTLIST_

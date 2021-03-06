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

	hexList* collectConnectedPath(hexPanel* targetPanel);
	hexList* removeLink(hexList* targetList);

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
	//bool collectConnectedPath(hexPanel* targetPanel);
	//void mergeList(hexList* dst, hexList* src, unsigned short boardSize);
	//hexList* getLongestPath();
	bool mergePath(hexPanel* targetPanel, unsigned short boardSize);
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

hexList* hexListList::removeLink(hexList* targetList)
{
	hexList* prevList = nullptr;

	if(targetList == head){
		head = targetList->getNext();
		prevList = head;
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

	return prevList;
}

hexList* hexListList::collectConnectedPath(hexPanel* targetPanel)
{
	hexList* connectedList;
	hexPanel* foundPanel;

	connectedList = nullptr;

	resetCursor();

	while(cursor != nullptr){

		foundPanel = cursor->search(targetPanel->getXpos(), targetPanel->getYpos(), targetPanel->getColor());
		if((foundPanel->getXpos() == targetPanel->getXpos()) &&
			(foundPanel->getYpos() == targetPanel->getYpos()) &&
			(foundPanel->getColor() == targetPanel->getColor())){

				if(connectedList == nullptr){
					connectedList = cursor;
					cursor = removeLink(cursor);
				}
				else{
					connectedList->setNext(cursor);
					cursor = removeLink(cursor);
				}
		}

		cursor = cursor->getNext();
	}

	return connectedList;
}

void mergeList(hexList* dst, hexList* src, unsigned short boardSize)
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

hexList* getLongestPath(hexList* targetList)
{
	hexList* theLongestList;
	hexList* listUnderTest;
	int theLongestLength;

	listUnderTest = targetList;
	theLongestList = targetList;
	theLongestLength = targetList->getLength();

	while(targetList != nullptr){
		
		if(targetList->getLength() > theLongestLength){
			theLongestLength = targetList->getLength();
			theLongestList = targetList;
		}

		targetList = targetList->getNext();
	}

	return theLongestList;
}

bool hexListList::mergePath(hexPanel* targetPanel, unsigned short boardSize)
{
	hexList* connectedList;
	hexList* theLongestPath;
	hexList* srcList;
	hexList* nextList;
	bool merge = false;

	resetCursor();

	//	collect connected path
	connectedList = collectConnectedPath(targetPanel);

	if(connectedList->getLength() > 1){

		//	find the longest path
		theLongestPath = getLongestPath(connectedList);

		//	merge connected path into a path list
		srcList = connectedList;

		while(srcList != nullptr){

			if(srcList == theLongestPath){
				srcList = srcList->getNext();
			}
			else{
				mergeList(theLongestPath, srcList, boardSize);
				srcList = srcList->getNext();
			}
		}

		//	remove unnessary lists in the path
		srcList = connectedList;

		while(srcList != nullptr){

			nextList = srcList->getNext();

			if(srcList != theLongestPath){
				deleteList(srcList);
				srcList = nextList;
			}
		}

		merge = true;
	}
	
	//	append the longest list to the path list
	resetCursor();

	while(cursor != nullptr){
		cursor = cursor->getNext();
	}

	cursor->setNext(connectedList);


	return merge;
}

#endif // !_HEXLISTLIST_

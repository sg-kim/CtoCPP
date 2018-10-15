#ifndef _HEXLIST_

#define _HEXLIST_

#include <iostream>

#include "hexPanel.h"

using std::cout;
using std::endl;

class hexList
{
private:
	hexPanel* head;
	hexPanel* cursor;
	hexList* next;

public:
	hexList():head(nullptr), cursor(nullptr), next(nullptr){}
	~hexList()
	{
		//hexList* preHead;
		//hexList* preCursor;

		//cursor = head;

		//while(cursor->sibling != nullptr){	//	delete siblings

		//	while(cursor->sibling != nullptr){
		//		preHead = cursor;	//	just before the last sibling
		//		cursor = cursor->sibling;	//	find the last sibling
		//	}

		//	while(cursor->child != nullptr){

		//		while(cursor->child != nullptr){
		//			preCursor = cursor;	//	just before the last child
		//			cursor = cursor->child;	//	find the last child
		//		}
		//		delete cursor;
		//		preCursor->child = nullptr;

		//		cursor = preHead->sibling;	//	head of children = a sibling
		//	}

		//	delete cursor;	//	delete the head of children = delete a sibling
		//	preHead->sibling = nullptr;

		//	cursor = head;	//	head of siblings
		//}

		//while(cursor->child != nullptr){	//	delete the children of the origin

		//	while(cursor->child != nullptr){
		//		preCursor = cursor;	//	just before the last child
		//		cursor = cursor->child;	//	find the last child
		//	}
		//	delete cursor;
		//	preCursor->child = nullptr;

		//	cursor = preHead->sibling;	//	head of children = a sibling
		//}

		//delete cursor;	//	delete the last sibling

		cursor = head;

		while(head != nullptr){
			
			cursor = cursor->getNext();

			delete head;
			
			head = cursor;
		}
	}
	void append(hexPanel* panel, unsigned short boardSize);
	int getLength();
	hexPanel* getHexPanel();
	hexList* getNext();
	void setNext(hexList* nextPtr);
	hexPanel* search(unsigned short xPos, unsigned short yPos, short color);
	void resetCursor();
	void display();
};

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

#endif // !_HEXLIST_

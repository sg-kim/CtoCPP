#ifndef _HEXLIST_

#define _HEXLIST_

#include "hexPanel.h"

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

#endif // !_HEXLIST_

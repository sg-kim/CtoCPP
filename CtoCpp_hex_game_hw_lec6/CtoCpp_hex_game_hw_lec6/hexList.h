#ifndef _HEXLIST_

#define _HEXLIST_

#include "hexPanel.h"

class hexList
{
private:
	hexPanel panel;
	hexList* sibling;
	hexList* child;
	hexList* head;
	hexList* cursor;

public:
	hexList():sibling(nullptr), child(nullptr), head(nullptr), cursor(nullptr){}
	~hexList()
	{
		hexList* preHead;
		hexList* preCursor;

		cursor = head;

		while(cursor->sibling != nullptr){	//	delete siblings

			while(cursor->sibling != nullptr){
				preHead = cursor;	//	just before the last sibling
				cursor = cursor->sibling;	//	find the last sibling
			}

			while(cursor->child != nullptr){

				while(cursor->child != nullptr){
					preCursor = cursor;	//	just before the last child
					cursor = cursor->child;	//	find the last child
				}
				delete cursor;
				preCursor->child = nullptr;

				cursor = preHead->sibling;	//	head of children = a sibling
			}

			delete cursor;	//	delete the head of children = delete a sibling
			preHead->sibling = nullptr;

			cursor = head;	//	head of siblings
		}

		while(cursor->child != nullptr){	//	delete the children of the origin

			while(cursor->child != nullptr){
				preCursor = cursor;	//	just before the last child
				cursor = cursor->child;	//	find the last child
			}
			delete cursor;
			preCursor->child = nullptr;

			cursor = preHead->sibling;	//	head of children = a sibling
		}

		delete cursor;	//	delete the last sibling
	}
	void append(hexPanel* panel);
	void getLength();
	void getXpos();
	void getYpos();
	void getColor();
	void resetCursor();
};

#endif // !_HEXLIST_

#ifndef _HEX_LIST_

#define _HEX_LIST_

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
	hexList(): head(nullptr), cursor(nullptr), next(nullptr) {}
	hexList(hexList& l)		//	shallow copy
	{
		head = l.getHead();
		cursor = l.getCursor();
		next = l.getNext();
	}
	~hexList() {}
	void copyHexList(hexList* l);	//	deep copy
	void resetCursor();
	void append(hexList* l);
	void appendPanel(int x, int y, int c);
	//void appendPanel(hexPanel& p);
	hexPanel* getHead();
	hexPanel* getCursor();
	hexList* getNext();
	void print();
};

void hexList::copyHexList(hexList* l)	//	deep copy
{
	if(l != nullptr){

		hexPanel* p;

		l->resetCursor();

		p = l->getCursor();		//	p = target panel

		head = new hexPanel(*p);
		cursor = head;

		p = p->getNext();

		while(p != nullptr){

			cursor->append(p->getXpos(), p->getYpos(), p->getColor());
			cursor = cursor->getNext();

			p = p->getNext();
		}
	}
}

void hexList::resetCursor()
{
	cursor = head;
}

void hexList::append(hexList* l)
{
	next = l;
}

void hexList::appendPanel(int x, int y, int c)
{
	resetCursor();

	if(cursor == nullptr){
		head = new hexPanel(x, y, c);
	}
	else{
		while(cursor->getNext() != nullptr){
			cursor = cursor->getNext();
		}
		cursor->append(x, y, c);
	}
}

//void hexList::appendPanel(hexPanel& p)
//{
//	resetCursor();
//
//	if(cursor == nullptr){
//		head = new hexPanel(p);
//	}
//	else{
//		while(cursor->getNext() != nullptr){
//			cursor = cursor->getNext();
//		}
//		cursor->append(p);
//	}
//}

hexPanel* hexList::getHead()	{	return head;	}
hexPanel* hexList::getCursor()	{	return cursor;	}
hexList* hexList::getNext()		{	return next;	}

void hexList::print()
{
	resetCursor();

	while(cursor != nullptr){
		cursor->print();
		cout << " -> ";
		cursor = cursor->getNext();
	}
	//cout << endl;
}

#endif // !_HEX_LIST_

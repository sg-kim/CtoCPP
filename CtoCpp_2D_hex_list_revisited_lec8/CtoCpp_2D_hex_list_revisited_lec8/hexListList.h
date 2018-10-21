#ifndef _HEX_LIST_LIST_

#define _HEX_LIST_LIST_

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
	hexListList(): head(nullptr), cursor(nullptr) {}
	hexListList(hexListList& ll)	//	shallow copy
	{
		head = ll.getHead();
		cursor = ll.getCursor();
	}
	~hexListList() {}
	void copyhexListList(hexListList* ll);	//	deep copy
	void resetCursor();
	void appendList(hexList* l);
	hexList* getHead();
	hexList* getCursor();
	void print();
};

void hexListList::copyhexListList(hexListList* ll)	//	deep copy
{
	if(ll != nullptr){

		hexList* l;

		ll->resetCursor();

		l = ll->getCursor();		//	target list

		head = new hexList();
		head->copyHexList(l);

		resetCursor();

		l = l->getNext();

		while(l != nullptr){

			cursor->append(new hexList());
			cursor = cursor->getNext();
			cursor->copyHexList(l);

			l = l->getNext();
		}
	}
}

void hexListList::resetCursor()
{
	cursor = head;
}

void hexListList::appendList(hexList* l)
{
	resetCursor();

	if(cursor == nullptr){
		head = l;
		cursor = head;
	}
	else{

		while(cursor->getNext() != nullptr){

			cursor = cursor->getNext();
		}

		cursor->append(l);
	}
}

hexList* hexListList::getHead()	{	return head;	}

hexList* hexListList::getCursor()	{	return cursor;	}

void hexListList::print()
{
	resetCursor();

	while(cursor != nullptr){
		cursor->print();
		cout << " ==> ";
		cursor = cursor->getNext();
	}
	cout << endl;
}

#endif // !_HEX_LIST_LIST_

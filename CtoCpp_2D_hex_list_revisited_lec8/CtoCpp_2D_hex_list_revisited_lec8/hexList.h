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
	hexList(hexList& l)
	{
		head = l.getHead();
		cursor = l.getCursor();
		next = l.getNext();
	}
	~hexList() {}
	void resetCursor();
	void append(hexList& l);
	void appendPanel(int x, int y, int c);
	void appendPanel(hexPanel& p);
	hexPanel* getHead();
	hexPanel* getCursor();
	hexList* getNext();
	void print();
};

void hexList::resetCursor()
{
	cursor = head;
}

void hexList::append(hexList& l)
{
	next = l.getNext();
}

void hexList::appendPanel(int x, int y, int c)
{
	resetCursor();

	if(cursor == nullptr){
		cursor = new hexPanel(x, y, c);
	}
	else{
		cursor->append(x, y, c);
	}
}

void hexList::appendPanel(hexPanel& p)
{
	cursor->append(p);
}

hexPanel* hexList::getHead()	{	return head;	}
hexPanel* hexList::getCursor()	{	return cursor;	}
hexList* hexList::getNext()		{	return next;	}

void hexList::print()
{
	resetCursor();

	while(cursor != nullptr){
		cursor->print();
		cout << " -> ";
	}
	cout << endl;
}

#endif // !_HEX_LIST_

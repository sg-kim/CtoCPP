#ifndef _HEXLISTLIST_

#define _HEXLISTLIST_

#include "hexList.h"

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
};

#endif // !_HEXLISTLIST_


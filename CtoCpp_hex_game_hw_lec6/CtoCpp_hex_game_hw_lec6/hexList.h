#ifndef _HEXLIST_

#define _HEXLIST_

#include "hexPanel.h"

class hexList
{
private:
	hexPanel panel;
	hexList* next;
	hexList* child;
	hexList* head;
	hexList* cursor;

public:
	hexList():next(nullptr), child(nullptr), head(nullptr), cursor(nullptr){}
	~hexList()
	{
		cursor = head;

		while(cursor->next != nullptr){
			cursor = cursor->next;
		}

		while(cursor->child != nullptr){
			cursor = cursor->child;
		}

	}
	void append(hexPanel* panel);
	void getLength();
	void getXpos();
	void getYpos();
	void getColor();
	void resetCursor();
};

#endif // !_HEXLIST_

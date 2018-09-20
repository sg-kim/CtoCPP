
#include <iostream>

#include "list.h"

using namespace std;

void list::append(int s, int d, int dist, bool v)
{
	if(head == nullptr){
		head = cursor = new list_element(s, d, dist, v, nullptr);
	}
	else{
		cursor = head;

		while(cursor->next != nullptr){
			cursor = cursor->next;
		}

		cursor->next = new list_element(s, d, dist, v, nullptr);
	}
}

void list::prepend(int s, int d, int dist, bool v)
{
	if(head == nullptr){
		head = cursor = new list_element(s, d, dist, v, nullptr);
	}
	else{
		head = new list_element(s, d, dist, v, head);
	}
}

void list::resetPtr()
{
	cursor = head;
}

void list::next()
{
	cursor = cursor->next;
}

void list::last()
{
	cursor = head;

	while(cursor->next != nullptr){
		cursor = cursor->next;
	}
}

int list::getSrc()
{
	return cursor->src;
}

int list::getDst()
{
	return cursor->dst;
}

int list::getWgt()
{
	return cursor->wgt;
}

bool list::visited()
{
	return cursor->visit;
}

void list::setSrc(int src)
{
	if(head == nullptr){
		head = cursor = new list_element(src, -1, -1, false, nullptr);
	}
	else{
		cursor->src = src;
	}
}

void list::setDst(int dst)
{
	if(head == nullptr){
		head = cursor = new list_element(-1, dst, -1, false, nullptr);
	}
	else{
		cursor->dst = dst;
	}
}

void list::setWgt(int wgt)
{
	if(head == nullptr){
		head = cursor = new list_element(-1, -1, wgt, false, nullptr);
	}
	else{
		cursor->wgt = wgt;
	}
}

void list::setVisit()
{
	cursor->visit = true;
}

void list::resetVisit()
{
	cursor->visit = false;
}

void list::print()
{
	list_element* curPos;
	curPos = cursor;

	cursor = head;

	while(cursor != nullptr){

		if(cursor->next == nullptr){
			cout << "(" << cursor->src << ", " << cursor->dst << ", " << cursor->wgt << ", " << cursor->visit << ")" << endl;
		}
		else{
			cout << "(" << cursor->src << ", " << cursor->dst << ", " << cursor->wgt << ", " << cursor->visit << ")" << " --> ";
		}

		cursor = cursor->next;
	}

	cursor = curPos;
}

int list::length()
{
	int len = 0;

	cursor = head;

	while(cursor != nullptr){

		cursor = cursor->next;

		len++;
	}

	return len;
}

bool list::end()
{
	bool end = false;

	if(cursor == nullptr){
		end = true;
	}
	
	return end;
}
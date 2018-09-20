
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

void list::setVisit()
{
	cursor->visit = true;
}

void list::print()
{
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
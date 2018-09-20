// CtoCPP_List_ex_lec_3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class list_element{
public:
	list_element(int n = 0, list_element* nextPtr = nullptr):
		d(n), next(nextPtr) {}
	int d;
	list_element* next;
};

class list{
public:
	list(): head(nullptr), cursor(nullptr) {}
	~list()
	{
		if(head != nullptr && head->next == nullptr){	//	one element
			delete head;
		}
		else{	//	more than an element
			while(head->next != nullptr){
				cursor = head->next;
				delete head;
				head = cursor;
			}
			delete head;	//	delete the last one
		}
	}
	void prepend(int d);
	void print();
	int getCurData();
private:
	list_element* head;
	list_element* cursor;
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}


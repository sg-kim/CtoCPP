// CtoCpp_lvalue_rvalue_lec7.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void efficientMove(vector<T>& a, vector<T>&& b)
{
	a = b;
	b = nullptr;
}

int foo()
{
	return 10;
}

int _tmain(int argc, _TCHAR* argv[])
{
	
	int a = foo();
	int& b = a;
	int&& c = foo();

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	vector<int> va(5);
	vector<int> vb(5);

	for(int i = 0; i < 5; i++){
		va[i] = i;
		vb[i] = i + 5;
	}

	for(int i = 0; i < 5; i++){
		cout << va[i] << endl;
	}

	for(int i = 0; i < 5; i++){
		cout << vb[i] << endl;
	}

	efficientMove(va, vb);
	
	for(int i = 0; i < 5; i++){
		cout << va[i] << endl;
	}

	for(int i = 0; i < 5; i++){
		cout << vb[i] << endl;
	}


	return 0;
}


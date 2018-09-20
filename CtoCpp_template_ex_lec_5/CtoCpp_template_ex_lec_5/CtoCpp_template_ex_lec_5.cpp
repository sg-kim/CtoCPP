// CtoCpp_template_ex_lec_5.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

template<typename T>	//	keyword to define template function or class
void t_swap(T&a, T&b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a = 5;
	int b = 10;

	cout << a << "\t" << b << endl;

	t_swap(a, b);

	cout << a << "\t" << b << endl;

	double c = 3.5;
	double d = 6.3;

	cout << c << "\t" << d << endl;

	t_swap(c, d);

	cout << c << "\t" << d << endl;

	return 0;
}


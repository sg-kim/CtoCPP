// CtoCpp_lvalue_rvalue_lec7.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#include <iostream>

void efficientSwap(int& a, int&& b)
{

}


int _tmain(int argc, _TCHAR* argv[])
{
	int a = 0;
	int& b = a;
	int&& c = 0;

	//b = 1;
	a = a + 1;
	b = b + 1;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	
	c = b;
	
	std::cout << c << std::endl;

	return 0;
}

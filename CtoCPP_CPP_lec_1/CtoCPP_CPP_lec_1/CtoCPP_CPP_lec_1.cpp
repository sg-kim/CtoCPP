// CtoCPP_CPP_lec_1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

const int N = 10;

void sum(int *p, int n, int d[])
{
	int i = 0;
	*p = 0;

	for(i = 0; i < n; ++i){
		*p = *p + d[i];
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int i = 0;
	int accum = 0;
	int data[N];

	for(i = 0; i < N; ++i){
		data[i] = i;
	}

	sum(&accum, N, data);

	std::cout << "sum is " << accum << std::endl;

	return 0;
}


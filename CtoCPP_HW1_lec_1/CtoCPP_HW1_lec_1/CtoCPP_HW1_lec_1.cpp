// CtoCPP_HW1_lec_1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

template <class summable>

void sum(summable& s, int size, summable data[])
{
	for(int i = 0; i < size; ++i){
		s += data[i];
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int i = 0;
	int accum = 0;
	const int N = 40;
	int data[N];

	for(i = 0; i < N; ++i){
		data[i] = i;
	}

	sum(accum, N, data);

	cout << "sum is " << accum << endl;

	return 0;
}


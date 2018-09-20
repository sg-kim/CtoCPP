// CtoCPP_generic_lec_2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

template <class summable>
void sum(const summable data[], int size, summable& result)
{
	for(int i = 0; i < size; i++){
		result += data[i];
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = {1, 2, 3};
	double b[] = {2.1, 2.2, 2.3};
	int sum_int = 0;
	double sum_double = 0;

	sum(a, 3, sum_int);
	cout << sum_int << endl;

	sum(b, 3, sum_double);
	cout << sum_double << endl;

	return 0;
}


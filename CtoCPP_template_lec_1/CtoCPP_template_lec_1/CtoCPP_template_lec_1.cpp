// CtoCPP_template_lec_1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

/*	
//	Code with C
#define N 10

void sum(int m, int* sum, int* a)
{
	int i;
	*sum = 0;
	
	for(i = 0; i <= m; i++){
		*sum = *sum + *(a + i);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int result;
	int a[N + 1];
	int i;

	result = 0;
	i = 0;

	for(i = 0; i <= N; i++){
		a[i] = i;
	}

	sum(N, &result, a);

	printf("result = %d\n", result);

	return 0;
}
*/

#include <iostream>

using namespace std;

const int N = 10;

template <class summable>	//	summable is the generic type

void sum(const summable data[], int size, summable& s)
{
	for(int i = 0; i <= size; i++){
		s += data[i];
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int i = 0;
	int a[N + 1];
	int result = 0;

	for(i = 0; i <= N; i++){
		a[i] = i;
	}

	sum(a, N, result);

	cout << "result= " << result << endl;

	return 0;
}

// CtoCPP_swap_lec_1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

inline void swap(int& i, int& j)	//	"&" operator: call by reference, reference to int not value
{
	// call by value in C makes inefficiency when localizing 'call by value' parameters by copying them.
	int temp = i;
	i = j;
	j = temp;
}

inline void swap(double& i, double& j)		//	function overloading according to the input arguments - signature matching
{
	double temp = i;
	i = j;
	j = temp;
}

int _tmain(int argc, _TCHAR* argv[])
{

	int m = 5, n = 10;
	double x = 5.3, y = 10.6;

	cout << "inputs: " << m << ", " << n << endl;

	swap(m, n);
	cout << "outputs: " << m << ", " << n << endl;

	cout << "double inputs: " << x << ", " << y << endl;

	swap(x, y);
	cout << "double outputs: " << x << ", " << y << endl;

	return 0;
}


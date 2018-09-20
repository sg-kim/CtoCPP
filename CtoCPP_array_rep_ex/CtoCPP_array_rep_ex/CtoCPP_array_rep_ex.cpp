// CtoCPP_array_rep_ex.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int data[3] = {1, 2, 3};

	cout << hex << data << endl;
	cout << hex << &data[0] << endl;
	
	return 0;
}


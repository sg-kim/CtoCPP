// CtoCPP_ptr_2D_array_ex.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

const int size = 5;

int _tmain(int argc, _TCHAR* argv[])
{

	int **table;

	table = (int**)malloc(sizeof(int*)*size);

	for(int i = 0; i < size; i++){
		table[i] = (int*)malloc(sizeof(int)*size);
	}

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){

			table[i][j] = i*size + j;
		}
	}

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){

			cout << table[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}


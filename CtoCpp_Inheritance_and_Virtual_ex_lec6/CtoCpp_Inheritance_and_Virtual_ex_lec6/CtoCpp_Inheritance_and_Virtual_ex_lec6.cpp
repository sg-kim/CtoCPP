// CtoCpp_Inheritance_and_Virtual_ex_lec6.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#include <iostream>

#include "point.h"
#include "point3D.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	point p_0(3.0, 4.0);
	point3D p3D_0(2.0, 2.0, 2.0);

	cout << p_0.length() << endl;

	cout << p3D_0.length() << endl;

	return 0;
}

// CtoCpp_inheritance_ex_2_lec6.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include "student.h"
#include "grad_student.h"

int _tmain(int argc, _TCHAR* argv[])
{
	student* s;

	s = new student("Jim Rogers", 201623492, 1, 2, 3.25);

	s->print();

	grad_student* gs;

	gs = new grad_student("Electrical Eng.", 31542 , "Stochastic computing architecture for high performance arithmatic", "Roding Green", 201152912, 1, 1, 3.64);

	gs->print();

	delete s;

	delete gs;

	return 0;
}


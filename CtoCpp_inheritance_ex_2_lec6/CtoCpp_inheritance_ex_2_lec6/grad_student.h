#ifndef _GRAD_STUDENT_

#define _GRAD_STUDENT_

#include "student.h"

class grad_student:public student
{
protected:
	char* dept;
	unsigned int deptCode;
	char* thesis;

public:
	grad_student(char* gs_dept, unsigned int gs_deptCode, char* gs_thesis, char* std_name, unsigned int std_id, unsigned int std_sex, unsigned int std_year, double std_gpa):dept(gs_dept), deptCode(gs_deptCode), thesis(gs_thesis), student(std_name, std_id, std_sex, std_year, std_gpa){}
	~grad_student(){}
	void print()
	{
		std::cout << dept << ", " << deptCode << ", " << thesis << std::endl;
		student::print();
	}

};

#endif // !_GRAD_STUDENT_

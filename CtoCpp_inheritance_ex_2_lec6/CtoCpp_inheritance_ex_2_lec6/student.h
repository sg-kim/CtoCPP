#ifndef _STUDENT_

#define _STUDENT_

#include <iostream>

class student
{
protected:
	char* name;
	unsigned int id;
	unsigned int sex;
	unsigned int year;
	double gpa;

public:
	student(char* std_name, unsigned int std_id, unsigned int std_sex, unsigned int std_year, double std_gpa): name(std_name), id(std_id), sex(std_sex), year(std_year), gpa(std_gpa){}
	~student(){}
	virtual void print()
	{
		std::cout << name << ", " << id << ", " << sex << ", " << year << ", " << gpa << std::endl;
	}

};

#endif // !_STUDENT_

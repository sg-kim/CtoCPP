// CtoCPP_op_overloading_ex_lec_4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

class point
{
private:
	double x, y;

public:
	explicit point(double u = 0.0, double v = 0.0): x(u), y(v) {}	//	only explicit conversion is enable
	point operator+(point p);
	double getX();
	double getY();
};

point point::operator+(point p)
{
	return point(x + p.x, y + p.y);
}

double point::getX()
{
	return x;
}

double point::getY()
{
	return y;
}

int _tmain(int argc, _TCHAR* argv[])
{

	point* a;
	point* b;
	point* c;

	//point a;
	//point b;
	//point c;

	a = new point(0.5, 1);
	b = new point(2.4, 2.2);
	c = new point;

	//a = point(0.5, 1);
	//b = point(2.4, 2.2);
	
	*c = *a + *b;

	//cout << a.getX() << ", " << a.getY() << endl;
	//cout << b.getX() << ", " << b.getY() << endl;
	//cout << c.getX() << ", " << c.getY() << endl;

	cout << a->getX() << ", " << a->getY() << endl;
	cout << b->getX() << ", " << b->getY() << endl;
	cout << c->getX() << ", " << c->getY() << endl;

	delete a;
	delete b;
	delete c;

	return 0;
}

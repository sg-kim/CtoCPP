#ifndef _POINT_

#define _POINT_

class point
{
private:
	double x;
	double y;
public:
	point(double xp = 0.0, double yp = 0.0):x(xp), y(yp){}
	~point(){}
	virtual double length()
	{
		return (sqrt(x*x + y*y));
	}
};

#endif // !_POINT_

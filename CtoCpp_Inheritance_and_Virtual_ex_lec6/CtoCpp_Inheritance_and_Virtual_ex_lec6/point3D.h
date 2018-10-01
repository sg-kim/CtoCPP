#ifndef _POINT3D_

#define _POINT3D_

#include "point.h"

class point3D: public point
//class point3D: private point
{
private:
	double z;
public:
	point3D(double xp = 0.0, double yp = 0.0, double zp = 0.0):z(zp), point(xp, yp){}
	~point3D(){}
	double length()
	{
		return (sqrt((point::length())*(point::length()) + z*z));
	}
};

#endif // !_POINT3D_

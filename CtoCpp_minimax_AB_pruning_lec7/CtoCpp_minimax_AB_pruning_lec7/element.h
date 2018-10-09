#ifndef _ELEMENT_

#define _ELEMENT_

class element
{
private:
	int value;
	element* nextElement;

public:
	element(int score, element* nextPtr):value(score), nextElement(nextPtr){}
	~element(){}
	int getValue()
	{
		return value;
	}
	void setValue(int score)
	{
		value = score;
	}
	element* next()
	{
		return nextElement;
	}
};

#endif // !_ELEMENT_

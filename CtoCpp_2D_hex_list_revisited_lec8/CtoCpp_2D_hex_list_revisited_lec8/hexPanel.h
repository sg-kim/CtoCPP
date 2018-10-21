#ifndef _HEX_PANEL_

#define _HEX_PANEL_

#include <iostream>

using std::cout;
using std::endl;

class hexPanel
{
private:
	int xPos;
	int yPos;
	int color;
	hexPanel* next;

public:
	hexPanel(int x, int y, int c): xPos(x), yPos(y), color(c), next(nullptr) {}
	hexPanel(hexPanel& p)
	{
		xPos = p.getXpos();
		yPos = p.getYpos();
		color = p.getColor();
		next = nullptr;
	}
	~hexPanel() {}
	void append(int x, int y, int c);
	//void append(hexPanel& p);
	int getXpos();
	int getYpos();
	int getColor();
	hexPanel* getNext();
	void print();
};

void hexPanel::append(int x, int y, int c)
{
	next = new hexPanel(x, y, c);
}

//void hexPanel::append(hexPanel& p)
//{
//	next = &p;
//}

int hexPanel::getXpos() {	return xPos;	}
int hexPanel::getYpos() {	return yPos;	}
int hexPanel::getColor() {	return color;	}
hexPanel* hexPanel::getNext() {		return next;	}

void hexPanel::print()
{
	cout << "(" << xPos << ", " << yPos << ", " << color << ")";
}

#endif // !_HEX_PANEL_

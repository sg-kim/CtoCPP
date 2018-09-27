#ifndef _HEXPANEL_

#define _HEXPANEL_

class hexPanel
{
private:
	unsigned short xPos;
	unsigned short yPos;
	short data;
	
public:
	hexPanel(unsigned short x = 0, unsigned short y = 0, short contents = -1):xPos(x), yPos(y), data(contents){}
	~hexPanel(){}
	void setPanel(unsigned short x, unsigned short y, short contents)
	{
		xPos = x;
		yPos = y;
		data = contents;
	}
	hexPanel* getPanel()
	{
		return this;
	}
	unsigned short getXpos()
	{
		return xPos;
	}
	unsigned short getYpos()
	{
		return yPos;
	}
	unsigned short getData()
	{
		return data;
	}
};

#endif // !_HEXPANEL_

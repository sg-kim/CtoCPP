#ifndef _HEXPANEL_

#define _HEXPANEL_

enum class edgeStatus : unsigned short {NOTEDGE, TOP, TOPRIGHT, TOPLEFT, BOTTOM, BOTTOMRIGHT, BOTTOMLEFT, LEFT, RIGHT};

class hexPanel
{
private:
	unsigned short xPos;
	unsigned short yPos;
	short color;	//	negative value = unoccupied
	bool edgeTop;
	bool edgeBottom;
	bool edgeLeft;
	bool edgeRight;
	hexPanel* next;

public:
	hexPanel(unsigned short x = 0, unsigned short y = 0, short c = -1, hexPanel* nextPtr = nullptr, unsigned short boardSize = 1): xPos(x), yPos(y), color(c), next(nextPtr)
	{
		if(xPos == 0){
			edgeLeft = true;
		}
		else{
			edgeLeft = false;
		}

		if(xPos == (boardSize - 1)){
			edgeRight = true;
		}
		else{
			edgeRight = false;
		}

		if(yPos == 0){
			edgeTop = true;
		}
		else{
			edgeTop = false;
		}

		if(yPos == (boardSize - 1)){
			edgeBottom = true;
		}
		else{
			edgeBottom = false;
		}
	}
	~hexPanel(){}
	void setXPos(unsigned short xpos, unsigned short boardSize);
	void setYPos(unsigned short ypos, unsigned short boardSize);
	void setColor(unsigned short c);
	void setNext(hexPanel* nextPtr);
	unsigned short getXpos();
	unsigned short getYpos();
	short getColor();
	hexPanel* getNext();
	void examineEdge(unsigned short boardSize);
	edgeStatus getEdgeStatus();
};


#endif // !_HEXPANEL_

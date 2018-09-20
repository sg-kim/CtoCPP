#ifndef _HEXPANEL_

#define _HEXPANEL_

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

public:
	hexPanel(unsigned short x = 0, unsigned short y = 0, short c = -1, unsigned short boardSize = 1): xPos(x), yPos(y), color(c)
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
	unsigned short getXpos();
	unsigned short getYpos();
	short getColor();
	void examineEdge(unsigned short boardSize);
};


#endif // !_HEXPANEL_

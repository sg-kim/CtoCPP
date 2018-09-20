#ifndef _HEXPANEL_

#define _HEXPANEL_

class hexPanel
{
private:
	unsigned short xPos;
	unsigned short yPos;
	unsigned short color;
	bool edgeTop;
	bool edgeBottom;
	bool edgeLeft;
	bool edgeRight;
	hexPanel* next;
	hexPanel* child;

public:
	hexPanel(unsigned short x = 0, unsigned short y = 0, unsigned short c = 0, hexPanel* nxt = nullptr,
		hexPanel* ch = nullptr, unsigned short boardSize = 1): xPos(x), yPos(y), color(c), next(nxt), child(ch)
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
	void setNext(hexPanel* nextItem);
	void setChild(hexPanel* childItem);
	unsigned short getXpos();
	unsigned short getYpos();
	unsigned short getColor();
	hexPanel* getNext();
	hexPanel* getChild();
	void hexPanel::examineEdge(unsigned short boadrSize);
};


#endif // !_HEXPANEL_

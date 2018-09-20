#ifndef _LIST_

#define _LIST_

class list_element
{
public:
	int src;
	int dst;
	int wgt;
	bool visit;
	list_element* next;
	list_element(int s, int d, int dist, bool v, list_element* nextItem): src(s), dst(d), wgt(dist), visit(v), next(nextItem) {}
};

class list
{
private:
	list_element* head;
	list_element* cursor;
public:
	list(): head(nullptr), cursor(nullptr) {}
	~list()
	{
		//cursor = head->next;

		while(head != nullptr){

			cursor = head->next;

			delete head;

			head = cursor;
		}
	}
	void append(int s, int d, int dist, bool v);
	void prepend(int s, int d, int dist, bool v);
	void resetPtr();	//	rewind the cursor to the head
	void next();	//	advance cursor by an item
	void last();	//	set cursor to the last item
	int getSrc();
	int getDst();
	int getWgt();
	bool visited();
	void setSrc(int src);
	void setDst(int dst);
	void setWgt(int wgt);
	void setVisit();
	void resetVisit();
	int length();
	bool end();
	void print();
};

#endif

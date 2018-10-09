#ifndef _NODE_

#define _NODE_

#include "element.h"

class node
{
private:
	element* content;
	node* parents;
	node* children;
	node* nextNode;	//	children siblings

public:
	node():content(nullptr), parents(nullptr), children(nullptr), nextNode(nullptr){}
	~node()
	{
		node* head = getChildren();
		node* cursor;

		//	delete content
		if(content != nullptr){
			delete content;
		}

		//	delete children
		while(head != nullptr){
			cursor = head->getNext();
			delete head;
			head = cursor;
		}
	}
	int getContent()
	{
		int retVal;

		if(content == nullptr){
			retVal = -65535;
		}
		else{
			retVal = content->getValue();
		}

		return retVal;
	}
	void setContent(int value)
	{
		if(content == nullptr){
			content = new element(value, nullptr);
		}
		else{
			content->setValue(value);
		}
	}
	node* getParents()
	{
		return parents;
	}
	void setParents(node* parentsPtr)
	{
		parents = parentsPtr;
	}
	node* getChildren()
	{
		return children;
	}
	void setChildren(node* childrenPtr)
	{
		children = childrenPtr;
	}
	node* getNext()
	{
		return nextNode;
	}
	node* setNext(node* nextPtr)
	{
		nextNode = nextPtr;

		return nextNode;
	}
	unsigned int getNumChildren()
	{
		unsigned int numChildren = 0;
		node* cursor = nullptr;

		if(children == nullptr){
			numChildren = 0;
		}
		else{
			cursor = getChildren();
			while(cursor != nullptr){
				cursor = cursor->getNext();
				numChildren++;
			}
		}

		return numChildren;
	}

};

#endif // !_NODE_

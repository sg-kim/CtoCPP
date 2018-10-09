#ifndef _TREE_

#define _TREE_

#include <iostream>

#include "element.h"
#include "node.h"

using namespace std;

class tree
{
private:
	node* root;
	node* cursor;

public:
	tree():root(nullptr), cursor(nullptr) {}
	~tree()
	{
		if(root != nullptr){
			delete root;
		}
	}

	node* addChild(node* parents, node* child)
	{
		node* lastChild = parents->getChildren();

		if(lastChild == nullptr){
			parents->setChildren(child);
		}
		else{
			while(lastChild->getNext() != nullptr){
				lastChild = lastChild->getNext();
			}
			lastChild->setChildren(child);
		}

		return parents;
	}

	node* graftNode(unsigned int numChildren, node* elements)
	{
		node* retVal = nullptr;
		node* parents = nullptr;
		
		if(elements->getNext() == nullptr){
			retVal = elements;
		}
		else{
			while(elements != nullptr){

				if(parents == nullptr){
					parents = new node();
					for(int i = 0; i < numChildren; i++){
						addChild(parents, elements);
						elements = elements->getNext();
						if(elements == nullptr){
							break;
						}
					}	//	for
				}
				else{
					cursor = parents->setNext(new node());
					for(int i = 0; i < numChildren; i++){
						addChild(cursor, elements);
						elements = elements->getNext();
						if(elements == nullptr){
							break;
						}
					}	//	for
				}
			}	//	while

			graftNode(numChildren, parents);
		}

		return retVal;
	}

	void resetCursor()
	{
		cursor = root;
	}

	node* getCursor()
	{
		return cursor;
	}

	void displayTree(node* tree)
	{
		node* nextNode;
		
		if(tree->getChildren() == nullptr){
			nextNode = tree;
			while(nextNode != nullptr){
				cout << nextNode->getContent() << endl;
				nextNode = nextNode->getNext();
			}
		}
		else{
			nextNode = tree->getChildren();
			displayTree(nextNode);
			cout << tree->getContent() << endl;
		}
	}

};

#endif // !_TREE_

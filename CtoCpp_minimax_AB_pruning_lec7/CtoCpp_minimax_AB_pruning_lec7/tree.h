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
	//	basic tree structure
	//
	//		|		parents 
	//		¡Û		node
	//	   £¯		children
	//	 ¡Û ¡ª ¡Û	children -> next -> ...
	//
	node* addChild(node* parents, node* child)
	{
		node* lastChild = parents->getChildren();

		if(lastChild == nullptr){
			lastChild = parents->setChildren(new node());	//	set parents' children field
			lastChild->setContent(child->getContent());		//	set child's content field
			lastChild->setChildren(child->getChildren());	//	set child's children field
			lastChild->setParents(parents);		//	set child's parents field
		}
		else{
			while(lastChild->getNext() != nullptr){
				lastChild = lastChild->getNext();
			}
			lastChild = lastChild->setNext(new node());		//	set	sibling field
			lastChild->setContent(child->getContent());		//	set child's content field
			lastChild->setChildren(child->getChildren());	//	set child's children field
			lastChild->setParents(parents);		//	set child's parents field
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
					cursor = parents;
					for(int i = 0; i < numChildren; i++){
						addChild(cursor, elements);
						//cout << i << ": " << elements->getContent() << endl;
						elements = elements->getNext();
						if(elements == nullptr){
							break;
						}
					}	//	for
				}
				else{
					cursor = cursor->setNext(new node());
					for(int i = 0; i < numChildren; i++){
						addChild(cursor, elements);
						//cout << i << i << ": " << elements->getContent() << endl;
						elements = elements->getNext();
						if(elements == nullptr){
							break;
						}
					}	//	for
				}
			}	//	while

			//node* nodePtr;
			//nodePtr = parents;

			//while(nodePtr != nullptr){
			//	cout << nodePtr->getContent() << " --> ";
			//	nodePtr = nodePtr->getNext();
			//}
			//cout << endl;

			retVal = graftNode(numChildren, parents);
		}

		root = retVal;

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

		if(tree->getChildren() == nullptr){		//	leaves
			nextNode = tree;
			cout << nextNode->getContent() << endl;
		}
		else{
			nextNode = tree->getChildren();		//	the eldest child
			while(nextNode != nullptr){
				displayTree(nextNode);
				nextNode = nextNode->getNext();		//	siblings
			}
			cout << tree->getContent() << endl;
		}
	}

};

#endif // !_TREE_

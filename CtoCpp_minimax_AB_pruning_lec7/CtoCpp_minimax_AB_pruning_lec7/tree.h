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
		deleteTree(root);
	}
	//	basic tree sub-structure
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

	node* graftNode(unsigned int numChildren, node* elements, bool initMax)
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
					if(initMax == true){
						cursor->setContent(maxNode(cursor->getChildren())->getContent());
					}
					else{
						cursor->setContent(minNode(cursor->getChildren())->getContent());
					}
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
					if(initMax == true){
						cursor->setContent(maxNode(cursor->getChildren())->getContent());
					}
					else{
						cursor->setContent(minNode(cursor->getChildren())->getContent());
					}
				}
			}	//	while

			//node* nodePtr;
			//nodePtr = parents;

			//while(nodePtr != nullptr){
			//	cout << nodePtr->getContent() << " --> ";
			//	nodePtr = nodePtr->getNext();
			//}
			//cout << endl;

			retVal = graftNode(numChildren, parents, (initMax^true));
		}

		root = retVal;

		return retVal;
	}

	void deleteTree(node* tree)
	{
		node* branch = tree;
		node* nextNode;

		if(branch->getChildren() != nullptr){
			branch = branch->getChildren();
			while(branch != nullptr){
				nextNode = branch->getNext();	//	siblings
				deleteTree(branch);
				branch = nextNode;
			}
		}

		delete tree;
	}

	node* minNode(node* elements)
	{
		node* nodeUnderTest = elements;
		node* minValueNode = nodeUnderTest;
		int minValue = minValueNode->getContent();

		while(nodeUnderTest != nullptr){

			if(nodeUnderTest->getContent() < minValue){
				minValue = nodeUnderTest->getContent();
				minValueNode = nodeUnderTest;
			}
			nodeUnderTest = nodeUnderTest->getNext();
		}

		return minValueNode;
	}

	node* maxNode(node* elements)
	{
		node* nodeUnderTest = elements;
		node* maxValueNode = nodeUnderTest;
		int maxValue = nodeUnderTest->getContent();

		while(nodeUnderTest != nullptr){

			if(nodeUnderTest->getContent() > maxValue){
				maxValueNode = nodeUnderTest;
				maxValue = maxValueNode->getContent();
			}
			nodeUnderTest = nodeUnderTest->getNext();
		}

		return maxValueNode;
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

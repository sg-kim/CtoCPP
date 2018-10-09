// CtoCpp_minimax_AB_pruning_lec7.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>

#include "element.h"
#include "node.h"
#include "tree.h"

int _tmain(int argc, _TCHAR* argv[])
{
	node* elements;
	node* cursor;

	tree* miniMaxTree;

	elements = new node();
	elements->setContent(-1);
	
	cursor = elements->setNext(new node());
	cursor->setContent(3);

	cursor = cursor->setNext(new node());
	cursor->setContent(5);

	cursor = cursor->setNext(new node());
	cursor->setContent(1);

	cursor = cursor->setNext(new node());
	cursor->setContent(-6);

	cursor = cursor->setNext(new node());
	cursor->setContent(-4);

	cursor = cursor->setNext(new node());
	cursor->setContent(0);

	cursor = cursor->setNext(new node());
	cursor->setContent(9);

	cursor = elements;
	while(cursor != nullptr){
		cout << cursor->getContent() << " -> ";
		cursor = cursor->getNext();
	}
	cout << endl;

	miniMaxTree = new tree();

	cursor = miniMaxTree->graftNode(2, elements);

	cout << cursor->getContent() << endl;
	cout << cursor->getNumChildren() << endl;

	cursor = cursor->getChildren();

	cout << cursor->getContent() << endl;
	cout << cursor->getNumChildren() << endl;

	cursor = cursor->getNext();

	cout << cursor->getContent() << endl;
	cout << cursor->getNumChildren() << endl;

	miniMaxTree->resetCursor();
	miniMaxTree->displayTree(miniMaxTree->getCursor());

	delete elements;
	//delete miniMaxTree;

	return 0;
}


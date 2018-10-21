// CtoCpp_exp_eval_tree_rewrite_lec7.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>

using std::cout;
using std::endl;

int valTab[127];

class node		//	abstract base class
{
private:
	int use;
public:
	node(): use(0) {}
	virtual ~node() {}
	int incUse()
	{
		use++;
		return use;
	}
	int decUse()
	{
		use--;
		return use;
	}
	int getUse()
	{
		return use;
	}
	virtual int eval() = 0;		//	pure virtual function
};

class tree
{
private:
	node* p;		//	polymorphic pointer. p can point any class, which is based on the 'node' base class.
public:
	tree(int n);
	tree(char c);
	tree(char op, tree opnd);
	tree(char op, tree opnd1, tree opnd2);
	tree(tree& t)	//	copy constructor
	{
		p = t.p;
		p->incUse();
	}
	~tree()
	{
		if(p->getUse() == 0){
			delete p;
		}
	}
	int eval()
	{
		return (p->eval());
	}
	void operator=(tree t)
	{
		p = t.p;
		p->incUse();
	}
};

class intNode: public node		//	polymorphism - integer node
{
private:
	int nodeVal;
public:
	intNode(int val): nodeVal(val) {}
	~intNode() {}
	int eval()
	{
		return nodeVal;
	}
};

class idNode: public node		//	polymorphism - id in the table
{
private:
	char name;
public:
	idNode(char c): name(c)	{}
	~idNode() {}
	int eval()
	{
		return (valTab[name]);
	}
};

class unaryNode:public node		//	polymorphism - node with unary operator
{
private:
	char nodeOp;
	tree nodeOpnd;
public:
	unaryNode(char op, tree opnd): nodeOp(op), nodeOpnd(opnd) {}
	~unaryNode() {}
	int eval()
	{
		int retVal;

		switch(nodeOp){
		case '-': retVal = -nodeOpnd.eval();
			break;
		case '+': retVal = nodeOpnd.eval();
			break;
		default: retVal = nodeOpnd.eval();
		}

		return retVal;
	}
};

class binaryNode: public node	//	polymorphism - node with binary operator
{
private:
	char nodeOp;
	tree leftOpnd;
	tree rightOpnd;
public:
	binaryNode(char op, tree opnd1, tree opnd2): nodeOp(op), leftOpnd(opnd1), rightOpnd(opnd2) {}
	~binaryNode() {}
	int eval()
	{
		int retVal;

		switch(nodeOp){
		case '-': retVal = leftOpnd.eval() - rightOpnd.eval();
			break;
		case '+': retVal = leftOpnd.eval() + rightOpnd.eval();
			break;
		case '*': retVal = leftOpnd.eval() * rightOpnd.eval();
			break;
		default: retVal = 0;
		}

		return retVal;
	}
};

tree::tree(int n)
{
	p = new intNode(n);
}

tree::tree(char c)
{
	p = new idNode(c);
}

tree::tree(char op, tree opnd)
{
	p = new unaryNode(op, opnd);
}

tree::tree(char op, tree opnd1, tree opnd2)
{
	p = new binaryNode(op, opnd1, opnd2);
}

int _tmain(int argc, _TCHAR* argv[])
{
	valTab['A'] = 3;
	valTab['B'] = 4;
	tree t1 = tree('*', tree('-', 5), tree('+', 'A', 4));
	tree t2 = tree('+', tree('-', 'A', 1), tree('+', t1, 'B'));
	cout << "t1:" << t1.eval() << " t2:" << t2.eval() << endl;

	return 0;
}

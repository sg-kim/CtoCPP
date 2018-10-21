// CtoCpp_lvalue_rvalue_lec7.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <assert.h>

#include <iostream>
#include <vector>

using std::cout;
using std::endl;

class arrData
{
private:
	int size;
	int* data;
public:
	arrData(): size(0), data(nullptr) {}
	arrData(int s)
	{
		size = s;
		data = new int[size];
		for(int i = 0; i < size; i++){
			data[i] = i;
		}
	}
	arrData(arrData& src)	//	copy constructor
	{
		size = src.getSize();
		data = new int[size];
		for(int i = 0; i < size; i++){
			data[i] = src.getData(i);
		}
	};
	arrData(arrData&& src)	//	move constructor
	{
		size = src.size;
		data = src.data;
		src.data = nullptr;
	}
	~arrData()
	{
		delete[] data;
	}
	int getSize() { return size; }
	int getData(int index)
	{
		assert(index < size);
		return data[index];
	}
	void print()
	{
		for(int i = 0; i < size; i++){
			cout << i << " ";
		}
		cout << endl;
	}
};

int main()
{

	arrData a = arrData(5);
	arrData b = arrData(a);		//	deep copying 'a'
	arrData c = arrData(arrData(10));	//	move 'arrData(10)' to 'c'

	a.print();
	b.print();
	c.print();

	arrData d = arrData(std::move(c));

	d.print();

	cout << c.getSize() << endl;
	
	c.print();

	return 0;
}

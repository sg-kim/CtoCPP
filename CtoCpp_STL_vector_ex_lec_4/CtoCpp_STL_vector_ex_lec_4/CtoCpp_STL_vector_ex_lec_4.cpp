// CtoCpp_STL_vector_ex_lec_4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;	//	STL scope. ex) std::vector

int _tmain(int argc, _TCHAR* argv[])
{

	//vector<int> v(100);
	//int vSize = v.size();

	//for(int i = 0; i < vSize; i++){
	//	v[i] = i;
	//}

	//for(vector<int>::iterator p = v.begin(); p != v.end(); p++){
	//	cout << *p << '\t';
	//}
	//cout << endl;

	//cout << v.size() << endl;

	int howMany;

	cout << "How many ints in data?: ";
	cin >> howMany;
	
	vector<int> data(howMany);

	cout << "The contents of data: ";
	for(vector<int>::iterator it = data.begin(); it != data.end(); ++it){	//	the 'data' can be hidden
		cin >> *it;
	}

	for(vector<int>::iterator p = data.begin(); p != data.end(); p++){
		cout << *p << '\t';
	}
	cout << endl;

	for(vector<int>::iterator p = data.begin(); p != data.end(); ++p){
		cout << *p << '\t';
	}
	cout << endl;

	return 0;
}


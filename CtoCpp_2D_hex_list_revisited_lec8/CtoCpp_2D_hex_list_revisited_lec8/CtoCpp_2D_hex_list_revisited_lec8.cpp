// CtoCpp_2D_hex_list_revisited_lec8.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>

#include "hexPanel.h"
#include "hexList.h"

using std::cout;
using std::endl;

int _tmain(int argc, _TCHAR* argv[])
{
	hexList* hList;

	hList = new hexList();

	hList->appendPanel(0, 0, 0);
	hList->appendPanel(1, 0, 0);
	hList->appendPanel(2, 0, 0);

	hList->print();

	cout << "&hList " << &hList << endl;
	cout << "hList " << hList << endl;

	//hexList* hList2 = hList;
	hexList* hList2 = new hexList(*hList);	//	shallow copy

	cout << "&hList2: " << &hList2 << endl;
	cout << "hList2: " << hList2 << endl;

	hList2->print();

	hexList* hList3 = new hexList();
	hList3->copyHexList(hList);	//	deep copy

	cout << "&hList3: " << &hList3 << endl;
	cout << "hList3: " << hList3 << endl;

	hList3->print();

	hList->appendPanel(3, 0, 0);

	hList->print();

	hList2->print();

	hList3->print();
	
	delete hList;
	delete hList2;
	delete hList3;
	
	return 0;
}


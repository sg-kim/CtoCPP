// CtoCpp_2D_hex_list_revisited_lec8.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>

#include "hexPanel.h"
#include "hexList.h"
#include "hexListList.h"

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
	cout << endl;

	cout << "&hList " << &hList << endl;
	cout << "hList " << hList << endl;

	//hexList* hList2 = hList;
	hexList* hList2 = new hexList(*hList);	//	shallow copy

	cout << "&hList2: " << &hList2 << endl;
	cout << "hList2: " << hList2 << endl;

	hList2->print();
	cout << endl;

	hexList* hList3 = new hexList();
	hList3->copyHexList(hList);	//	deep copy

	cout << "&hList3: " << &hList3 << endl;
	cout << "hList3: " << hList3 << endl;

	hList3->print();
	cout << endl;

	hList->appendPanel(3, 0, 0);

	hList->print();
	cout << endl;

	hList2->print();
	cout << endl;

	hList3->print();
	cout << endl;

	cout << "====================================" << endl;

	hexListList* hListList = new hexListList();

	hListList->appendList(*hList2);
	hListList->appendList(*hList3);

	cout << "hListList: " << hListList << endl;

	hListList->print();

	hexListList* hListList2 = new hexListList(*hListList);

	cout << "hListList2: " << hListList2 << endl;

	hListList2->print();
	
	hexListList* hListList3 = new hexListList();

	hListList3->copyhexListList(hListList);

	cout << "hListList3: " << hListList3 << endl;

	delete hListList;

	hListList3->print();

	delete hList;
	delete hList2;
	delete hList3;

	//delete hListList;
	delete hListList2;
	delete hListList3;
	
	return 0;
}


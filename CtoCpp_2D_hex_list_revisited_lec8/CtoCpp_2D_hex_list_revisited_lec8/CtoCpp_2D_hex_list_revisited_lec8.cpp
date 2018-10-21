// CtoCpp_2D_hex_list_revisited_lec8.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include "hexPanel.h"
#include "hexList.h"

int _tmain(int argc, _TCHAR* argv[])
{
	hexList* hList;

	hList = new hexList();

	hList->appendPanel(0, 0, 0);
	hList->appendPanel(1, 0, 0);
	hList->appendPanel(2, 0, 0);

	hList->print();

	delete hList;
	
	return 0;
}


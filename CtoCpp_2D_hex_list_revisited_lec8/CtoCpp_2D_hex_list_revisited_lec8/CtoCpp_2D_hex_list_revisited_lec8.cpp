// CtoCpp_2D_hex_list_revisited_lec8.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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


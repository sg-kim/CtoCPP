// CtoCpp_2d_array_of_classes_ex_lec6.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#include <iostream>

#include "hexPanel.h"
#include "hexMap.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned short boardSize = 2;
	hexPanel* panel;
	hexMap* map = new hexMap(boardSize);

	map->setPanel(0, 0, 0);
	map->setPanel(0, 1, 1);
	map->setPanel(1, 0, 2);
	map->setPanel(1, 1, 3);

	for(int i = 0; i < boardSize; i++){
		for(int j = 0; j < boardSize; j++){

			panel = map->getPanel(i, j);

			cout << panel->getXpos() << endl;
			cout << panel->getYpos() << endl;
			cout << panel->getData() << endl;

			cout << endl;
		}
	}

	return 0;
}


// CtoCpp_hex_game_hw_lec6.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>

#include "hexPanel.h"
#include "hexList.h"
#include "hexListList.h"
#include "hexBoard.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	hexBoard* gameBoard;
	unsigned short boardSize = 5;

	gameBoard = new hexBoard(boardSize);

	gameBoard->displayBoard();

	for(int i = 0; i < boardSize; i++){
		for(int j = 0; j < boardSize; j++){

			cout << j << ", " << i << endl;

			gameBoard->setPanel(j, i, i%2);
		}
	}

	gameBoard->displayBoard();

	delete gameBoard;

	return 0;
}


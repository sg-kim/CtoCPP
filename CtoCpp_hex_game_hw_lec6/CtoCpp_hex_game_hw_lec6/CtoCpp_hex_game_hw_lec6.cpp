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
	int winner;

	gameBoard = new hexBoard(boardSize);

	gameBoard->displayBoard();

	gameBoard->setPanel(0, 0, 0);

	gameBoard->displayBoard();
	gameBoard->displayPath();

	winner = gameBoard->isWinner();
	cout << "Winner = " << winner << endl;

	gameBoard->setPanel(0, 1, 0);

	gameBoard->displayBoard();
	gameBoard->displayPath();

	winner = gameBoard->isWinner();
	cout << "Winner = " << winner << endl;

	gameBoard->setPanel(1, 0, 0);

	gameBoard->displayBoard();
	gameBoard->displayPath();

	winner = gameBoard->isWinner();
	cout << "Winner = " << winner << endl;

	gameBoard->setPanel(1, 1, 0);

	gameBoard->displayBoard();
	gameBoard->displayPath();

	winner = gameBoard->isWinner();
	cout << "Winner = " << winner << endl;

	gameBoard->setPanel(3, 3, 0);

	gameBoard->displayBoard();
	gameBoard->displayPath();

	winner = gameBoard->isWinner();
	cout << "Winner = " << winner << endl;

	gameBoard->setPanel(2, 2, 0);

	gameBoard->displayBoard();
	gameBoard->displayPath();

	winner = gameBoard->isWinner();
	cout << "Winner = " << winner << endl;

	gameBoard->setPanel(2, 3, 0);

	gameBoard->displayBoard();
	gameBoard->displayPath();

	winner = gameBoard->isWinner();
	cout << "Winner = " << winner << endl;

	gameBoard->setPanel(4, 4, 0);

	gameBoard->displayBoard();
	gameBoard->displayPath();

	winner = gameBoard->isWinner();
	cout << "Winner = " << winner << endl;

	//for(int i = 0; i < boardSize; i++){
	//	for(int j = 0; j < boardSize; j++){

	//		gameBoard->setPanel(j, i, i%2);
	//	}
	//}

	//gameBoard->displayBoard();

	//gameBoard->displayPath();

	//winner = gameBoard->isWinner();

	//cout << "Winner = " << winner << endl;

	//delete gameBoard;

	//gameBoard = new hexBoard(boardSize);

	//for(int i = 0; i < boardSize; i++){
	//	for(int j = 0; j < boardSize; j++){

	//		gameBoard->setPanel(j, i, j%2);
	//	}
	//}

	//gameBoard->displayBoard();

	//gameBoard->displayPath();

	//winner = gameBoard->isWinner();

	//cout << "Winner = " << winner << endl;

	delete gameBoard;

	return 0;
}


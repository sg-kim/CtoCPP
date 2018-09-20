// CtoCPP_poker_probability_lec5.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <assert.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//	pip: 1 ~ 13 numbers in cards
//	suit: cards which have the same suit(DIAMOND, HEART, SPADE, CLUB)
//	deck: a set of full cards, which is 52 cards.

//	flush: all five cards have the same suit
//	straight: five cards have consecutive numbers
//	straight flush: five consecutive cards are the same suit

enum class suit:short {SPADE, HEART, DIAMOND, CLUB};

class pip
{
private:
	int v;	//	pip value

public:
	pip(int val):v(val)
	{
		assert(v > 0 && v < 14);
	}
	friend ostream& operator<<(ostream& out, const pip& p);
	int getPip(){
		return v;
	}
};

class card
{
private:
	pip v;
	suit s;
	
public:
	card():s(suit::SPADE), v(1){}
	card(suit s, pip v):s(s), v(v){}
	friend ostream& operator<<(ostream& out, const card& c);
	suit getSuit()
	{
		return s;
	}
	pip getPip()
	{
		return v;
	}
};

ostream& operator<<(ostream& out, card& c)
{
	cout << (c.getPip()).getPip() << static_cast<short>(c.getSuit());
	return out;
}

void initDeck(vector<card>& d)
{
	for(int i = 1; i < 14; i++){
		card c(suit::SPADE, i);
		d[i - 1] = c;
		card c(suit::HEART, i);
		d[i - 1 + 13] = c;
		card c(suit::DIAMOND, i);
		d[i - 1 + 26] = c;
		card c(suit::CLUB, i);
		d[i - 1 + 39] = c;
	}
}

void print(vector<card>& deck)
{
	for(vector<card>::iterator p = deck.begin(); p != deck.end(); p++){
		cout << *p;
	}
	cout << endl;
}

bool isFlush(vector<card>& hand)
{
	int numCard = hand.size();
	suit suit;
	bool flush = true;

	for(int i = 0; i < numCard; i++){

		if(i == 0){
			suit = hand[i].getSuit();
		}
		else{
			if(suit != hand[i].getSuit()){
				flush = false;
				break;
			}
		}
	}

	return flush;
}

bool isStraight(vector<card>& hand)
{
	bool straight = true;
	int numCard = hand.size();

	sort(hand.begin(), hand.end());

	for(int i = 0; i < (numCard - 1); i++){

		if((hand[i].getPip().getPip() + 1) != hand[i + 1].getPip().getPip()){

			//	other cases such as Q, K, A, 2, 3 should be considered.

			straight = false;
			break;
		}
	}

	return straight;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}


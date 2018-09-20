// CtoCpp_assoc_containers_ex_lec5.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <map>
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	map<unsigned long, string> worker;
	unordered_map<unsigned long, unsigned> payroll;
	unsigned totalPay = 0;

	worker[99567800] = "Harold Fish";
	payroll[99567800] = 67300;

	worker[8567800] = "Philip FIsh";
	payroll[8567800] = 87300;

	for(map<unsigned long, string>::iterator p = worker.begin(); p != worker.end(); p++){
		cout << "name: " << p->second << "\t id no." << p->first << endl;
	}

	for(unordered_map<unsigned long, unsigned>::iterator p = payroll.begin(); p != payroll.end(); p++){
		totalPay = totalPay + p->second;
	}

	cout << "payroll totals: " << totalPay << endl;

	return 0;
}


// CtoCPP_graph_hw_lec_4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

#include "Dijkstra_shortest_path.h"
#include "kruskal_MST.h"

using namespace std;

void generateGraph(int** graph, int size)
{
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			graph[i][j] = -1;	//	negative number means no edge
		}
	}

	//graph[0][1] = 4;
	//graph[0][2] = 3;
	//graph[0][4] = 7;

	//graph[1][3] = 1;

	//graph[2][0] = 3;
	//graph[2][4] = 4;

	//graph[3][4] = 3;
	//graph[3][5] = 1;

	//graph[4][5] = 1;
	//graph[4][6] = 5;
	//graph[4][8] = 3;

	//graph[5][7] = 2;
	//graph[5][8] = 4;

	//graph[7][5] = 2;
	//graph[7][8] = 3;

	//graph[8][6] = 5;

	graph[0][1] = 7;	//	A - B
	graph[0][3] = 5;	//	A - D

	graph[1][0] = 7;	//	B - A
	graph[1][2] = 8;	//	B - C
	graph[1][3] = 9;	//	B - D
	graph[1][4] = 7;	//	B - E

	graph[2][1] = 8;	//	C - B
	graph[2][4] = 5;	//	C - E

	graph[3][1] = 9;	//	D - B
	graph[3][4] = 15;	//	D - E
	graph[3][5] = 6;	//	D - F

	graph[4][1] = 7;	//	E - B
	graph[4][2] = 5;	//	E - C
	graph[4][3] = 15;	//	E - D
	graph[4][5] = 8;	//	E - F
	graph[4][6] = 9;	//	E - G

	graph[5][3] = 6;	//	F - D
	graph[5][4] = 8;	//	F - E
	graph[5][6] = 11;	//	F - G

	graph[6][4] = 9;	//	G - E
	graph[6][5] = 11;	//	G - F
}

void displayGraph(int** graph, int size)
{
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//ifstream sampleDataFile("sample_test_data.txt");
	//istream_iterator<int> start(sampleDataFile), end;
	//vector<int> dataSet(start, end);

	int** graph;
	int graphSize = -1;
	list* shortestPath;
	//int dataSetSize = dataSet.size();

	//graphSize = dataSet[0];

	graphSize = 7;	//	num vertices == 7

	graph = (int**)malloc(sizeof(int*)*graphSize);
	for(int i = 0; i < graphSize; i++){
		graph[i] = (int*)malloc(sizeof(int)*graphSize);
		
		for(int j = 0; j < graphSize; j++){
			graph[i][j] = -1;
		}
	}

	generateGraph(graph, graphSize);

	displayGraph(graph, graphSize);

	//for(vector<int>::iterator p = dataSet.begin(); p != dataSet.end(); p++){
	//	cout << *p << '\t';
	//}

	//for(istream_iterator<int> pos = start; pos != end; pos++){
	//	cout << *pos << '\t';
	//}

	//for(int i = 1; i < dataSetSize; i = i + 3){
	//	graph[dataSet[i]][dataSet[i + 1]] = dataSet[i + 2];
	//}
	
	//shortestPath_Dijkstra* SPD;
	//SPD = new shortestPath_Dijkstra(graph, graphSize);

	//SPD->run();

	//shortestPath = SPD->getShortestPath();

	//shortestPath->print();

	//delete SPD;

	list* MST;
	MST_kruskal* kruskal;
	kruskal = new MST_kruskal(graph, graphSize);

	kruskal->run();

	//MST = kruskal->getMST();

	//MST->print();

	delete kruskal;

	for(int i = 0; i < graphSize; i++){
		free(graph[i]);
	}
	free(graph);

	return 0;
}


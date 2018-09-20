// CtoCpp_revisit_dijkstra_hw_lec_3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>

#include "list.h"

using namespace std;

void generateGraph(int** graph, int size)
{
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			graph[i][j] = -1;	//	negative number means no edge
		}
	}

	graph[0][1] = 4;
	graph[0][2] = 3;
	graph[0][4] = 7;

	graph[1][3] = 1;

	graph[2][0] = 3;
	graph[2][4] = 4;

	graph[3][4] = 3;
	graph[3][5] = 1;

	graph[4][5] = 1;
	graph[4][6] = 5;
	graph[4][8] = 3;

	graph[5][7] = 2;
	graph[5][8] = 4;

	graph[7][5] = 2;
	graph[7][8] = 3;

	graph[8][6] = 5;
}

void displayGraph(int** graph, int size)
{
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}

bool checkTargetPath(list* openSet, list* closedSet, int graphSize)
{
	const int startNode = 0;
	const int dstNode = graphSize - 1;

	bool found = false;
	bool dstInClosedSet = false;

	int lenClosedSet = closedSet->length();
	int lenOpenSet = openSet->length();

	int targetPathDistClosedSet = -1;
	int minPathDistOpenSet = -1;

	closedSet->resetPtr();

	for(int i = 0; i < lenClosedSet; i++){
		if(closedSet->getDst() == dstNode){
			dstInClosedSet = true;
			targetPathDistClosedSet = closedSet->getWgt();
		}
		closedSet->next();
	}

	cout << "targetPathDistClosedSet = " << targetPathDistClosedSet << endl;

	if(dstInClosedSet == true){

		cout << "dstInClosedSet == true" << endl;

		openSet->resetPtr();

		for(int i = 0; i < lenOpenSet; i++){
			if(openSet->visited() == false){
				minPathDistOpenSet = openSet->getWgt();

				break;
			}
			openSet->next();
		}

		openSet->resetPtr();

		for(int i = 0; i < lenOpenSet; i++){

			if((openSet->getWgt() < minPathDistOpenSet) && (openSet->visited() == false)){
				minPathDistOpenSet = openSet->getWgt();
			}

			openSet->next();
		}

		cout << "minPathDistOpenSet = " << minPathDistOpenSet << endl;

		if(minPathDistOpenSet >= targetPathDistClosedSet){
			found = true;
		}
	}

	return found;
}

bool checkRechableNode(list* openSet, int startNode, int newNode, int newDist)
{
	bool newItem = true;
	int lenOpenSet = openSet->length();

	if((newNode == 0) || (newNode == startNode)){	//	do not allow loop
		newItem = false;
	}
	else{
		openSet->resetPtr();

		for(int i = 0; i < lenOpenSet; i++){
			if(newNode == openSet->getDst()){
				if(newDist >= openSet->getWgt()){
					newItem = false;
				}
			}
			openSet->next();
		}
	}

	return newItem;
}

void makeOpenSet(int** graph, list* openSet, list* closedSet, int size)
{
	int lenOpenSet = openSet->length();
	int lenCloedSet = closedSet->length();

	int startNode;
	int startDist;
	int rechableNode;
	int dist = -1;

	if(lenCloedSet == 0){
		startNode = 0;
		startDist = 0;
	}
	else{
		closedSet->last();
		startNode = closedSet->getDst();
		startDist = closedSet->getWgt();
	}

	for(int i = 0; i < size; i++){
		if(graph[startNode][i] > 0){
			rechableNode = i;
			dist = graph[startNode][i];

			if(checkRechableNode(openSet, startNode, rechableNode, dist) == true){
				openSet->append(startNode, rechableNode, (dist + startDist), false);
			}
		}
	}		
}

bool checkNewPath(int src, int dst, int dist, list* closedSet)
{
	bool newPath = true;
	int lenClosedSet = closedSet->length();

	closedSet->resetPtr();

	for(int i = 0; i < lenClosedSet; i++){
		if((closedSet->getDst() == dst) && (closedSet->getWgt() <= dist)){
			newPath = false;
		}

		closedSet->next();
	}

	return newPath;
}

void makeClosedSet(list* openSet, list* closedSet, int size)
{
	int lenOpenSet = openSet->length();
	int lenClosedSet = closedSet->length();

	bool newPath = true;
	int selectedSrc;
	int selectedDst;
	int selectedDist;

	openSet->resetPtr();

	for(int i = 0; i < lenOpenSet; i++){

		if(openSet->visited() == false){
			selectedSrc = openSet->getSrc();
			selectedDst = openSet->getDst();
			selectedDist = openSet->getWgt();

			break;
		}

		openSet->next();
	}

	openSet->resetPtr();

	for(int i = 0; i < lenOpenSet; i++){

		if((openSet->visited() == false) && (openSet->getWgt() < selectedDist)){
			selectedSrc = openSet->getSrc();
			selectedDst = openSet->getDst();
			selectedDist = openSet->getWgt();
		}

		openSet->next();
	}

	openSet->resetPtr();

	for(int i = 0; i < lenOpenSet; i++){
		if((openSet->getSrc() == selectedSrc) && (openSet->getDst() == selectedDst) && (openSet->getWgt() == selectedDist)){
			openSet->setVisit();
		}
		openSet->next();
	}

	newPath = checkNewPath(selectedSrc, selectedDst, selectedDist, closedSet);

	if(newPath == true){
		closedSet->append(selectedSrc, selectedDst, selectedDist, true);
	}
}

void buildShortestPath(list* closedSet, list* shortestPath, int graphSize)
{
	int src = graphSize - 1;
	int dst = graphSize - 1;
	int lenClosedSet = closedSet->length();

	while(src != 0){

		closedSet->resetPtr();

		for(int i = 0; i < lenClosedSet; i++){
			if(closedSet->getDst() == dst){
				shortestPath->prepend(closedSet->getSrc(), closedSet->getDst(), closedSet->getWgt(), false);
				src = dst = closedSet->getSrc();

				break;
			}
			closedSet->next();
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int** graph;
	const int graphSize = 9;

	list* openSet;
	list* closedSet;
	list* shortestPath;
	bool found = false;

	graph = (int**)malloc(sizeof(int*)*graphSize);
	for(int i = 0; i < graphSize; i++){
		graph[i] = (int*)malloc(sizeof(int)*graphSize);
	}

	generateGraph(graph, graphSize);

	openSet = new list;
	closedSet = new list;
	shortestPath = new list;

	displayGraph(graph, graphSize);

	while(found == false){

		makeOpenSet(graph, openSet, closedSet, graphSize);

		makeClosedSet(openSet, closedSet, graphSize);

		openSet->print();
		closedSet->print();

		found = checkTargetPath(openSet, closedSet, graphSize);

		cout << found << endl;
	}

	buildShortestPath(closedSet, shortestPath, graphSize);

	shortestPath->print();

	delete openSet;
	delete closedSet;
	delete shortestPath;

	for(int i = 0; i < graphSize; i++){
		free(graph[i]);
	}
	free(graph);

	return 0;
}


#include <iostream>

#include "Dijkstra_shortest_path.h"

using namespace std;

//	found the shortest path?
bool shortestPath_Dijkstra::checkTargetPath(list* openSet, list* closedSet, int graphSize)
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

//	rechable node(newNode) ?= a valid new node
bool shortestPath_Dijkstra::checkRechableNode(list* openSet, int startNode, int newNode, int newDist)
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

void shortestPath_Dijkstra::makeOpenSet(int** graph, list* openSet, list* closedSet, int size)
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

//	a picked path in the open set ?= valid to be included int the closed set
bool shortestPath_Dijkstra::checkNewPath(int src, int dst, int dist, list* closedSet)
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

void shortestPath_Dijkstra::makeClosedSet(list* openSet, list* closedSet, int size)
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

//	build shortest path with a completed closed set
void shortestPath_Dijkstra::buildShortestPath(list* closedSet, list* shortestPath, int graphSize)
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

list* shortestPath_Dijkstra::getShortestPath()
{
	return shortestPath;
}

void shortestPath_Dijkstra::run()
{
	while(found == false){

		makeOpenSet(graph, openSet, closedSet, graphSize);

		makeClosedSet(openSet, closedSet, graphSize);

		openSet->print();
		closedSet->print();

		found = checkTargetPath(openSet, closedSet, graphSize);

		cout << found << endl;
	}

	buildShortestPath(closedSet, shortestPath, graphSize);
}
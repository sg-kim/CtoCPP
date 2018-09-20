// CtoCpp_dijkstra_hw_lec_2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

const int N = 9;

typedef struct link{
	unsigned char src;
	unsigned char dst;
	int dist;
	bool visited;
	struct link *next;
}edge;

void displayEdge(edge *edge)
{
	cout << "(src: " << edge->src << ", dst: " << edge->dst << ", dist: " << edge->dist << ", visited: " << edge->visited << ", next: " << edge->next << ")" << endl;
}

void displayGraph(edge *graph)
{
	if(graph->next == NULL){
		cout << "(" << graph->src << "-->" << graph->dst << ", " << graph->dist << ", visited:" << graph->visited << ")" << endl;
	}
	else{
		cout << "(" << graph->src << "-->" << graph->dst << ", " << graph->dist << ", visited:" << graph->visited << ") ";
		displayGraph(graph->next);
	}
}

void setEdge(edge *item, unsigned char src, unsigned char dst, int dist, bool visited, edge *next_edge)
{
	item->src = src;
	item->dst = dst;
	item->dist = dist;	//	negative means unreachble
	item->visited = visited;
	item->next = next_edge;
}

void copyEdge(edge *src, edge *dst)
{
	dst->src = src->src;
	cout << "src->src: " << src->src << " --> dst->src: " << dst->src << endl;
	dst->dst = src->dst;
	dst->dist = src->dist;
	dst->visited = src->visited;
	dst->next = src->next;
}

edge *selectLastItem(edge *set)
{
	if(set->next == NULL){
		return(set);
	}
	else{
		selectLastItem(set->next);
	}
}

void expandSet(edge **set, edge *item)
{
	edge *newItem;

	newItem = (edge *)malloc(sizeof(edge));
	setEdge(newItem, item->src, item->dst, item->dist, item->visited, NULL);

	if(*set == NULL){
		*set = newItem;
	}
	else{
		selectLastItem(*set)->next = newItem;
	}
}

edge *getSet(edge **graph, unsigned char src)
{
	edge *edgeSet = NULL;

	for(int i = 0; i < N; i++){
		if(graph[i]->src == src){
			edgeSet = graph[i];
		}
	}

	return edgeSet;
}

unsigned int lengthSet(edge *set)
{
	int length = 0;
	edge* curItem = set;

	if(set == NULL){
		return length;
	}

	do{
		if(curItem->dist > 0){
			length++;
		}
		curItem = curItem->next;
	}while(curItem != NULL);

	return length;
}

edge *selectMinDistEdge(edge *set)
{
	edge *minDistEdge = NULL;
	edge *curEdge = set;
	int minDist = INT_MAX;
	int length = lengthSet(set);

	for(int i = 0; i < length; i++){	//	search all items in the set
		if(curEdge->visited == false && curEdge->dist < minDist){	// a nearest node from unvisited nodes
			minDistEdge = curEdge;
			minDist = curEdge->dist;
		}

		if(i < (length - 1)){
			curEdge = curEdge->next;
		}
	}

	return minDistEdge;
}

bool checkNewEdge(edge *set, edge *item)
{
	edge *curEdge = set;
	bool valid = true;
	int length = lengthSet(set);

	//if(length == 0){
	//	valid = false;
	//}

	for(int i = 0; i < length; i++){	//	length = size of the closed set or the open set
		//if(curEdge->src != item->src && curEdge->dst != item->dst){
		if(curEdge->dst != item->dst){	//	check if the path is a new path
			if(curEdge->src == item->dst){	//	the path should not be a way back to src node(= no loop allowded)
				valid = false;
				return valid;
			}
			else{
				curEdge = curEdge->next;
			}
		}
		else{
			if(curEdge->dist > item->dist){		//	if the new path has the same dst, the distance should be smaller than the old path
				curEdge = curEdge->next;
			}
			else{
				valid = false;
				return valid;
			}
		}
	}

	return valid;
}

void makeOpenSet(edge *closedSet, edge **openSet)
{
	edge *minDistEdge = NULL;
	bool valid = false;

	cout << "makeOpenSet: " << endl;

	minDistEdge = selectMinDistEdge(closedSet);		//	select an edge, which has minimum distance in the unvisited edges

	cout << "minDistEdge = ";
	displayEdge(minDistEdge);

	//	validities: 1. not back to the src node(= no loop allowded), 2. has less distance if the dst node is already included in the visited group
	valid = checkNewEdge(*openSet, minDistEdge);

	if(valid){
		//if((*openSet)->dist < 0){
		//	*openSet = minDistEdge;
		//}
		//else{
			expandSet(openSet, minDistEdge);	//	update information of path to nodes with the new and valid path information
		//}
	}

	cout << "openSet = ";
	displayGraph(*openSet);

	cout << endl;
}

bool makeClosedSet(edge** graph, edge **closedSet, edge *openSet)
{
	bool found = false;
	bool valid = false;
	edge *curEdgeOpen = openSet;
	edge *minDistEdgeClosed = NULL;
	edge *newReachableSet = NULL;
	edge *newReachableEdge = NULL;

	int lengthOpen = lengthSet(openSet);
	int lengthClosed = lengthSet(*closedSet);
	int lengthNewReachableSet;

	cout << "makeClosedSet: " << endl;

	cout << "lengthOpen = " << lengthOpen << endl;
	cout << "lengthClosed = " << lengthClosed << endl;

	newReachableEdge = (edge*)malloc(sizeof(edge));

	if(lengthClosed == 0){		//	an empty closed set case
		minDistEdgeClosed = getSet(graph, 'S');		//	start from a 'start node'
	}
	else{	//	there are elements in the close set
		minDistEdgeClosed = selectMinDistEdge(*closedSet);		//	select an edge which has minimum distance
		minDistEdgeClosed->visited = true;		//	visited: the selected edge will not be analyzed again
	}

	cout << "minDistEdgeClosed = ";
	displayEdge(minDistEdgeClosed);

	for(int i = 0; i < lengthOpen; i++){	//	the case of not empty open set
		if(curEdgeOpen->dst == 'T'){	//	edge(path) to the 'target node' exists in the openset
			//	the minimum distance to a unvisited edge is larger than the distance of an known path to the target node
			if(minDistEdgeClosed->dist >= curEdgeOpen->dist){
				found = true;	//	we found the shortes path to the target node
				return found;
			}
		}
		else{
			curEdgeOpen = curEdgeOpen->next;
		}
	}

	if(lengthClosed == 0){		//	an empty closed set case
		newReachableSet = getSet(graph, 'S');	//	start from the 'start node' S
	}
	else{
		newReachableSet = getSet(graph, minDistEdgeClosed->dst);	//	move to the nearest node
	}

	lengthNewReachableSet = lengthSet(newReachableSet);		//	the number of nodes that are reachable from current node

	cout << "newReachableSet = ";
	displayGraph(newReachableSet);
	cout << "lengthNewReachableSet = " << lengthNewReachableSet << endl;

	if(lengthClosed == 0){
		//	in the beginning(there is no visited nodes), the accumulated distance is 0. 
		setEdge(newReachableEdge, newReachableSet->src, newReachableSet->dst, newReachableSet->dist, newReachableSet->visited, NULL);
	}
	else{
		//	accumulate distance of nodes in the path to new reachable node
		setEdge(newReachableEdge, newReachableSet->src, newReachableSet->dst, (minDistEdgeClosed->dist + newReachableSet->dist), newReachableSet->visited, NULL);
	}

	cout << "newReachableEdge = ";
	displayEdge(newReachableEdge);

	for(int i = 0; i < lengthNewReachableSet; i++){

		//	validities: 1. not back to the src node(= no loop allowded), 2. has less distance if the dst node is already included in the visited group
		valid = checkNewEdge(*closedSet, newReachableEdge);

		cout << "valid = " << valid << endl;

		if(valid){
			//if((*closedSet)->dist < 0){		//	empty closed set case	
			//	*closedSet = newReachableEdge;
			//}
			//else{
				expandSet(closedSet, newReachableEdge);		//	expand the closed set with a newly reachable node
			//}
		}

		if( i < (lengthNewReachableSet - 1)){
			valid = false;
			newReachableSet = newReachableSet->next;	//	move to a new realchable node from the current node
			if(lengthClosed == 0){
				setEdge(newReachableEdge, newReachableSet->src, newReachableSet->dst, newReachableSet->dist, newReachableSet->visited, NULL);
			}
			else{
				setEdge(newReachableEdge, newReachableSet->src, newReachableSet->dst, (minDistEdgeClosed->dist + newReachableSet->dist), newReachableSet->visited, NULL);
			}

			cout << "newReachableEdge = ";
			displayEdge(newReachableEdge);
		}
	}

	cout << "closedSet = ";
	displayGraph(*closedSet);

	free(newReachableEdge);

	cout << endl;

	return found;
}

edge *getDstEdge(edge *set, unsigned char node)
{
	int lenSet = lengthSet(set);
	edge *dstEdge = NULL;
	edge *curEdge = set;

	for(int i = 0; i < lenSet; i++){
		if(curEdge->dst == node){
			dstEdge = curEdge;
		}
		else{
			curEdge = curEdge->next;
		}
	}

	return dstEdge;
}

int constructShortestPath(edge *openSet, edge **theSP)
{
	int lengthOpenSet = lengthSet(openSet);
	bool startNodeReached = false;
	edge *targetEdge = openSet;
	unsigned char targetNode = NULL;

	//	find the 'Target edge'
	for(int i = 0; i < lengthOpenSet; i++){
		if(targetEdge->dst == 'T'){
			expandSet(theSP, targetEdge);
			break;
		}
		else{
			targetEdge = targetEdge->next;
		}
	}

	//	iterate until the 'Start node' is found
	while(!startNodeReached){

		targetNode = targetEdge->src;		//	next edge = (dst == curEdge->src)

		if(targetNode == 'S'){
			startNodeReached = true;
		}
		else{
			targetEdge = getDstEdge(openSet, targetNode);
			expandSet(theSP, targetEdge);
		}
	}

	return lengthSet(*theSP);
}

edge *calcDijkstraSP(edge **graph, unsigned int size)
{
	edge *open_set;
	edge *closed_set;
	edge *theSP;

	bool found = false;
	
	open_set = NULL;
	closed_set = NULL;
	theSP = NULL;

	while(found == false){
		
		//	closed set: a set of edges, which have 1 hop distance from a currently visted node.
		//	makeCloseSet: search new paths to new reachable nodes
		found = makeClosedSet(graph, &closed_set, open_set);

		//	open set: a set of selected edges, which have minimum distance from visited nodes.
		//	makeOpenSet: store information of paths of visited nodes.
		makeOpenSet(closed_set, &open_set);
	}

	constructShortestPath(open_set, &theSP);

	return theSP;	//	the Shortest Path
}

edge **makeGraph(int nodes)		//	the target graph
{
	edge **graph;

	graph = (edge**)malloc(sizeof(edge*)*nodes);

	for(int i = 0; i < nodes; i++){
		graph[i] = NULL;
	}

	edge *openEdge = (edge*)malloc(sizeof(edge));

	//	node 'S', start node
	setEdge(openEdge, 'S', 'A', 4, false, NULL);
	expandSet(&graph[0], openEdge);
	setEdge(openEdge, 'S', 'B', 3, false, NULL);
	expandSet(&graph[0], openEdge);
	setEdge(openEdge, 'S', 'D', 7, false, NULL);
	expandSet(&graph[0], openEdge);	

	//	node 'A'
	setEdge(openEdge, 'A', 'C', 1, false, NULL);
	expandSet(&graph[1], openEdge);

	//	node 'B'
	setEdge(openEdge, 'B', 'S', 3, false, NULL);
	expandSet(&graph[2], openEdge);
	setEdge(openEdge, 'B', 'D', 4, false, NULL);
	expandSet(&graph[2], openEdge);

	//	node 'C'
	setEdge(openEdge, 'C', 'D', 3, false, NULL);
	expandSet(&graph[3], openEdge);
	setEdge(openEdge, 'C', 'E', 1, false, NULL);
	expandSet(&graph[3], openEdge);

	//	node 'D'
	setEdge(openEdge, 'D', 'E', 1, false, NULL);
	expandSet(&graph[4], openEdge);
	setEdge(openEdge, 'D', 'F', 5, false, NULL);
	expandSet(&graph[4], openEdge);
	setEdge(openEdge, 'D', 'T', 3, false, NULL);
	expandSet(&graph[4], openEdge);

	//	node 'E'
	setEdge(openEdge, 'E', 'G', 2, false, NULL);
	expandSet(&graph[5], openEdge);
	setEdge(openEdge, 'E', 'T', 4, false, NULL);
	expandSet(&graph[5], openEdge);

	//	node 'F'
	setEdge(openEdge, 'F', 'F', -1, false, NULL);
	expandSet(&graph[6], openEdge);

	//	node 'G'
	setEdge(openEdge, 'G', 'E', 2, false, NULL);
	expandSet(&graph[7], openEdge);
	setEdge(openEdge, 'G', 'T', 3, false, NULL);
	expandSet(&graph[7], openEdge);

	//	node 'T', the target node
	setEdge(openEdge, 'T', 'F', 5, false, NULL);
	expandSet(&graph[8], openEdge);

	free(openEdge);

	return graph;
}

//void freeEdgeList(edge *edges)
//{
//	edge *nextItem = NULL;
//
//	nextItem = edges->next;
//
//	if(nextItem == NULL){
//		free(edges);
//	}
//	else{
//		free(edges);
//		freeEdgeList(nextItem);
//	}
//}

void freeEdgeList(edge **edges)
{
	edge *nextItem = NULL;

	nextItem = (*edges)->next;

	if(nextItem == NULL){
		free(*edges);
	}
	else{
		free(*edges);
		freeEdgeList(&nextItem);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	edge **graph;
	edge *shortestPath;
	graph = makeGraph(N);

	//	graph = group of edges
	//	edge = (src + dst + dist + visited + next edge)
	//	next edge: for a set of edges, which have common characteristics such as the same src
	
	for(int i = 0; i < N; i++){
		displayGraph(graph[i]);
	}
	cout << endl;

	shortestPath = calcDijkstraSP(graph, N);

	cout << "The shortest path: ";
	displayGraph(shortestPath);

	for(int i = 0; i < N; i++){
		freeEdgeList(&graph[i]);
	}

	free(graph);

	freeEdgeList(&shortestPath);

	return 0;
}

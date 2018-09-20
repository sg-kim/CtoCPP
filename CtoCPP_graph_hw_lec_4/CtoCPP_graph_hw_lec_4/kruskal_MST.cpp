
#include <iostream>

#include <vector>

#include "kruskal_MST.h"

using namespace std;

void MST_kruskal::minCostEdge(list* minDistEdge)
{
	bool visited = false;
	int weight;
	bool initialItem = false;

	listGraph->resetPtr();

	//	find minimum distance edge
	for(int i = 0; i < numEdges; i++){

		visited = listGraph->visited();
		weight = listGraph->getWgt();

		if(initialItem == false){
			if(visited == false){
				minDistEdge->setSrc(listGraph->getSrc());
				minDistEdge->setDst(listGraph->getDst());
				minDistEdge->setWgt(listGraph->getWgt());

				initialItem = true;
			}
		}
		else{
			if((visited == false) && (weight < minDistEdge->getWgt())){
				minDistEdge->setSrc(listGraph->getSrc());
				minDistEdge->setDst(listGraph->getDst());
				minDistEdge->setWgt(listGraph->getWgt());
			}
		}

		listGraph->next();
	}

	listGraph->resetPtr();

	//	mark visited to the min dist edge
	for(int i = 0; i < numEdges; i++){

		if((listGraph->getSrc() == minDistEdge->getSrc()) &&
			(listGraph->getDst() == minDistEdge->getDst()) &&
			(listGraph->getWgt() == minDistEdge->getWgt())){

				listGraph->setVisit();
		}

		listGraph->next();
	}

}

bool MST_kruskal::checkLoop(list* eut)
{
	//int exist = 0;
	//bool loop = false;
	//int numClosedSet = closedSet->length();
	//int src;
	//int dst;
	//int srcEut = eut->getSrc();
	//int dstEut = eut->getDst();

	//closedSet->resetPtr();

	//for(int i = 0; i < numClosedSet; i++){

	//	src = closedSet->getSrc();
	//	dst = closedSet->getDst();

	//	if((src == srcEut) || (src == dstEut)){
	//		exist++;
	//	}
	//	if((dst == dstEut) || (dst == srcEut)){
	//		exist++;
	//	}

	//	//if(((src == srcEut) && (dst == dstEut)) || ((src == dstEut) && (dst == srcEut))){

	//	//	loop = true;

	//	//	break;
	//	//}

	//	if(exist > 1){

	//		loop = true;

	//		break;
	//	}

	//	closedSet->next();
	//}

	int numClosedSet = closedSet->length();
	int numElementSegAcyclic;	//	number of elements in an acyclic graph segment
	int numSharedVertices;	//	number of shared vertices between a target edge and a (sub) graph
	bool loop = false;

	//	calculate number of acyclic graph segments

	bool visitAllVertices;
	int srcEut;	//	source of an edge under test;
	int dstEut;	//	destination of an edge under test;
	int srcTarget;	//	source of a target edge;
	int dstTarget;	//	destination of a target edge;
	list* acyclic;
	int numSegAcyclic = 0;
	int segAcyclicGroup = 0;
	int numVisitedEdge = 0;
	bool sharedSrcEut = false;
	bool sharedDstEut = false;

	visitAllVertices = (numClosedSet == numVisitedEdge) ? true : false;

	closedSet->resetPtr();

	for(int i = 0; i < numClosedSet; i++){
		closedSet->resetVisit();
		closedSet->next();
	}

	closedSet->resetPtr();

	acyclic = new list();

	//acyclic->append(closedSet->getSrc(), closedSet->getDst(), closedSet->getWgt(), false);
	//closedSet->setVisit();
	//numVisitedEdge++;

	cout << "numClosedSet = " << numClosedSet << endl;

	while(!visitAllVertices){

		if(acyclic->end() == true){

			closedSet->resetPtr();

			//	find an unvisited edge in the set
			for(int i = 0; i < numClosedSet; i++){
				if(closedSet->visited() == false){
					acyclic->append(closedSet->getSrc(), closedSet->getDst(), closedSet->getWgt(), false);
					closedSet->setVisit();
					numVisitedEdge++;

					break;
				}

				closedSet->next();
			}

			acyclic->print();

			numSegAcyclic++;
		}

		srcEut = acyclic->getSrc();
		dstEut = acyclic->getDst();

		//cout << "(srcEut, dstEut) = " << "(" << srcEut << ", " << dstEut << ")" << endl;

		closedSet->resetPtr();

		for(int i = 0; i < numClosedSet; i++){

			srcTarget = closedSet->getSrc();
			dstTarget = closedSet->getDst();

			//cout << "(srcTarget, dstTarget) = " << "(" << srcTarget << ", " << dstTarget << ")" << endl;

			//	the target edge has not visted yet ans shared vertices with the edge under test
			if((closedSet->visited() == false) &&
				(srcEut == srcTarget || srcEut == dstTarget || dstEut == srcTarget || dstEut == dstTarget)){
					//cout << "Eut == Target" << endl;
					acyclic->append(srcTarget, dstTarget, closedSet->getWgt(), false);
					closedSet->setVisit();
					numVisitedEdge++;
			}

			closedSet->next();
		}

		acyclic->next();

		visitAllVertices = (numVisitedEdge == numClosedSet) ? true : false;
	}

	closedSet->resetPtr();

	for(int i = 0; i < numClosedSet; i++){
		closedSet->resetVisit();
		closedSet->next();
	}

	//cout << "numSegAcyclic = " << numSegAcyclic << endl;
	
	//	make sets of acyclic segments

	vector<list> segAcyclic(numSegAcyclic);

	numVisitedEdge = 0;
	visitAllVertices = (numVisitedEdge == numClosedSet) ? true : false;

	while(!visitAllVertices){

		if(segAcyclic[segAcyclicGroup].end() == true){

			closedSet->resetPtr();

			for(int i = 0; i < numClosedSet; i++){
				if(closedSet->visited() == false){
					segAcyclic[segAcyclicGroup].append(closedSet->getSrc(), closedSet->getDst(), closedSet->getWgt(), false);
					closedSet->setVisit();
					numVisitedEdge++;

					break;
				}

				closedSet->next();
			}
		}

		srcEut = segAcyclic[segAcyclicGroup].getSrc();
		dstEut = segAcyclic[segAcyclicGroup].getDst();

		closedSet->resetPtr();

		for(int i = 0; i < numClosedSet; i++){

			srcTarget = closedSet->getSrc();
			dstTarget = closedSet->getDst();

			if((closedSet->visited() == false) &&
				(srcEut == srcTarget || srcEut == dstTarget || dstEut == srcTarget || dstEut == dstTarget)){
					segAcyclic[segAcyclicGroup].append(srcTarget, dstTarget, closedSet->getWgt(), false);
					closedSet->setVisit();
					numVisitedEdge++;
			}

			closedSet->next();
		}

		segAcyclic[segAcyclicGroup].next();

		if(segAcyclic[segAcyclicGroup].end() == true){
			segAcyclicGroup++;
		}

		visitAllVertices = (numVisitedEdge == numClosedSet) ? true : false;
	}

	for(int i = 0; i < numSegAcyclic; i++){

		cout << "Acyclic Segment " << i << ": ";
		segAcyclic[i].print();
	}

	//	check whether or not if the target edge has shared vertices with a segment more than or equal of two

	srcEut = eut->getSrc();
	dstEut = eut->getDst();

	//cout << "(srcEut, dstEut) = (" << srcEut << ", " << dstEut << ")" << endl;

	//cout << "numSegAcyclic = " << numSegAcyclic << endl;

	for(int i = 0; i < numSegAcyclic; i++){

		numElementSegAcyclic = segAcyclic[i].length();

		//cout << "numElementSegAcyclic = " << numElementSegAcyclic << endl;

		sharedSrcEut = false;
		sharedDstEut = false;
		numSharedVertices = 0;

		segAcyclic[i].resetPtr();

		for(int j = 0; j < numElementSegAcyclic; j++){

			srcTarget = segAcyclic[i].getSrc();
			dstTarget = segAcyclic[i].getDst();

			//cout << "(srcTar, dstTar) = (" << srcTarget << ", " << dstTarget << ")" << endl;

			if(sharedSrcEut == false){
				if((srcEut == srcTarget) || (srcEut == dstTarget)){
					numSharedVertices++;
					sharedSrcEut = true;
				}
			}
			if(sharedDstEut == false){
				if((dstEut == srcTarget) || (dstEut == dstTarget)){
					numSharedVertices++;
					sharedDstEut = true;
				}
			}

			if(numSharedVertices == 2){
				loop = true;
				break;
			}

			segAcyclic[i].next();
		}

		//cout << "numSharedVertices  = " << numSharedVertices << endl;

		if(numSharedVertices == 2){
			break;
		}
	}

	delete acyclic;

	return loop;
}

bool MST_kruskal::checkClosedSet()
{
	bool all = true;
	int numClosedSet = closedSet->length();
	int src;
	int dst;

	cout << "graphSize = " << graphSize << endl;

	vector<int> vertices(graphSize);

	closedSet->resetPtr();

	if(numClosedSet == 0){
		all = false;
	}
	else{
		for(int i = 0; i < numClosedSet; i++){

			src = closedSet->getSrc();
			dst = closedSet->getDst();

			vertices[src]++;
			vertices[dst]++;

			closedSet->next();
		}

		cout << "vector<int> vertices ";

		for(vector<int>::iterator p = vertices.begin(); p != vertices.end(); p++){

			cout << *p << " ";

			if(*p == 0){
				all = false;
				break;
			}
		}

		cout << endl;
	}

	return all;
}

void MST_kruskal::run()
{
	list* minDistEdge;
	bool loop;

	minDistEdge = new list();

	while(allVertices == false){

		minCostEdge(minDistEdge);

		cout << "minDistEdge = (" << minDistEdge->getSrc() << ", " << minDistEdge->getDst() << ", " << minDistEdge->getWgt() << ")" << endl;

		loop = checkLoop(minDistEdge);

		cout << "loop = " << loop << endl;

		if(loop == false){
			closedSet->append(minDistEdge->getSrc(), minDistEdge->getDst(), minDistEdge->getWgt(), false);
		}

		allVertices = checkClosedSet();

		cout << "allVertices = " << allVertices << endl;

		cout << "closed Set: ";
		closedSet->print();

		cout << endl;
	}

	delete minDistEdge;

}

list* MST_kruskal::getMST()
{
	return closedSet;
}

#include "list.h"

class shortestPath_Dijkstra
{
private:
	list* openSet;
	list* closedSet;
	list* shortestPath;

	int** graph;

	bool found;
	int graphSize;

	//	found the shortest path?
	bool checkTargetPath(list* openSet, list* closedSet, int graphSize);

	//	rechable node(newNode) ?= a valid new node
	bool checkRechableNode(list* openSet, int startNode, int newNode, int newDist);

	void makeOpenSet(int** graph, list* openSet, list* closedSet, int size);

	//	a picked path in the open set ?= valid to be included int the closed set
	bool checkNewPath(int src, int dst, int dist, list* closedSet);

	void makeClosedSet(list* openSet, list* closedSet, int size);

	//	build shortest path with a completed closed set
	void buildShortestPath(list* closedSet, list* shortestPath, int graphSize);

public:
	shortestPath_Dijkstra(int** targetGraph, int size): graph(targetGraph), graphSize(size)
	{
		found = false;
		openSet = new list;
		closedSet = new list;
		shortestPath = new list;
	}
	~shortestPath_Dijkstra()
	{
		delete openSet;
		delete closedSet;
		delete shortestPath;
	}
	list* getShortestPath();
	void run();
};

#include "list.h"

class MST_kruskal
{
private:
	list* closedSet;
	list* listGraph;

	int graphSize;
	int numEdges;
	bool allVertices;
	bool loop;

	void minCostEdge(list* minDistEdge);
	bool checkLoop(list* eut);
	bool checkClosedSet();

public:
	MST_kruskal(int** graph, int size): graphSize(size)
	{
		closedSet = new list();
		listGraph = new list();

		for(int i = 0; i < graphSize; i++){
			for(int j = i; j < graphSize; j++){

				if(graph[i][j] > 0){
					listGraph->append(i, j, graph[i][j], false);
				}
			}
		}

		allVertices = false;
		loop = false;
		numEdges = listGraph->length();
	}
	~MST_kruskal()
	{
		delete closedSet;
		delete listGraph;
	}
	void run();
	list* getMST();
};

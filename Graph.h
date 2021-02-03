#ifndef GRAPH_H
#define GRAPH_H

#include <algorithm>
#include <vector>
#include "Edge.h"

using namespace std;

class Graph {
public:
	Graph(int _vertexCnt = 0, bool weighted = false);
	int getVertexCnt();
	int getEdgeCnt();
	void addEdge(int a, int b, int w = 1);
	int addVertex();

private:
	bool weighted;
	int vertexCnt;
	int edgeCnt;
	vector<vector<Edge>> edges;

};

#endif // GRAPH_H
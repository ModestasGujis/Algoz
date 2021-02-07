#ifndef GRAPH_H
#define GRAPH_H

#include <algorithm>
#include <vector>
#include "Edge.h"

using namespace std;

class Graph {
public:
	Graph(int _vertexCnt = 0, bool _weighted = false);
	Graph(int _vertexCnt, vector<int> from, vector<int> to, vector<int> weight);
	Graph(int _vertexCnt, vector<int> from, vector<int> to);
	int getVertexCnt();
	int getEdgeCnt();
	void addEdge(int a, int b, int w = 1);
	int addVertex();
	int shortestDistance(int a, int b); // -1 if path doesn't exist
	vector<int> shortestPath(int a, int b); // empty vector if ...
private:
	bool weighted;
	int vertexCnt;
	int edgeCnt;
	vector<vector<Edge>> edges;
	void getShortestOneToAllDijkstra(int from, vector<int> &dist, bool backtrack = false);
	void getShortestOneToAllBFS(int from, vector<int> &dist, bool backtrack = false);
};

#endif // GRAPH_H
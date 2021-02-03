#include <algorithm>
#include "Edge.h"

using namespace std;

class Graph {
public:
	Graph(int _N = 0, bool weighted = false);
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

#include <algorithm>
#include <cassert>

#include "Graph.h"

using namespace std;

// Graph::Graph() {
//     Graph(0, false);
// // }

Graph::Graph(int _vertexCnt, bool _weighted) {
    vertexCnt = _vertexCnt;
    weighted = _weighted;
    edges = vector<vector<Edge>>(_vertexCnt);
    edgeCnt = 0;
}

int Graph::getVertexCnt() { return vertexCnt; };
int Graph::getEdgeCnt() { return edgeCnt; };
void Graph::addEdge(int from, int to, int weight) {
    assert(from >= 0 && to >= 0 && from < vertexCnt && to < vertexCnt);
    edges[from].emplace_back(Edge(from, to, weight));
    edgeCnt++;
};
int Graph::addVertex() {
    edges.emplace_back(vector<Edge>());
    return vertexCnt++;
};

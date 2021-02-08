#include <algorithm>
#include <queue>
#include <cassert>
#include <utility>
#include <stdio.h>

#include "Graph.h"

using namespace std;

Graph::Graph(int _vertexCnt, bool _weighted) {
	vertexCnt = _vertexCnt;
	weighted = _weighted;
	edges = vector<vector<Edge>>(_vertexCnt);
	edgeCnt = 0;
}

Graph::Graph(int _vertexCnt, vector<int> from, vector<int> to, vector<int> weight) {
	vertexCnt = _vertexCnt;
	weighted = true;
	edges = vector<vector<Edge>>(_vertexCnt);
	edgeCnt = 0;

	for (int i = 0; i < (int)from.size(); ++i)
	{
		addEdge(from[i], to[i], weight[i]);
	}
}

Graph::Graph(int _vertexCnt, vector<int> from, vector<int> to) {
	vertexCnt = _vertexCnt;
	weighted = false;
	edges = vector<vector<Edge>>(_vertexCnt);
	edgeCnt = 0;

	for (int i = 0; i < (int)from.size(); ++i)
	{
		addEdge(from[i], to[i]);
	}
}

int Graph::getVertexCnt() { return vertexCnt; }
int Graph::getEdgeCnt() { return edgeCnt; }
void Graph::addEdge(int from, int to, int weight) {
	assert(from >= 0 && to >= 0 && from < vertexCnt && to < vertexCnt);
	edges[from].emplace_back(Edge(from, to, weight));
	edgeCnt++;
}

int Graph::addVertex() {
	edges.emplace_back(vector<Edge>());
	return vertexCnt++;
}

void Graph::getShortestOneToAllDijkstra(int from, vector<int> &dist, bool backtrack) {
	assert(from >= 0 and from < vertexCnt);
	dist = vector<int>(vertexCnt, -1);
	vector<int> origin;
	if (backtrack) origin = vector<int>(vertexCnt, -1);
	dist[from] = 0;
	priority_queue<pair<int, int>> pq; // {negative distance, vertex}
	pq.push({0, from}); // {max heap}

	while (pq.size()) {
		int c = pq.top().second;
		int d = -pq.top().first;
		pq.pop();

		if (d > dist[c]) continue;

		for (Edge nxt : edges[c]) {
			if (dist[nxt.to] == -1 or dist[c] + nxt.weight < dist[nxt.to]) {
				dist[nxt.to] = dist[c] + nxt.weight;
				if (backtrack) {
					origin[nxt.to] = c;
				}
				pq.push({ -dist[nxt.to], nxt.to});
			}
		}
	}
	if (backtrack) dist = origin;
}

void Graph::getShortestOneToAllBFS(int from, vector<int> &dist, bool backtrack) {
	assert(from >= 0 and from < vertexCnt);
	dist = vector<int>(vertexCnt, -1);
	vector<int> origin;
	if (backtrack) origin = vector<int>(vertexCnt, -1);

	dist[from] = 0;
	queue<int> q;
	q.push(from);

	while (q.size()) {
		int c = q.front(); q.pop();

		for (Edge nxt : edges[c]) {
			if (dist[nxt.to] == -1 or dist[c] + nxt.weight < dist[nxt.to]) {
				dist[nxt.to] = dist[c] + nxt.weight;
				if (backtrack) {
					origin[nxt.to] = c;
				}
				q.push(nxt.to);
			}
		}
	}
	if (backtrack) dist = origin;
}

int Graph::shortestDistance(int a, int b) {
	assert(a >= 0 and a < vertexCnt and b >= 0 and b < vertexCnt);
	vector<int> dist;
	if (weighted) getShortestOneToAllDijkstra(a, dist);
	else getShortestOneToAllBFS(a, dist);

	return dist[b];
}

vector<int> Graph::shortestPath(int a, int b) {
	assert(a >= 0 and a < vertexCnt and b >= 0 and b < vertexCnt);
	vector<int> backtrack;
	if (weighted) getShortestOneToAllDijkstra(a, backtrack, true);
	else getShortestOneToAllBFS(a, backtrack, true);

	if (backtrack[b] == -1) return vector<int>();

	vector<int> path;
	int c = b;
	while (c != a) {
		path.emplace_back(c);
		c = backtrack[c];
	}
	path.emplace_back(a);
	reverse(path.begin(), path.end());
	return path;
}

bool Graph::hasACycle() {
	vector<bool> visited(vertexCnt, false);

	for (int i = 0; i < vertexCnt; ++i)
	{
		if (!visited[i]) {
			if (Graph::hasACycleUtil(i, visited))
				return true;
		}
	}
	return false;
}

bool Graph::hasACycleUtil(int v, vector<bool> &visited) {
	visited[v] = true;

	for (Edge ed : edges[v]) {
		if (visited[ed.to]) return true;

		if (Graph::hasACycleUtil(ed.to, visited))
			return true;
	}

	return false;
}

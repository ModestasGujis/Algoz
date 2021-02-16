#include <algorithm>
#include <queue>
#include <cassert>
#include <utility>
#include <stdio.h>
#include <iostream>

#include "Graph.h"
#include "../DSU/DSU.h"

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
	vector<int> visited(vertexCnt, 0);

	for (int i = 0; i < vertexCnt; ++i)
	{
		if (!visited[i]) {
			if (Graph::hasACycleUtil(i, visited))
				return true;
		}
	}
	return false;
}

bool Graph::hasACycleUtil(int v, vector<int> &visited) {
	visited[v] = 1;

	for (Edge ed : edges[v]) {
		if (visited[ed.to] == 1) return true;

		if (Graph::hasACycleUtil(ed.to, visited))
			return true;
	}

	visited[v] = 2;
	return false;
}

vector<int> Graph::topoSort() {
	if (Graph::hasACycle()) return vector<int>();

	vector<int> currentrSort;
	vector<bool> visited(vertexCnt, false);

	for (int i = 0; i < vertexCnt; ++i)
	{
		if (!visited[i]) {
			topoSortUtil(i, currentrSort, visited);
		}
	}

	reverse(currentrSort.begin(), currentrSort.end());

	return currentrSort;
}

void Graph::topoSortUtil(int v, vector<int> &currentrSort, vector<bool> &visited) {
	visited[v] = true;

	for (Edge ed : edges[v]) {
		if (!visited[ed.to]) {
			Graph::topoSortUtil(ed.to, currentrSort, visited);
		}
	}

	currentrSort.emplace_back(v);
}

vector<int> Graph::connectedComp(int v) {
	vector<bool> visited(vertexCnt, false);
	connectedCompUtil(v, visited);

	vector<int> components;
	for (int i = 0; i < vertexCnt; ++i)
	{
		if (visited[i])
			components.emplace_back(i);
	}

	return components;
}

void Graph::connectedCompUtil(int v, vector<bool> &visited) {
	visited[v] = true;

	for (Edge ed : edges[v])
		if (!visited[ed.to])
			connectedCompUtil(ed.to, visited);
}

vector<vector<int>> Graph::MST() {
	vector<Edge> all_edges;
	for (int i = 0; i < vertexCnt; ++i)
	{
		for (Edge u : edges[i]) {
			if (i < u.to) {
				all_edges.emplace_back(u);
			}
		}
	}

	sort(all_edges.begin(), all_edges.end(), [](const Edge & a, const Edge & b) {
		return a.weight < b.weight;
	});

	DSU connected(vertexCnt);

	vector<vector<int>> result;

	for (Edge e : all_edges) {
		if (connected.isSameSet(e.from, e.to)) continue;

		connected.unionSet(e.from, e.to);
		result.emplace_back(vector<int>{e.from, e.to, e.weight});
	}

	if ((int)result.size() != vertexCnt - 1) // graph is not connected
		return vector<vector<int>>();

	return result;
}

int Graph::maxFlowBFS(int s, int t, vector<int>& parents, vector<vector<int>> capacities) {
	fill(parents.begin(), parents.end(), -1);
	parents[s] = -2;
	queue<pair<int, int>> q;
	q.push({s, INT32_MAX});

	while(!q.empty()) {
		int current = q.front().first;
		int flow = q.front().second;
		q.pop();
		
		for (Edge next : edges[current]) {
			if(parents[next.to] == -1 && capacities[current][next.to]) {
				parents[next.to] = current;
                int new_flow = min(flow, capacities[current][next.to]);
                if (next.to == t)
                    return new_flow;
                q.push({next.to, new_flow});
			}
		}
	}
	return 0;
}

int Graph::maxFlow(int source, int sink) {
	vector<vector<int>> capacities(vertexCnt, vector<int>(vertexCnt, 0));
	for(int i = 0; i < vertexCnt; i++) {
		for(Edge j : edges[i]) {
			capacities[i][j.to] += j.weight;
		}
	}

	int flow = 0;
	vector<int> parent(vertexCnt);
	int new_flow;
	while((new_flow = maxFlowBFS(source, sink, parent, capacities))) {
        flow += new_flow;
        int current = sink;
        while (current != source) {
            int previous = parent[current];
            capacities[previous][current] -= new_flow;
            capacities[current][previous] += new_flow;
            current = previous;
        }
    }
    return flow;
}

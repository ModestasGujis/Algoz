#ifndef EDGE_H
#define EDGE_H

#include <algorithm>

using namespace std;

class Edge {
public:
	Edge();
	Edge(int from, int to, int weight = 1);
	int getFrom();
	int getTo();
	int getWeight();
private:
	int from;
	int to;
	int weight;
};

#endif // EDGE_H
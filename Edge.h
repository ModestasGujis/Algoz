#include <algorithm>

using namespace std;

class Edge {
public:
	Edge(int from, int to, int weight = 1);
	int getFrom();
	int getTo();
	int getWeight();
private:
	int from;
	int to;
	int weight;
};
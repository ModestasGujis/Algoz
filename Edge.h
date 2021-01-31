#include <algorithm>

using namespace std;

class Edge {
public:
	int getFrom();
	int getTo();
	int getWeight();
private:
	int from;
	int to;
	int weight;
};
#include <algorithm>
#include "Edge.h"

using namespace std;

class WeightedEdge : public Edge {
public:
	int getWeight();

private:
	int weight;
}
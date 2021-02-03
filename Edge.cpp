#include "Edge.h"
#include <algorithm>

using namespace std;

Edge::Edge(int m_from, int m_to, int m_weight) {
    from  = m_from;
    to = m_to;
    weight = m_weight;
}

int Edge::getFrom() { return from; }

int Edge::getTo() { return to; }

int Edge::getWeight() { return weight; }



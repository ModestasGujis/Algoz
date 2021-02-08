#include <algorithm>
#include <numeric>

#include "DSU.h"

using namespace std;

DSU::DSU(int n) {
	size = n;
	rank = vector<int>(n, 1);
	sz = vector<int>(n, 1);
	p = vector<int>(n);
	iota(p.begin(), p.end(), 0);
}

int DSU::getSize() {
	return size;
}

int DSU::getSize(int i) {
	return sz[findSet(i)];
}

int DSU::findSet(int i) {
	return (p[i] == i) ? i : (p[i] = findSet(p[i]));
}

bool DSU::isSameSet(int i, int j) {
	return findSet(i) == findSet(j);
}

bool DSU::unionSet(int i, int j) {
	if (isSameSet(i, j)) return false;

	int x = findSet(i), y = findSet(j);

	if (rank[x] < rank[y]) swap(x, y);

	sz[x] += sz[y];
	p[y] = x;
	if (rank[x] == rank[y]) rank[x]++;
	return true;
}
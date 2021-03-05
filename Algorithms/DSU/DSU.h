#ifndef DSU_H
#define DSU_H

#include <algorithm>
#include <vector>

using namespace std;

class DSU {
public:
	DSU(int n);
	int getSize();
	int getSize(int a);
	int findSet(int i);
	bool isSameSet(int i, int j);
	bool unionSet(int i, int j); // false if already in union
private:
	vector<int> rank;
	vector<int> sz;
	vector<int> p; // parent
	int size;
};

#endif // DSU_H
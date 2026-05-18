/*

kruskals algorithm using disjoint set

note : nodes are numbered from 1 to n

e.g.

input :

7 9

1 2 4
1 3 5
2 4 2
2 5 7
3 4 6
3 6 9
5 6 1
5 7 3
6 7 8

output :

22

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class disjointSet {

	vector<int> parMap;
	vector<int> rankMap;

public:

	disjointSet(int n) {
		parMap.resize(n + 1);
		rankMap.resize(n + 1);
	}

	// time : O(1)

	void createSet(int x) {
		parMap[x] = x;
		rankMap[x] = 0;
	}

	int findSet(int x) {
		if (parMap[x] == x) {
			return x;
		}

		return parMap[x] = findSet(parMap[x]); // path compression
	}

	void unionSet(int x, int y) {
		int lx = findSet(x);
		int ly = findSet(y);
		if (lx != ly) {

			if (rankMap[lx] == rankMap[ly]) {
				rankMap[lx]++;
			}

			if (rankMap[lx] > rankMap[ly]) {
				parMap[ly] = lx;
			} else {
				parMap[lx] = ly;
			}

		}
	}

};


int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> edges; // each edge is represented by a 3-sized vector
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({w, u, v});
	}

	// mlogm

	sort(edges.begin(), edges.end()); // when you sort a vector<vector<int>> then by default sorting is done in inc. order based on 1st member of internal vector which in our case is weight of the edge

	// n

	disjointSet ds(n);
	for (int i = 1; i <= n; i++) {
		ds.createSet(i);
	}

	vector<vector<int>> mst; // to track V-1 safe edges
	int mstSum = 0;

	// m

	for (vector<int> e : edges) {
		int w = e[0];
		int u = e[1];
		int v = e[2];
		if (ds.findSet(u) != ds.findSet(v)) {
			// uv is a safe edge, pick it
			ds.unionSet(u, v);
			mst.push_back(e);
			mstSum += w;
			if (mst.size() == n - 1) {
				break;
			}
		}
	}

	cout << mstSum << endl;
	for (vector<int> e : mst) {
		int w = e[0];
		int u = e[1];
		int v = e[2];
		cout << u << " " << v << " : " << w << endl;
	}

	// time : mlogm + n + m ~ O(mlogm) or O(ElogE)
	// space: n due to disjointSet


	return 0;
}
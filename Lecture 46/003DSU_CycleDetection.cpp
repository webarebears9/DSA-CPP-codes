/*

cycle detection in an undirected graph using disjoint set

note : nodes are numbered from 1 to n

e.g.

input :

4 4

1 2
2 3
3 4
4 1

output :

true

*/

#include<iostream>
#include<vector>

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

	vector<vector<int>> edges; // edgelist repr
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		edges.push_back({u, v});
	}

	// time : O(n+m) or O(V+E)
	// space: O(n) or O(V) due to disjointSet

	disjointSet ds(n);

	for (int i = 1; i <= n; i++) {
		ds.createSet(i);
	}

	bool flag = false; // assume no cycle is present

	for (vector<int> e : edges) {
		int u = e[0];
		int v = e[1];
		if (ds.findSet(u) != ds.findSet(v)) {
			// u and v are present in different sets
			ds.unionSet(u, v);
		} else {
			// u and v are present in the same set
			// which means they are present in the same component
			// which means there is a path b/w them
			// and now there is an edge b/w which means
			// there are multiple ways or paths b/w u and v
			// hence my graph contains a cycle
			flag = true;
			break;
		}
	}

	if (flag) {
		cout << "cycle found" << endl;
	} else {
		cout << "cycle not found" << endl;
	}

	return 0;
}
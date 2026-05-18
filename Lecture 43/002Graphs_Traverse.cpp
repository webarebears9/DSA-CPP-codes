/*

Implementation of graph traversal using

	1. depth first search (dfs)
	2. breadth first search (bfs)

	e.g.

	16 16

	0 2
	0 3
	1 3
	1 4
	2 5
	3 5
	3 6
	4 6

	7 9
	8 9
	9 10
	9 11

	12 13
	12 14
	13 15
	14 15

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// time : O(n+2m) or O(V+2E)
// space: n due to vis[] + n due to fn call stack ~ O(n) or O(V)

void dfs(int cur,
         vector<bool>& vis,
         const vector<vector<int>>& adj) {

	vis[cur] = true;
	cout << cur << " ";

	for (int ngb : adj[cur]) {
		if (!vis[ngb]) {
			dfs(ngb, vis, adj);
		}
	}

}

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<bool> vis(n, false);
	int numComponents = 0;

	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			// make node i as source
			// and traverse the component of
			// node i using dfs or bfs
			cout << "dfs(" << i << ") : ";
			dfs(i, vis, adj);
			cout << endl;
			numComponents++;
		}
	}

	cout << numComponents << endl;

	return 0;
}
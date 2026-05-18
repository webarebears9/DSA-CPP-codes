/*

Given an undirected graph, check if there exists a cycle or not.

	e.g.

	3 3

	0 1
	0 2
	1 2

*/

#include<iostream>
#include<vector>

using namespace std;

bool dfs(int cur,
         int par,
         vector<bool>& vis,
         const vector<vector<int>>& adj) {


	vis[cur] = true;
	for (int ngb : adj[cur]) {
		if (!vis[ngb]) {
			// ngb is not visited
			if (dfs(ngb, cur, vis, adj)) {
				// we've found a cycle in the subcomponent of
				// cur hence we have found a cycle in the component
				// of cur
				return true;
			}
		} else {
			// ngb is already visited

			// check if the edge b/w cur and ngb is a
			// backedge or not
			if (ngb != par) {
				// the edge between cur and ngb is a backedge
				// hence we've found a cycle in the component
				// of cur
				return true;
			}
		}
	}

	return false; // no cycle found in the component of cur

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

	bool flag = false; // assume graph has no cycle

	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			// check if a cycle is present in the
			// component of node i using
			if (dfs(i, -1, vis, adj)) {
				flag = true;
				break;
			}
		}
	}

	if (flag) {
		cout << "cycle found" << endl;
	} else {
		cout << "no cycle found" << endl;
	}

	return 0;
}
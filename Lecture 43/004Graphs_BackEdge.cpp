/*

Given an directed graph, check if there exists a back-edge or not.

	e.g.

	4 4

	0 1
	1 2
	2 3
	3 0

*/

#include<iostream>
#include<vector>

using namespace std;

bool dfs(int cur,
         vector<bool>& vis,
         vector<bool>& stackState,
         const vector<vector<int>>& adj) {

	vis[cur] = true;
	stackState[cur] = true;

	for (int ngb : adj[cur]) {
		if (!vis[ngb]) {
			// ngb is not visited
			if (dfs(ngb, vis, stackState, adj)) {
				// cycle found in the subcomponent of ngb
				// hence cyle found in the component of cur
				return true;
			}
		} else {
			// ngb is visited, check if edge from cur to ngb is backedge
			if (stackState[ngb]) {
				// since ngb is on the fn call stack while we are at cur
				// it means there is dir. path from ngb to cur
				// hence edge from cur to ngb is a backedge
				// therefore we've found a cycle in the component
				// of cur
				return true;
			}
		}
	}

	stackState[cur] = false;
	return false;

}

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	vector<bool> vis(n, false);
	vector<bool> stackState(n, false);

	bool flag = false; // assume no directed cycle in the graph

	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			// check if a directed cycle is present in the
			// component of node i
			if (dfs(i, vis, stackState, adj)) {
				flag = true; // cycle found in component of node i hence cycle
				// found in the graph
				break;
			}
		}
	}

	if (flag) {
		cout << "cycle found" << endl;
	} else {
		cout << "cycle not found" << endl;
	}

	return 0;

}
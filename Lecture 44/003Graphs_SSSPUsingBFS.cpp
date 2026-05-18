/*

Computing SSSP using the BFS algorithm in an unweighted graph.

note : each vertex in the graph is an integer in the range [0, n-1].

e.g.

9 12

0  1
0  2
1  3
1  4
2  4
2  5
3  6
4  6
4  7
5  7
6  8
7  8

*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

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

	int s = 0; // source node

	queue<int> q;
	q.push(s);

	vector<int> distMap(n);
	distMap[s] = 0;

	vector<int> parMap(n);
	parMap[s] = -1;

	vector<bool> vis(n);
	vis[s] = true;

	while (!q.empty()) {

		int cur = q.front(); q.pop();
		for (int ngb : adj[cur]) {
			if (!vis[ngb]) {
				vis[ngb] = true;
				q.push(ngb);
				distMap[ngb] = 1 + distMap[cur];
				parMap[ngb] = cur;
			}
		}

	}

	for (int i = 0; i < n; i++) {
		cout << "dist(" << i << ") = " << distMap[i] << endl;
	}

	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << "par(" << i << ") = " << parMap[i] << endl;
	}

	cout << endl;

	int dst = 8;

	vector<int> path = {dst};

	while (parMap[dst] != -1) {
		dst = parMap[dst];
		path.push_back(dst);
	}

	reverse(path.begin(), path.end());

	for (int x : path) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector < vector<pair<int, int>>> adj(n);

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w}); // adj[u].push_back(make_pair(v, w));
		adj[v].push_back({u, w}); // comment this out if the graph is directed
	}

	for (int i = 0; i < n; i++) {

		cout << "ngb(" << i << ") = ";
		for (pair<int, int> p : adj[i]) {
			int ngb = p.first;
			int edgeWt = p.second;
			cout << "(" << ngb << ", " << edgeWt << ") ";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << "ngb(" << i << ") = ";
		for (auto [ngb, edgeWt] : adj[i]) {
			cout << "(" << ngb << ", " << edgeWt << ") ";
		}
		cout << endl;
	}


	return 0;
}
#include<vector>
#include<iostream>

using namespace std;

int main() {

	// vector<vector<int>> v; // v is a 2d vector // v is a vector of vector<int>

	vector<vector<int>> v(3, vector<int>(4));

	int m = v.size(); // # rows
	int n = v[0].size(); // # cols

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	return 0;
}
#include<iostream>

using namespace std;

void wavePrint(int mat[][10], int m, int n) { // mat[][] is by default passed by reference

	for (int j = 0; j < n; j++) {

		if (j % 2 == 0) {

			// j is an even column

			for (int i = 0; i < m; i++) {
				cout << mat[i][j] << " ";
			}

		} else {

			// j is an odd column

			for (int i = m - 1; i >= 0; i--) {
				cout << mat[i][j] << " ";
			}

		}

	}

}

int main() {

	int mat[10][10];

	int m;
	cin >> m;

	int n;
	cin >> n;

	// read m x n values into the 2D array

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}

	wavePrint(mat, m, n);

	return 0;
}
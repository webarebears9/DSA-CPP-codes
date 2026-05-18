#include<iostream>
#include<cstring>

using namespace std;

int main() {

	int A[5] = {10, 20, 30, 40, 50};
	int n = 5;

	cout << A[0] << " ";
	cout << A[1] << " ";
	cout << A[2] << " ";
	cout << A[3] << " ";
	cout << A[4] << endl;

	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	for (int i = 0; i <= n - 1; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	int B[] = {100, 200, 300}; // during init, specifying size of the array is optional
	int m = sizeof(B) / sizeof(int);

	for (int i = 0; i < m; i++) {
		cout << B[i] << " ";
	}

	cout << endl;

	int C[10] = {};

	for (int i = 0; i < 10; i++) {
		cout << C[i] << " ";
	}

	cout << endl;

	int D[10] = {0};

	for (int i = 0; i < 10; i++) {
		cout << D[i] << " ";
	}

	cout << endl;

	int E[10];

	memset(E, 0, sizeof(E));

	for (int i = 0; i < 10; i++) {
		cout << E[i] << " ";
	}

	cout << endl;

	int F[10];

	memset(F, -1, sizeof(F));

	for (int i = 0; i < 10; i++) {
		cout << F[i] << " ";
	}

	cout << endl;

	int G[10];

	memset(G, 2, sizeof(G));

	for (int i = 0; i < 10; i++) {
		cout << G[i] << " ";
	}

	cout << endl;

	return 0;
}
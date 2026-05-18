#include<iostream>

using namespace std;

bool f(int X[], int n, int i) {

	// base case

	if (i == n - 1) {
		// f(n-1) : it is a fn that check if X[n-1...n-1] is sorted or not
		return true;
	}

	// recursive case

	// f(i) : it is a fn that checks if the suffix of X[] that starts
	// at the ith index i.e. X[i...n-1] is sorted or not

	return X[i] < X[i + 1] and f(X, n, i + 1);

}

int main() {

	int X[] = {10, 20, 30, 40, 50};
	int n = sizeof(X) / sizeof(int);

	f(X, n, 0) ? cout << "sorted" << endl : cout << "not sorted" << endl;

	return 0;
}
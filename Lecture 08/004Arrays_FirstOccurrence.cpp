// n <= 100

#include<iostream>

using namespace std;

int main() {

	int n, t;
	cin >> n >> t;

	int arr[100]; // based on constraints
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// time : O(n)

	int i;

	for (i = 0; i < n; i++) {
		if (arr[i] == t) {
			// you've found the target at index i
			cout << i << endl;
			break;
		}
	}

	if (i == n) {
		// target is not present in arr[]
		cout << -1 << endl;
	}

	return 0;
}
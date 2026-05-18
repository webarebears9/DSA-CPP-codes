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

	bool flag = false; // assume t is not present in arr[]

	for (int i = 0; i < n; i++) {
		if (arr[i] == t) {
			// you've found an occ. of 't' at index i
			cout << i << " ";
			flag = true;
		}
	}

	if (flag == false) {
		cout << -1 << endl;
	}

	return 0;
}
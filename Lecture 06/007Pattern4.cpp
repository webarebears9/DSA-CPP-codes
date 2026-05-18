#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		// for the ith row, print i nos.

		int num;
		if (i % 2 == 0) {
			// ith row is even
			num = 0;
		} else {
			// ith row is odd
			num = 1;
		}

		for (int j = 1; j <= i; j++) {
			cout << num << " ";
			if (num == 0) {
				num = 1;
			} else {
				num = 0;
			}
		}

		cout << endl;

	}

	return 0;
}
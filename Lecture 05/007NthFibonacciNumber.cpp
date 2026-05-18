#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	if (n == 0 || n == 1) {
		cout << n << endl;
	} else {
		// n >= 2
		int a = 0; // 0th fib. no.
		int b = 1; // 1st fib. no.

		int i = 1;
		int c;

		while (i <= n - 1) {
			c = a + b;
			a = b;
			b = c;
			i = i + 1;
		}

		cout << c << endl;

	}

	return 0;
}
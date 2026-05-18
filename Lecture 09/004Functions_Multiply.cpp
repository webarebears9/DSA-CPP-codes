#include<iostream>

using namespace std;

int multiply(int x, int y) {
	int z = x * y;
	return z;
}

int main() {

	cout << multiply(2, 3) << endl;

	cout << multiply(4, 5) * 10 << endl;

	int ans = multiply(3, 5) * 5 - 10;

	cout << ans << endl;

	return 0;
}
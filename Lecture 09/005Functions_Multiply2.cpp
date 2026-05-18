#include<iostream>

using namespace std;

int multiply(int x, int y) {
	int z = x * y;
	return z;
}

int main() {

	int x = 5;
	int y = 6;

	cout << multiply(x, y) << endl;

	return 0;
}
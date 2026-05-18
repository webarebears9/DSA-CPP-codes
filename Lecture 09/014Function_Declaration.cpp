#include<iostream>

using namespace std;

int multiply(int x, int y); // function declaration // function prototype

int main() {

	cout << multiply(2, 3) << endl;

	return 0;
}

int multiply(int x, int y) {
	return x * y;
}
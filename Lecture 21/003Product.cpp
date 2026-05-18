#include<iostream>

using namespace std;

int f(int x, int y) {

	// base case

	if (y == 0) {
		// f(x, 0) : it is a fn that multples x with 0
		return 0;
	}

	// recursive case

	// f(x, y) : it is a fn that adds 'x' 'y' times

	// or

	// f(x, y) : it is a fn that multiples x with y

	// 1. ask your friend to multiply x with y-1

	int A = f(x, y - 1);

	// 2. use the result from your friend to solve the given problem

	return x + A;

}

int main() {

	int x = 3;
	int y = 4;

	cout << f(x, y) << endl;

	return 0;
}
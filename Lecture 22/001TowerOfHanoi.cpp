#include<iostream>

using namespace std;

// for n disks there will pow(2, n) - 1 moves
// time : O(2^n)

void f(int n, char src, char dst, char hlp) {

	// base case

	if (n == 0) {
		// f(0)
		return;
	}

	// recursive case

	// f(n) : move n disks from src (A) to dst (C) using hlp(B)

	// 1. ask your friend to move n - 1 disks from src (A) to hlp (B) using dst (C)

	f(n - 1, src, hlp, dst);

	// 2. move the largest disk from src (A) to dst (C)

	cout << "move disk from " << src << " to " << dst << endl;

	// 3. ask your friend to move n - 1 disks from hlp (B) to dst (C) using src (A)

	f(n - 1, hlp, dst, src);

}

int main() {

	int n = 5;

	f(n, 'A', 'C', 'B');

	return 0;
}
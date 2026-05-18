#include<iostream>

using namespace std;

int main() {

	const int y = 10;
	cout << y << endl;
	// y++; // error : y is read-only

	// const int z; // error : const var. must be initialized
	// z = 10;

	return 0;
}
#include<iostream>

using namespace std;

bool isEven(int n) {
	return n % 2 == 0;
}

int main() {

	// if a function call returns a value
	// treat that function call like an
	// expression

	bool ans;

	ans = isEven(4);

	cout << ans << endl;

	cout << isEven(5) << endl;

	if (isEven(7)) {
		cout << "even" << endl;
	} else {
		cout << "odd" << endl;
	}

	if (isEven(6)) {
		cout << "even" << endl;
	} else {
		cout << "odd" << endl;
	}

	isEven(5) ? cout << "even" << endl : cout << "odd" << endl;
	isEven(8) ? cout << "even" << endl : cout << "odd" << endl;

	return 0;
}
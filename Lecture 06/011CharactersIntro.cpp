#include<iostream>

using namespace std;

int main() {

	char ch = 'A';

	cout << ch << endl;
	cout << (int)ch << endl;

	ch = 'z';

	cout << ch << endl;
	cout << (int)ch << endl;

	ch = 90; // implicite type-casting

	cout << ch << endl;

	int x = 'A'; // implicit type-casting

	cout << x << endl;

	ch = '0';

	cout << (int)ch << endl;

	ch = '9';

	cout << (int)ch << endl;

	return 0;
}
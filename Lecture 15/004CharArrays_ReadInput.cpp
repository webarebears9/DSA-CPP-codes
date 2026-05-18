// n <= 100

#include<iostream>

using namespace std;

int main() {

	char str[101]; // based on constraints

	cin >> str; // cin >> automatically adds '\0' to the end of the input

	// cin >> ignores leading whitespaces but
	// stops reading as soon as it encounters
	// a non-leading whitespace

	cout << str << endl;

	return 0;
}
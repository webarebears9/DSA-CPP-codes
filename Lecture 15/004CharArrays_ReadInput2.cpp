// n <= 100

#include<iostream>

using namespace std;

int main() {

	char str[101]; // based on constraints

	cin.getline(str, 101);

	// by default cin.getline() stops reading as soon as it encounters
	// a newline character i.e. '\n'

	cout << str << endl;

	return 0;
}
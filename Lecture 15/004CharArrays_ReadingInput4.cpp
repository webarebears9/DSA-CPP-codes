// n <= 100

#include<iostream>

using namespace std;

int main() {

	char str[101]; // based on constraints

	cin.getline(str, 101);

	// cin.getline() doesn't ignore leading whitespaces

	cout << str << endl;

	return 0;
}
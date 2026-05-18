#include<iostream>
#include<string>

using namespace std;

int main() {

	string str;
	getline(cin, str, '$');

	// getline(...) stops reading as soon as
	// it encounters '$'

	cout << str << endl;

	return 0;
}
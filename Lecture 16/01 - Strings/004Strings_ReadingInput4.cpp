#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int main() {

	string str;
	getline(cin >> ws, str);

	// cin >> ws is an input manip. that
	// helps to ignore leading whitespaces

	cout << str << endl;

	return 0;
}
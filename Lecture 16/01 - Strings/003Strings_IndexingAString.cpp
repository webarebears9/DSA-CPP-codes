#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "coding";

	cout << s[0] << endl;
	cout << s[1] << endl;

	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << endl;
	}

	return 0;
}
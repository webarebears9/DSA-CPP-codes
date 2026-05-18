#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "abc";
	string t = "def";

	// s.append(t);

	// cout << s << endl;
	// cout << t << endl;

	s = s + t;

	cout << s << endl;

	return 0;
}
#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "abcabcabc";
	string t = "bca";

	cout << s.find(t) << endl;
	cout << s.rfind(t) << endl;

	string w = "zzz";

	cout << s.find(w) << endl;
	cout << (s.find(w) == -1) << endl;

	cout << string::npos << endl;

	return 0;
}
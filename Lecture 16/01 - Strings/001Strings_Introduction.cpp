#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {

	string s1;
	s1 = "hello";
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.length() << endl;

	string s2 = "coding";
	cout << s2 << endl;
	cout << s2.size() << endl;
	cout << s2[0] << " " << s2.front()  << endl;
	cout << s2[s2.size() - 1] << " " << s2.back() << endl;

	string s3 = "putin";
	for (int i = 0; i < s3.size(); i++) {
		cout << s3[i] << " ";
	}
	cout << endl;

	for (int i = 0; s3[i] != '\0'; i++) {
		cout << s3[i] << " ";
	}
	cout << endl;

	for (char ch : s3) { // here char of s3 are copied into ch
		cout << ch << " ";
	}
	cout << endl;

	for (char& ch : s3) { // here ch is ref. to char of s3
		cout << ch << " ";
	}
	cout << endl;

	vector<string> v;

	v.push_back("putin");
	v.push_back("modi");
	v.push_back("trump");
	v.push_back("xi");

	for (string name : v) {
		cout << name << endl;
		// name[0] = 'y';
	}

	for (string& name : v) {
		cout << name << endl;
		// name[0] = 'y';
	}

	for (string name : v) {
		cout << name << endl;
	}

	return 0;
}
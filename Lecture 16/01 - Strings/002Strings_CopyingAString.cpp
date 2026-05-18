#include<iostream>
#include<string>

using namespace std;

int main() {

	string s1 = "coding";
	cout << s1 << endl;

	string s2 = s1; // copy constructor
	cout << s2 << endl;

	string s4(s1); // copy constructor // we are creating s4 as a copy of s1
	cout << s4 << endl;

	string s3;
	s3 = s1; // copy assignment operator
	cout << s3 << endl;

	return 0;
}
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {

	string s = "state";

	sort(s.begin(), s.end()); // by default, sort(...) sorts the string in inc. order

	cout << s << endl;

	// sort(s.rbegin(), s.rend());
	sort(s.begin(), s.end(), greater<char>());

	cout << s << endl;

	return 0;
}
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {

	string s = "coding";

	reverse(s.begin(), s.end());

	cout << s << endl;

	string t = "delhi";

	reverse(t.begin() + 1, t.begin() + 4); // [1, 4)

	cout << t << endl;

	return 0;
}
#include<iostream>
#include<string>

using namespace std;

int main() {

	// all the relational operators work b/w string objs.

	string s = "zzz";
	string t = "zxz";

	if (s > t) {
		cout << s << " > " << t << endl;
	} else if (s < t) {
		cout << s << " < " << t << endl;
	} else {
		cout << s << " is equal to " << t << endl;
	}

	return 0;
}
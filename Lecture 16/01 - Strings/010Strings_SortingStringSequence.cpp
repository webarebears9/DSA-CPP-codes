#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

// return true if you want a to be ordered before
// otherwise return false

bool lenCmp(string a, string b) {

	// if (a.size() < b.size()) {

	// 	// since we are sorting in inc. order
	// 	// based on len when a.size() is < b.size()
	// 	// we want a to be ordered before b

	// 	return true;

	// }

	// return false;

	return a.size() < b.size();

}

int main() {

	vector<string> v;

	v.push_back("putin");
	v.push_back("modi");
	v.push_back("xi");
	v.push_back("macron");
	v.push_back("kim");

	// sort(v.begin(), v.end()); // sorting done in lexicographically inc. order

	// sort(v.rbegin(), v.rend()); // sorting done in lexicographically dec. order

	// sort(v.begin(), v.end(), greater<string>()); // sorting done in lexicographically dec. order

	sort(v.begin(), v.end(), lenCmp);

	for (string s : v) {
		cout << s << endl;
	}

	return 0;
}
#include<iostream>
#include<string>

using namespace std;

// for a string of size n, it will n(n+1)/2 ~ n^2 substrings
// time : O(n^3)

void generateSubstrings(const string& str) { // here str is passed by const ref to we avoid copy + we make str cannot be modified within this fn

	int n = str.size();
	for (int i = 0; i <= n - 1; i++) {
		for (int j = i; j <= n - 1; j++) {
			// generate the substring that starts
			// at the ith index and ends at the
			// jth index

			// for (int k = i; k <= j; k++) {
			// 	cout << str[k];
			// }
			// cout << endl;

			cout << str.substr(i, j - i + 1) << endl;

		}
		cout << endl;
	}

}

int main() {

	string str = "abcde";

	generateSubstrings(str);

	return 0;
}
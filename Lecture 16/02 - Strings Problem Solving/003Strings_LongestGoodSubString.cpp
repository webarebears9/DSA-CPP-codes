#include<iostream>
#include<string>

using namespace std;

bool isGoodString(const string& str) {

	for (char ch : str) {

		if (!(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u')) {

			// ch is a consonant
			return false;

		}

	}

	return true; // str is a good string

}


// time : O(n^3) since for each of the ~n^2 substrings we spend linear time ~ 2n
int longestGoodSubstring(const string& str) {

	int maxSoFar = 0;
	int n = str.size();

	for (int i = 0; i <= n - 1; i++) {
		for (int j = i; j <= n - 1; j++) {

			string substring = str.substr(i, j - i + 1);

			if (isGoodString(substring)) {
				maxSoFar = max(maxSoFar, j - i + 1);
			}
		}
	}

	return maxSoFar;

}

int main() {

	string str = "cbaeicdeiou";

	cout << longestGoodSubstring(str) << endl;

	return 0;
}
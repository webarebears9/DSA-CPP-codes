#include<iostream>
#include<vector>
#include<set>

using namespace std;

// time : O(nlogn)
// space: O(26) due to set<>

int lengthOfLongestPalindrome(const string& str) {
	set<char> s;
	int cnt = 0;
	for (char ch : str) {
		if (s.find(ch) == s.end()) {
			// ch is not present
			s.insert(ch);
		} else {
			// ch is present
			cnt += 2;
			s.erase(ch);
		}
	}

	if (!s.empty()) {
		cnt++;
	}

	return cnt;
}

int main() {

	string str = "aabbbbbac";

	cout << lengthOfLongestPalindrome(str) << endl;

	return 0;
}
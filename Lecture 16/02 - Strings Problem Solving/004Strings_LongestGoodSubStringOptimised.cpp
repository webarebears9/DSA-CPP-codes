#include<iostream>
#include<string>

using namespace std;

int main() {

	string str = "cbaeicdeiou";

	int cnt = 0; // to track the length of the longest good substring

	int maxSoFar = 0;

	// time : O(n) space : O(1)
	// [HW] try to construct the longest good substring as well

	for (char ch : str) {
		if (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u') {
			cnt++;
			maxSoFar = max(maxSoFar, cnt);
		} else {
			cnt = 0;
		}
	}

	cout << maxSoFar << endl;
	return 0;
}
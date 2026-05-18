#include<iostream>
#include<queue>

using namespace std;

int main() {

	char ch;
	queue<char> q;
	int freq[26] = {0};

	// time : O(n) where steram size is n
	// space: n due to queue esp. when stream has distinct elements + 26 due to freq ~ O(n)

	while (true) {

		cin >> ch;
		if (ch == '.') break;

		freq[ch - 'a']++;
		if (freq[ch - 'a'] == 1) {
			q.push(ch);
		}

		while (!q.empty() and freq[q.front() - 'a'] > 1) {
			q.pop();
		}

		if (q.empty()) {
			// after reading ch there is no non-repeating
			// char in the stream
			cout << -1 << " ";
		} else {
			cout << q.front() << " ";
		}

	}

	return 0;
}
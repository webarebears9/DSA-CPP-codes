/*

Given two strings s1 and s2, return the length of their longest common subsequence.
If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters
(can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example :

	Input : s1 = "ATGC", s2 = "AGCT"
	Output: 3
	Explanation : "AGC" is the LCS between s1 and s2

	Input : s1 = "AGGTAB", s2 = "GXTXAYB"
	Output: 4
	Explanation : “GTAB” is the LCS between s1 and s2

*/

#include<iostream>
#include<vector>

using namespace std;

// time : O(2^(m+n))
// space: O(m+n) due to fn call stack

int f(const string& s1, const string& s2, int m, int n, int i, int j) {

	// base case

	if (i == m || j == n) {

		// f(m, j) = find the length of the lcs b/w s1[m...m-1] i.e. "" and s2[j...n-1]

		// f(i, n) = find the length of the lcs b/w s1[i...m-1] and s2[n...n-1] i.e. ""

		return 0;
	}

	// recursive case

	// f(i, j) = find the length of the lcs b/w s1[i...m-1] and s2[j...n-1]

	if (s1[i] == s2[j]) {

		// ask your friend to find the length of the lcs b/w s1[i+1...m-1] and s2[j+1...n-1]

		return 1 + f(s1, s2, m, n, i + 1, j + 1);

	}

	// ask your friend to find the length of the lcs b/w s1[i...m-1] and s2[j+1...n-1]
	// ask your friend to find the length of the lcs b/w s1[i+1...m-1] and s2[j...n-1]

	return max(f(s1, s2, m, n, i, j + 1),
	           f(s1, s2, m, n, i + 1, j));


}

// time : O(mn)
// space: (m+n) due to fn call stack + mn due dp[][] ~ O(mn)

int fTopdown(const string& s1, const string& s2, int m, int n, int i, int j, vector<vector<int>>& dp) {

	// lookup

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	// base case

	if (i == m || j == n) {

		// f(m, j) = find the length of the lcs b/w s1[m...m-1] i.e. "" and s2[j...n-1]

		// f(i, n) = find the length of the lcs b/w s1[i...m-1] and s2[n...n-1] i.e. ""

		return dp[i][j] = 0;
	}

	// recursive case

	// f(i, j) = find the length of the lcs b/w s1[i...m-1] and s2[j...n-1]

	if (s1[i] == s2[j]) {

		// ask your friend to find the length of the lcs b/w s1[i+1...m-1] and s2[j+1...n-1]

		return dp[i][j] = 1 + fTopdown(s1, s2, m, n, i + 1, j + 1, dp);

	}

	// ask your friend to find the length of the lcs b/w s1[i...m-1] and s2[j+1...n-1]
	// ask your friend to find the length of the lcs b/w s1[i+1...m-1] and s2[j...n-1]

	return dp[i][j] = max(fTopdown(s1, s2, m, n, i, j + 1, dp),
	                      fTopdown(s1, s2, m, n, i + 1, j, dp));


}

// time : O(mn)
// space: O(mn) due to dp[][]

int fBottomUp(const string& s1, const string& s2, int m, int n) {

	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // 0-init make sures that cells corr. to the base are filled automatically

	for (int i = m - 1; i >= 0; i--) {

		for (int j = n - 1; j >= 0; j--) {

			// dp[i][j] = f(i, j) = find the length of the lcs b/w s1[i...m-1] and s2[j...n-1]

			if (s1[i] == s2[j]) {

				dp[i][j] = 1 + dp[i + 1][j + 1];

			} else {

				dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);

			}

		}

	}

	// for (int i = 0; i <= m; i++) {
	// 	for (int j = 0; j <= n; j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	// cout << endl;

	string ans = "";

	int x = 0;
	int y = 0;

	while (!(x == m or y == n)) {

		if (s1[x] == s2[y]) {

			ans += s1[x];
			x++; y++;

		} else if (dp[x][y] == dp[x][y + 1]) {

			y++;

		} else {

			x++;

		}

	}

	cout << ans << endl;

	return dp[0][0]; // at the 0,0th index of dp[][] we store f(0, 0)

}

// time : O(mn)
// space: O(n) due to cur[] and nxt[]

int fBottomUpSpaceOptimised(const string& s1, const string& s2,
                            int m, int n) {

	vector<int> nxt(n + 1, 0); // init nxt[] represent mth row of dp[][]

	for (int i = m - 1; i >= 0; i--) {

		vector<int> cur(n + 1, 0);

		for (int j = n - 1; j >= 0; j--) {

			if (s1[i] == s2[j]) {

				cur[j] = 1 + nxt[j + 1];

			} else {

				cur[j] = max(cur[j + 1], nxt[j]);

			}

		}

		nxt = cur;

	}

	return nxt[0]; // at this of time nxt[] represents 0th row of dp[][]
	// hence nxt[0] is dp[0][0]

}

int main() {

	string s1("HAMZA");
	string s2("REHMAN");

	int m = s1.size();
	int n = s2.size();

	cout << f(s1, s2, m, n, 0, 0) << endl;

	vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

	cout << fTopdown(s1, s2, m, n, 0, 0, dp) << endl;

	cout << fBottomUp(s1, s2, m, n) << endl;

	cout << fBottomUpSpaceOptimised(s1, s2, m, n) << endl;

	return 0;
}
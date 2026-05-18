// https://leetcode.com/problems/partition-array-for-maximum-sum/

class Solution {
public:

	int f(const vector<int>& arr, int n, int k, int i) {

		// base case

		if (i == n) {
			return 0;
		}

		// recursive case

		// f(i) : find the max. sum we can get by paritioning arr[i...n-1]

		int maxSoFar = 0;
		int maxViToj = 0;

		for (int j = i; j < i + k and j < n; j++) {

			// make a cut at index j and then ask your friend
			// to find the max. sum we can get by paritioning arr[j+1...n-1]

			maxViToj = max(maxViToj, arr[j]);
			maxSoFar = max(maxSoFar, (j - i + 1) * maxViToj + f(arr, n, k, j + 1));

		}

		return maxSoFar;

	}

	// time : O(nk)
	// space: n due to fn call stack + n due to dp[] ~ O(n)

	int fTopdown(const vector<int>& arr, int n, int k, int i, vector<int>& dp) {

		// lookup
		if (dp[i] != -1) {
			return dp[i];
		}

		// base case

		if (i == n) {
			return dp[i] = 0;
		}

		// recursive case

		// f(i) : find the max. sum we can get by paritioning arr[i...n-1]

		int maxSoFar = 0;
		int maxViToj = 0;

		for (int j = i; j < i + k and j < n; j++) {

			// make a cut at index j and then ask your friend
			// to find the max. sum we can get by paritioning arr[j+1...n-1]

			maxViToj = max(maxViToj, arr[j]);
			maxSoFar = max(maxSoFar, (j - i + 1) * maxViToj + fTopdown(arr, n, k, j + 1, dp));

		}

		return dp[i] = maxSoFar;

	}

	int maxSumAfterPartitioning(vector<int>& arr, int k) {

		int n = arr.size();
		// return f(arr, n, k, 0);

		vector<int> dp(n + 1, -1);
		return fTopdown(arr, n, k, 0, dp);

	}
};

// https://leetcode.com/problems/trapping-rain-water/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

	// time : 2n ~ O(n)
	// space: n due to r[] = n ~ O(n)

	int trap(vector<int>& height) {

		int n = height.size();

		// 1. precompute r[]

		vector<int> r(n);
		r[n - 1] = height[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			r[i] = max(r[i + 1], height[i]);
		}

		// 2. solve the given problem

		int total = 0;
		int maxSoFar = 0; // INT_MIN // height[0] // maxSoFar represents max of 0 to i i.e. li

		for (int i = 0; i < n; i++) {

			// find out the water trapped on top of the ith building

			maxSoFar = max(maxSoFar, height[i]); // holds the max(0 to i)
			int wi = min(maxSoFar, r[i]) - height[i];
			total += wi;

		}

		return total;

	}
};

int main() {

	vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

	Solution s;
	cout << s.trap(height) << endl;

	return 0;

}
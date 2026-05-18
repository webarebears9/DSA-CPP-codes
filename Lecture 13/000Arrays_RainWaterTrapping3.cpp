
// https://leetcode.com/problems/trapping-rain-water/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

	// time : n ~ O(n)
	// space: O(1)

	int trap(vector<int>& height) {

		int n = height.size();

		int i = 0;
		int j = n - 1;

		int total = 0; // to track the total water trapped b/w buildings

		int l = 0; // max(height[0...i]) // INT_MIN // height[0]
		int r = 0; // max(height[j...n-1]) // INT_MIN // height[n-1]

		while (i <= j) {

			l = max(l, height[i]);
			r = max(r, height[j]);

			if (l < r) {
				int wi = l - height[i];
				total += wi;
				i++;
			} else {
				int wj = r - height[j];
				total += wj;
				j--;
			}

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
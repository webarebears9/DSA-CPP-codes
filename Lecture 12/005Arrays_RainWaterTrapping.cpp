
// https://leetcode.com/problems/trapping-rain-water/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public :

	// time : O(n^2)
	// space : O(1)

	int trap(vector<int>& height) {

		int total = 0;

		int n = height.size();

		for (int i = 0; i < n; i++) {

			// find out the water trapped on top of the ith building

			int li = height[i]; // max(height[0...i])

			for (int j = i - 1; j >= 0; j--) {
				li = max(li, height[j]);
			}

			int ri = height[i]; // max(height[i...n-1])

			for (int j = i + 1; j < n; j++) {
				ri = max(ri, height[j]);
			}

			int wi = min(li, ri) - height[i];
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
// https://leetcode.com/problems/find-the-duplicate-number/description/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

	// time : O(n)
	// space: O(1) but we've modified the array

	int findDuplicate(vector<int>& nums) {

		int slow = nums[0];
		int fast = nums[0];

		while (true) {

			slow = nums[slow];
			fast = nums[nums[fast]];
			if (slow == fast) {
				break;
			}

		}

		// slow and fast are at the meeting point

		slow = nums[0];

		while (slow != fast) {
			slow = nums[slow];
			fast = nums[fast];
		}

		// slow and fast are at the start of the cycle

		return slow; // return fast

	}

};

int main() {

	vector<int> nums = {1, 3, 4, 2, 2};

	Solution s;
	cout << s.findDuplicate(nums) << endl;

	return 0;

}
#include<iostream>
#include<climits>

using namespace std;

// time : O(n^3)
// space: O(1)

int maximumSubarraySum(int arr[], int n) {

	int maxSofar = INT_MIN; // to track the maximum subarray sum

	for (int i = 0; i <= n - 1; i++) {
		for (int j = i; j <= n - 1; j++) {
			// find the sum of the subarray that
			// starts at the ith index and ends
			// at the jth index

			int sum = 0; // to track the sum of the subarray arr[i...j]
			for (int k = i; k <= j; k++) {
				sum += arr[k];
			}

			maxSofar = max(maxSofar, sum);
		}
	}

	return maxSofar;

}

int main() {

	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	cout << maximumSubarraySum(arr, n) << endl;

	return 0;
}
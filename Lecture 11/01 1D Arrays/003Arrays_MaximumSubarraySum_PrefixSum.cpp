// constraints : n <= 100

#include<iostream>
#include<climits>

using namespace std;

int main() {

	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	// 1. precompute prefix sums // time : O(n)

	int psum[100]; // based on constraints

	psum[0] = arr[0];
	for (int i = 1; i < n; i++) {
		psum[i] = psum[i - 1] + arr[i];
	}

	// 2. find the maximum subarray sum // time : O(n^2)

	int maxSoFar = INT_MIN;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			// find the sum of the subarray that starts
			// at the ith index and ends at the jth index
			int sum = i == 0 ? psum[j] : psum[j] - psum[i - 1];
			maxSoFar = max(maxSoFar, sum);
		}
	}

	cout << maxSoFar << endl;

	// total time : n + n^2  ~ O(n^2)
	// total space: O(n) due psum[]


	return 0;
}
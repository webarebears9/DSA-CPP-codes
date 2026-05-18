#include<iostream>

using namespace std;

// time : O(logn)

int lowerBound(int arr[], int n, int t) {

	int s = 0;
	int e = n - 1;

	int ans = -1;

	while (s <= e) {
		// int m = (s + e) / 2; // this can cause integer overflow
		int m = s + (e - s) / 2;
		if (arr[m] == t) {
			// you've found the target at index 'm' so save it and move towards left of the mid-point i.e. reduce the search space from [s, e] to [s, m-1]
			ans = m;
			e = m - 1;
		} else {
			if (t > arr[m]) {
				// reduce the search space from [s, e] to [m+1, e]
				s = m + 1;
			} else {
				// t < arr[m]
				// reduce the search space from [s, e] to [s, m-1]
				e = m - 1;
			}
		}
	}

	return ans;

}

int main() {

	int arr[] = {10, 20, 30, 30, 30, 30, 30, 40, 40, 40, 70};
	int n = sizeof(arr) / sizeof(int);

	int t = 100;

	cout << lowerBound(arr, n, t) << endl;

	return 0;
}
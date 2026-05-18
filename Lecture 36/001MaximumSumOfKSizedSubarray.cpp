#include<iostream>

using namespace std;

int main() {

	int arr[] = {1, 4, 2, 7, 6, 3, 5};
	int n = sizeof(arr) / sizeof(int);
	int k = 4;

	int i = 0; // to store the start of the window
	int j = 0; // to store the end of the window

	int wSum = 0; // to store the window sum
	int maxSumSoFar;   // to track the maximum window sum

	// compute the sum of 1st window

	while (j < k) { // time : k.const
		wSum += arr[j];
		j++;
	}

	maxSumSoFar = wSum;

	// compute the sum for the remaining windows

	while (j < n) { // time : (n-k).const

		// slide the window
		wSum -= arr[i]; i++;
		wSum += arr[j];

		// update the answer using sum of current window
		maxSumSoFar = max(maxSumSoFar, wSum);

		j++;

	}

	cout << maxSumSoFar << endl;

	// time : k.c + (n-k).c ~ O(n) space : O(1)

	return 0;
}


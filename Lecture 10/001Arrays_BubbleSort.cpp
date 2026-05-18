#include<iostream>

using namespace std;

// time : O(n^2) worst case e.g. 50 40 30 20 10
// time : O(n) best case e.g. 10 20 30 40 50

void bubbleSort(int arr[], int n) {

	int cnt = 0; // to count no. of comparisions

	for (int i = 1; i <= n - 1; i++) {

		// in the ith pass, place the largest value in
		// the unsorted part of the arr[] to its corr.
		// position

		bool flag = false; // assume no swaps will be done in the ith pass

		for (int j = 0; j < n - i; j++) {

			cnt++;

			if (arr[j] > arr[j + 1]) {
				flag = true;
				swap(arr[j], arr[j + 1]);
			}

		}

		if (flag == false) {
			// no swaps were done in the ith pass, array is already sorted
			break;
		}

	}

	cout << "no. of comparisions = " << cnt << endl;

}

int main() {

	int arr[] = {50, 40, 30, 20, 10};
	int n = sizeof(arr) / sizeof(int);

	bubbleSort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}
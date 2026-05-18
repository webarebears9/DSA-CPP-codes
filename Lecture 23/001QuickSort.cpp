// constraints : n <= 100

#include<iostream>

using namespace std;

int partition(int arr[], int s, int e) {

	int pivot = arr[e];

	int i = s;
	int j = s;

	while (j < e) {

		if (arr[j] > pivot) {

			// put arr[j] in the right part

			j++;

		} else {

			// put arr[j] in the left part

			swap(arr[i], arr[j]);
			i++;
			j++;

		}

	}

	swap(arr[i], arr[e]);

	return i;

}

void quickSort(int arr[], int s, int e) {

	// base case

	if (s >= e) {
		return;
	}

	// recursive case

	// 1. partition the arr[s...e] around the pivot i.e. arr[e]

	int pidx = partition(arr, s, e);

	// 2. ask your friend to sort arr[s...pidx-1]

	quickSort(arr, s, pidx - 1);

	// 3. ask your friend to sort arr[pidx+1...e]

	quickSort(arr, pidx + 1, e);

}

int main() {

	int arr[] = {60, 50, 20, 10, 40, 30};
	int n = sizeof(arr) / sizeof(int);

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}
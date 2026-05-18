// constraints : n <= 100

#include<iostream>

using namespace std;

void merge(int arr[], int s, int m, int e) {

	// merge the two sorted subarrays arr[s...m] and arr[m+1...e]

	int temp[100]; // based on constraints

	int i = s; // to iterate arr[s...m]
	int j = m + 1; // to iterate over arr[m+1...e]
	int k = s; // to iterate over temp[s...e]

	while (i <= m and j <= e) {

		if (arr[i] <= arr[j]) {
			temp[k] = arr[i];
			i++;
			k++;
		} else {
			temp[k] = arr[j];
			j++;
			k++;
		}

	}

	while (i <= m) {
		temp[k] = arr[i];
		i++;
		k++;
	}

	while (j <= e) {
		temp[k] = arr[j];
		j++;
		k++;
	}

	// temp[s...e] is sorted

	// copy temp[s...e] to arr[s..e] to make sure arr[s...e] also becomes sorted

	for (int x = s; x <= e; x++) {
		arr[x] = temp[x];
	}

	// arr[s...e] is also sorted


}

void mergeSort(int arr[], int s, int e) {

	// base case

	if (s == e) {
		// f(s, s) : sort the arr[s..s] using merge sort algorithm
		return; // arr[s...s] is already sorted so just return
	}

	// recursive case

	// f(s, e) : sort the arr[s...e] using merge sort algorithm

	// 1. divide the arr[s..e] around the mid-point

	int m = s + (e - s) / 2;

	// 2. recursively sort the two subarrays arr[s...m] and arr[m+1...e]

	mergeSort(arr, s, m);
	mergeSort(arr, m + 1, e);

	// 3. merge the two sorted subarrays arr[s...m] and arr[m+1...e]
	// such that arr[s...e] becomes sorted

	merge(arr, s, m, e);

}

int main() {

	int arr[] = {50, 40, 30, 20, 10};
	int n = sizeof(arr) / sizeof(int);

	mergeSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}
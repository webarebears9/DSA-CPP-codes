#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int arr[] = {10, 10, 20, 30, 30, 30, 30, 30, 40, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	// arr[] should sorted to use the following functions

	int key = 50;

	// 1. searching for a key in a sorted sequence in O(logn) using binary_search()

	binary_search(arr, arr + n, key) ? cout << key << " found" << endl :
	                                        cout << key << " not found" << endl;

	// 2. finding lower bound for a key in a sorted sequence in O(logn) using lower_bound()

	// lower_bound of key is the first element not < the key

	// i.e. the first element >= the key

	key = 30;

	cout << "lower bound of " << key << " is present at index = "
	     << lower_bound(arr, arr + n, key) - arr << endl;

	// 3. finding upper bound for a key in a sorted sequence in O(logn) using upper_bound()

	// upper_bound of key is the first element > key

	cout << "upper bound of " << key << " is present at index = "
	     << upper_bound(arr, arr + n, key) - arr << endl;

	// 4. counting the occurences of a key in a sorted sequence in O(logn)

	cout << upper_bound(arr, arr + n, key) - lower_bound(arr, arr + n, key) << endl;

	return 0;
}
/*

e.g.

input
9
1 0 3 2 3 1 2 0 2
3

output
0 0 1 1 2 2 2 3 3

*/

#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> arr = {1, 0, 3, 2, 3, 1, 2, 0, 2};
	int n = arr.size();
	int k = 3;

	// 1. build a freqMap ~ linear

	vector<int> freq(k + 1, 0);

	for (int i = 0; i < n; i++) {
		int x = arr[i];
		freq[x]++;
	}

	// for(int i=0; i<n; i++) {
	// 	freq[arr[i]]++;
	// }

	// for(int x : arr) {
	// 	freq[x]++;
	// }

	// for (int i = 0; i <= k; i++) {
	// 	cout << "freq(" << i << ") = " << freq[i] << endl;
	// }

	// 2. build sorted array from freqMap ~ linear

	for (int i = 0; i <= k; i++) {

		// print i 'freq[i]' times

		for (int j = 1; j <= freq[i]; j++) {
			cout << i << " ";
		}

	}

	// total time : n + n ~ O(n)
	// total space : O(k) due to freq[]

	return 0;
}
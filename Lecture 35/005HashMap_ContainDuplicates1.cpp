#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

// time : O(nlogn)
// space: O(n) due to freqMap

bool isDuplicatePresent(const vector<int>& v) {
	map<int, int> freqMap;
	for (int x : v) {
		freqMap[x]++;
		if (freqMap[x] > 1) {
			return true;
		}
	}

	// for (pair<int, int> p : freqMap) {
	// 	int x = p.first;
	// 	int freq_x = p.second;
	// 	cout << x << " " << freq_x << endl;
	// }

	// cout << endl;

	// for (auto [x, freq_x] : freqMap) {
	// 	cout << x << " " << freq_x << endl;
	// }

	// cout << endl;

	// for (auto [x, freq_x] : freqMap) {
	// 	if (freq_x > 1) {
	// 		return true; // you've found duplicate
	// 	}
	// }

	// no duplicates found

	return false;


}

// time : O(nlogn)
// space: O(n) due to set<>

bool isDuplicatePresentUsingSet(const vector<int>& v) {

	set<int> s;
	for (int x : v) {
		if (s.find(x) == s.end()) {
			// x is not present
			s.insert(x);
		} else {
			// x is already present
			// duplicate found
			return true;
		}
	}

	// no duplicates found
	return false;

}

int main() {

	vector<int> v = {10, 10, 10, 20, 20, 20, 20, 30, 30};

	isDuplicatePresent(v) ? cout << "duplicate found" << endl :
	                             cout << "no duplicates found" << endl;


	isDuplicatePresentUsingSet(v) ? cout << "duplicate found" << endl :
	                                     cout << "no duplicates found" << endl;

	return 0;

}
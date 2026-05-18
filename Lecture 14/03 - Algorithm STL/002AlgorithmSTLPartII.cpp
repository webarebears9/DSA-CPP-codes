#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// return true if you want a to be ordered before b
// otherwise return false

bool lengthCmp(string a, string b) {
	if (a.size() < b.size()) {
		// since we are sorting the vec in inc. order based on length
		// when length of a is less than length of b, we want a to be
		// ordered before b in the sorted sequence therefore we are
		// return true
		return true;
	}

	return false;
}

// return true if you want a to be ordered before b otherwise return false

bool greaterCmp(int a, int b) {
	// if (a > b) {
	// 	// since we are sorting the arr in dec. order therefore when
	// 	// a > b we want a to be ordered before b hence we are returning
	// 	// true
	// 	return true;
	// }

	// return false;

	return a > b;
}

int main() {

	int arr[] = {50, 40, 40, 30, 30, 30, 20, 10, 10};
	int n = sizeof(arr) / sizeof(int);

	// sorting a sequence in the decreasing order

	// 1. using a customer comparator

	sort(arr, arr + n, greaterCmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	// 2. using greater<T>() function object / functor

	sort(arr, arr + n, greater<int>());

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	vector<string> v;

	v.push_back("man");
	v.push_back("rajhan");
	v.push_back("vansh");
	v.push_back("akhi");
	v.push_back("yuvansh");

	for (string name : v) {
		cout << name << endl;
	}

	cout << endl;

	sort(v.begin(), v.end());

	for (string name : v) {
		cout << name << endl;
	}

	cout << endl;

	sort(v.begin(), v.end(), greater<string>());

	for (string name : v) {
		cout << name << endl;
	}

	cout << endl;

	sort(v.begin(), v.end(), lengthCmp);

	for (string name : v) {
		cout << name << endl;
	}

	return 0;
}

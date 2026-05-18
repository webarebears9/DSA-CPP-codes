#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> a = {10, 30, 50, 70, 90};
	vector<int> b = {20, 40, 60};

	int n = a.size();
	int m = b.size();

	vector<int> c(n + m);

	int i = 0; // to iterate over a[]
	int j = 0; // to iterate over b[]
	int k = 0; // to iterate over c[]

	while (i <= n - 1 and j <= m - 1) {

		if (a[i] < b[j]) {
			c[k] = a[i];
			i++;
			k++;
		} else {
			c[k] = b[j];
			j++;
			k++;
		}

	}

	while (i <= n - 1) {
		c[k] = a[i];
		i++;
		k++;
	}

	while (j <= m - 1) {
		c[k] = b[j];
		j++;
		k++;
	}

	for (int idx = 0; idx < n + m; idx++) {
		cout << c[idx] << " ";
	}

	cout << endl;

	// time : (n+m).const ~ O(n+m)

	return 0;
}


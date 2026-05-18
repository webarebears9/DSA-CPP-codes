#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int serejaScore = 0;
	int dimaScore = 0;

	bool serjeraTurn = true;

	int i = 0;
	int j = n - 1;

	while (i <= j) {

		if (serjeraTurn) {

			if (v[i] > v[j]) {

				serejaScore += v[i];
				i++;

			} else {

				serejaScore += v[j];
				j--;

			}

			serjeraTurn = false;

		} else {

			if (v[i] > v[j]) {

				dimaScore += v[i];
				i++;

			} else {

				dimaScore += v[j];
				j--;

			}

			serjeraTurn = true;

		}

	}

	cout << serejaScore << " " << dimaScore << endl;

	return 0;
}
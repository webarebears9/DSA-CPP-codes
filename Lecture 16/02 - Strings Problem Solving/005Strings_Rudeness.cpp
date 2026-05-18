#include<iostream>
#include<string>

using namespace std;

int main() {

	string str = "ababbaab";

	int cntb = 0;
	int rudeness = 0;

	int n = str.size();

	// time : O(n)
	// space: O(1)

	for (int i = n - 1; i >= 0; i--) {
		if (str[i] == 'b') {
			cntb++;
		} else {
			// str[i] == 'a'
			rudeness += cntb;
		}

	}

	cout << rudeness << endl;

	return 0;
}
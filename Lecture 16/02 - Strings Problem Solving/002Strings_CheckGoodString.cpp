#include<iostream>
#include<string>

using namespace std;

// time : O(n) where n is the length of the string

bool isGoodString(const string& str) {

	for (char ch : str) {

		if (!(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u')) {

			// ch is a consonant
			return false;

		}

	}

	return true; // str is a good string

}

int main() {

	string str = "uoiea";

	isGoodString(str) ? cout << "good" << endl : cout << "not good" << endl;

	return 0;
}
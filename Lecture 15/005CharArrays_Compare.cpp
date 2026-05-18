#include<iostream>
#include<cstring>

using namespace std;

// assuming length of s1 is n and length of s2 is m
// time : O(min(n, m))

int stringCompare(char s1[], char s2[]) {

	int i = 0; // to iterate over s1[]
	int j = 0; // to iterate over s2[]

	while (s1[i] != '\0' and s2[j] != '\0') {

		if (s1[i] > s2[j]) {

			// s1 > s2

			return 1;

		} else if (s1[i] < s2[j]) {

			// s1 < s2

			return -1;

		} else { // s1[i] is equal to s2[j]

			i++;
			j++;

		}

	}

	if (s1[i] == '\0' and s2[j] == '\0') {

		// s1 equals s2

		return 0;

	} else if (s1[i] == '\0' and s2[j] != '\0') {

		// length of s2 > length of s1 => s2 > s1

		return -1;

	} else {

		// s1[i] != '\0' and s2[j] == '\0'

		// length of s1 > length of s2 => s1 > s2

		return 1;

	}

}

int main() {

	char s1[] = "azc";
	char s2[] = "azf";

	// int res = stringCompare(s1, s2);
	int res = strcmp(s1, s2);

	cout << res << endl;

	if (res == 0) {
		cout << s1 << " equals " << s2 << endl;
	} else if (res > 0) {
		cout << s1 << " > " << s2 << endl;
	} else {
		// res < 0
		cout << s1 << " < " << s2 << endl;
	}

	return 0;
}
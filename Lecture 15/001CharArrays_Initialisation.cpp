#include<iostream>

using namespace std;

int main() {

	char str1[] = {'a', 'b', 'c', 'd', 'e', '\0'};

	cout << str1 << endl;

	char str2[] = "coding";

	// when you init a char[] using a string literal
	// '\0' is added automatically.

	cout << str2 << endl;

	for (int i = 0; str2[i] != '\0'; i++) {
		cout << str2[i] << endl;
	}

	// since char. arrays are always null terminated
	// we can use '\0' as a stopping condition while
	// iterating over them

	return 0;
}
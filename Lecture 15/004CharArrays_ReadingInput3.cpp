// n <= 100

#include<iostream>

using namespace std;

int main() {

	char str[101]; // based on constraints

	cin.getline(str, 101, '$');

	// here we are using '$' as a delimiting char. therefore
	// we'll stop reading as soon as we encounter a '$' in the
	// input

	cout << str << endl;

	return 0;
}
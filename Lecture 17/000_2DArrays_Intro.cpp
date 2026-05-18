#include<iostream>

using namespace std;

int main() {

	int arr[3][4];

	cout << "sizeof(arr) = " << sizeof(arr) << "B" << endl;

	double brr[3][3];

	cout << "sizeof(brr) = " << sizeof(brr) << "B" << endl;

	char crr[10][10];

	cout << "sizeof(crr) = " << sizeof(crr) << "B" << endl;

	return 0;
}
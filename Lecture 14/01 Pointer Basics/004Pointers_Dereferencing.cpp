#include<iostream>

using namespace std;

int main() {

	int x = 10;
	int *xptr = &x;

	cout << "x = " << x << endl; // 10
	cout << "sizeof(x) = " << sizeof(x) << endl; // 4B
	cout << "xptr = " << xptr << endl; // 0x...
	cout << "sizeof(xptr) = " << sizeof(xptr) << endl; // 8B
	cout << "*xptr = " << *xptr << endl << endl;

	double y = 3.14;
	double* yptr = &y;
	cout << "y = " << y << endl;
	cout << "*yptr = " << *yptr << endl;

	int z = 516;
	char* ptr = (char*)&z;
	cout << (int)*ptr << endl;

	return 0;
}
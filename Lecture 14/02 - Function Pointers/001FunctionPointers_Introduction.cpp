#include<iostream>

using namespace std;

void greet() {
	cout << "namaste" << endl;
}

int add(int a, int b) {
	return a + b;
}

bool ascending(int a, int b) {
	return a > b; // return true if a > b otherwise return false
}

int main() {

	cout << (void*)&greet << endl;
	cout << (void*)&add << endl;
	cout << (void*)&ascending << endl << endl;

	// using '&' to access address of a function is optional

	cout << (void*)greet << endl;
	cout << (void*)add << endl;
	cout << (void*)ascending << endl << endl;

	void (*gptr)() = &greet;
	int (*aptr)(int, int) = &add;
	bool (*ascptr)(int, int) = &ascending;

	cout << (void*)gptr << endl;
	cout << (void*)aptr << endl;
	cout << (void*)ascptr << endl << endl;

	// we dereference a function pointer to call the function
	// whose addr the function pointer stores

	// using '*' to call a function using function pointer
	// is optional

	greet();
	(*gptr)();
	gptr();
	(*greet)();

	cout << add(1, 2) << endl;
	cout << (*aptr)(1, 2) << endl;
	cout << aptr(1, 2) << endl;
	cout << (*add)(1, 2) << endl;

	cout << ascending(1, 2) << endl;
	cout << (*ascptr)(1, 2) << endl;
	cout << ascptr(1, 2) << endl;
	cout << (*ascending)(1, 2) << endl;

	return 0;
}
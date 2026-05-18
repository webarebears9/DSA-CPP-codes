#include<iostream>
#include<climits>
#include<cmath>
#include<iomanip>

using namespace std;

int main() {

	cout << INT_MIN << endl;
	cout << INT_MAX << endl;
	cout << fixed << pow(2, 31) - 1 << endl;
	cout << -pow(2, 31) << endl;

	return 0;
}
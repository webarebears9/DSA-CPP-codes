#include<iostream>

using namespace std;

int main() {

	int p;
	cin >> p;

	int r;
	cin >> r;

	int t;
	cin >> t;

	cout << p * r * t / 100.0 << endl;
	cout << (float)p * r * t / 100 << endl; // explicite type-casting
	cout << (p * r * t) / 100.0 << endl;

	float si = p * r * t / 100.0;
	cout << si << endl;

	return 0;
}
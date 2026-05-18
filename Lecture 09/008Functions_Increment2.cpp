#include<iostream>

using namespace std;

void incr(int& ref) {
	ref++;
}

int main() {

	int x = 10;

	incr(x);

	cout << x << endl;

	return 0;
}
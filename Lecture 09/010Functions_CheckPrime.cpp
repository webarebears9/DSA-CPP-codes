#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int n) {
	int i = 2;
	while (i * i <= n) {
		if (n % i == 0) {
			// you've found a factor of n in the range 2 to sqrt(n)
			return false;
		}
		i++;
	}
	return true; // n is prime
}

int main() {

	int n;
	cin >> n;

	isPrime(n) ? cout << n << " is prime" << endl : cout << n << " is not prime" << endl;

	if (isPrime(n)) {
		cout << n << " is prime" << endl;
	} else {
		cout << n << " is not prime" << endl;
	}

	return 0;
}
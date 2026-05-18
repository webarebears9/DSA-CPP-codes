#include<iostream>
#include<cmath>

using namespace std;

/*

advantages of using functions

1. reusability
2. readability
3. modularity

*/

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

void printPrimes(int m) {

	for (int n = 2; n <= m; n++) {
		// check if n is a prime no. or not
		if (isPrime(n)) {
			cout << n << " ";
		}
	}

}


int main() {

	int m;
	cin >> m;

	printPrimes(m);

	return 0;
}
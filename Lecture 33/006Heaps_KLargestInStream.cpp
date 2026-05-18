#include<iostream>
#include<queue>
#include<vector>
#define pqmin priority_queue <int, vector<int>, greater<int>>

using namespace std;

void printHeap(pqmin minHeap) { // by default minHeap is passed by value

	while (!minHeap.empty()) {
		cout << minHeap.top() << " ";
		minHeap.pop();
	}

	cout << endl;

}

int main() {

	int k;
	cin >> k;

	pqmin minHeap;
	for (int i = 1; i <= k; i++) {
		int x; cin >> x;
		minHeap.push(x);
	}

	while (true) {

		int x;
		cin >> x;

		if (x == 0) break;

		if (x == -1) {
			// print minHeap as it track k-largest elements so
			// far in the stream
			printHeap(minHeap);
		} else {
			if (x > minHeap.top()) {
				minHeap.pop();
				minHeap.push(x);
			}
		}

	}

	return 0;
}
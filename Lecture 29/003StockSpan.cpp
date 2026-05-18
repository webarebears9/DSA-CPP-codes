#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// vector<int> f(const vector<int>& A) {

// 	int n = A.size();
// 	vector<int> ans;
// 	stack<pair<int, int>> s; // monotonic stack <value, index>

// 	for (int i = 0; i < n; i++) {

// 		// find the index of the nearest greater element
// 		// to the left of A[i]

// 		while (!s.empty() and s.top().first <= A[i]) {
// 			s.pop();
// 		}

// 		int j;

// 		if (s.empty()) {
// 			// there is no greater element to the
// 			// left of A[i]
// 			j = -1;
// 		} else {
// 			// whatever is at the top of the stack
// 			// is the nearest greater element to the
// 			// left of A[i]
// 			j = s.top().second;
// 		}

// 		ans.push_back(i - j);

// 		// s.push({A[i], i});

// 		s.push(make_pair(A[i], i));

// 	}

// 	return ans;

// }

vector<int> f(const vector<int>& A) {

	int n = A.size();
	vector<int> ans;
	stack<int> s; // monotonic stack <index>

	for (int i = 0; i < n; i++) {

		// find the index of the nearest greater element
		// to the left of A[i]

		while (!s.empty() and A[s.top()] <= A[i]) {
			s.pop();
		}

		int j;

		if (s.empty()) {
			// there is no greater element to the
			// left of A[i]
			j = -1;
		} else {
			// whatever is at the top of the stack
			// is the nearest greater element to the
			// left of A[i]
			j = s.top();
		}

		ans.push_back(i - j);

		s.push(i);

	}

	return ans;

}

int main() {

	vector<int> A = {100, 80, 60, 70, 60, 75, 85, 200};

	vector<int> ans = f(A);
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl; // 1 1 1 2 1 4 6 8

	return 0;
}
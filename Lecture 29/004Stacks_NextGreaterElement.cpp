#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> f(const vector<int>& A) {

	int n = A.size();
	vector<int> ans(n, -1);
	stack<int> s; // monotonic stack // <index>

	for (int i = 0; i < n; i++) {

		// for which elements A[i] can be the ans
		// i.e. for which values seen so far whose
		// ans is still not calculated A[i]
		// is the nearest greater element to the
		// right

		while (!s.empty() and A[i] > A[s.top()]) {
			// A[i] is the nearest greater element
			// for whatever is at the top of the stack
			ans[s.top()] = A[i];
			s.pop();
		}

		s.push(i);

	}

	return ans;

}

int main() {

	vector<int> A = {5, 3, 6, 7, 2, 1, 4};

	vector<int> ans = f(A);
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl; // 6 6 7 -1 4 4 -1

	return 0;
}
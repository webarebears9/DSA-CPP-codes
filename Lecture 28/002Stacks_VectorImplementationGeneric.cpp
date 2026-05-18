#include<iostream>
#include<vector>

using namespace std;

template <typename T>
class Stack {

	vector<T> v;

public :

	void push(T val) {
		v.push_back(val);
	}

	void pop() {
		v.pop_back();
	}

	int size() {
		return v.size();
	}

	T top() {
		return v.back();
	}

	bool empty() {
		return v.empty();
	}

};

int main() {

	Stack<string> s;

	cout << "size : " << s.size() << endl;
	cout << "isEmpty ? " << s.empty() << endl;

	s.push("ABC");
	s.push("DEF");
	s.push("GHI");
	s.push("JKL");
	s.push("MNO");

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;
	cout << "isEmpty ? " << s.empty() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "isEmpty ? " << s.empty() << endl;

	return 0;
}
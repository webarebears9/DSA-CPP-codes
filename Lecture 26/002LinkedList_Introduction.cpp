#include<iostream>

using namespace std;

class ListNode {

public:

	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}

};

int main() {

	ListNode* n = new ListNode(10);

	cout << n->val << endl;

	if (n->next == NULL) {
		cout << "this node is not pointing to anything" << endl;
	}

	ListNode* m = new ListNode(20);

	cout << m->val << endl;

	if (m->next == NULL) {
		cout << "this node is not pointing to anything" << endl;
	}

	n->next = m; // node with val 10 is now pointing to node with val 20

	if (n->next == NULL) {
		cout << "this node is not pointing to anything" << endl;
	} else {
		cout << "this node is pointing to some node" << endl;
	}

	return 0;

}
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

void insertAtHead(ListNode*& headRef, int val) { // here we are passing head ptr by reference since we want changes done to head ptr in this fn to be reflected in the caller fn
	ListNode* n = new ListNode(val);
	n->next = headRef;
	headRef = n;
}

void printLinkedList(ListNode* head) { // here we are passing head ptr by value since we don't want changes done to head ptr within this fn to reflect in the caller fn
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

int main() {

	ListNode* head = NULL; // init, linkedList is empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	if (head == NULL) {
		cout << "LinkedList is empty" << endl;
	}

	printLinkedList(head);

	return 0;

}
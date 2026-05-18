
/*
given the pre-order traversal of a binary tree, check if it is height balanced or not

Example
	Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
	Output: true

	Input : 10 20 40 -1 -1 50 -1 -1 30 60 -1 -1 70 -1 -1
	Output: true

	Input : 10 20 30 -1 -1 -1 -1
	Output: false

*/

#include<iostream>
#include<cmath>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};


TreeNode* buildTree() {

	int val;
	cin >> val;

	// base case

	if (val == -1) {
		// construct an empty tree and return pointer to its root TreeNode
		return NULL;
	}

	// recursive case

	// 1. construct the root val using the first value of the given preOrder traversal

	TreeNode* root = new TreeNode(val);

	// 2. ask your friend to construct the leftSubtree from the preOrder traversal of the leftSubtree

	root->left = buildTree();

	// 3. ask your friend to construct the rightSubtree from the preOrder traversal of the rightSubtree

	root->right = buildTree();

	return root;

}

int findHeight(TreeNode* root) {

	// base case
	if (root == NULL) {
		return -1;
	}

	// recursive case

	// f(root) : find the height of the given tree

	// 1. ask your friend to find the height of the leftSubtree

	int leftHgt = findHeight(root->left);

	// 2. ask your friend to find the height of the rightSubtree

	int rightHgt = findHeight(root->right);

	return 1 + max(leftHgt, rightHgt);

}

// time : O(n^2)

bool dfs(TreeNode* root) {

	// base case

	if (root == NULL) {
		// tree is empty hence height-balanced
		return true;
	}

	// recursive case

	// f(root) : it is a fn that check if given tree is height balanced or not

	// 1. ask your friend to check if the leftSubtree is height-balanced

	bool leftIsBal = dfs(root->left);

	// 2. ask your friend to check if the rightSubtree is height-balanced

	bool rightIsBal = dfs(root->right);

	// 3. check if the height-balance prop. works at the root node

	bool doesHBPropWorkAtRoot = abs(findHeight(root->left) - findHeight(root->right)) <= 1 ? true : false;

	return leftIsBal and rightIsBal and doesHBPropWorkAtRoot;

}

class Pair {

public:
	int height;
	bool isBal;
};

// time : O(n)
// space: O(h) due to fn call stack

Pair dfsOptimised(TreeNode* root) {

	Pair p;

	// base case
	if (root == NULL) {
		p.height = -1;
		p.isBal = true;
		return p;
	}

	// recursive case

	Pair left = dfsOptimised(root->left);
	Pair right = dfsOptimised(root->right);
	bool doesHBPropWorkAtRoot = abs(left.height - right.height) <= 1 ? true : false;

	p.height = 1 + max(left.height, right.height);
	p.isBal = left.isBal and right.isBal and doesHBPropWorkAtRoot;

	return p;

}

int main() {

	TreeNode* root = buildTree();

	dfs(root) ? cout << "height-balanced!" << endl : cout << "not height-balanced" << endl;

	Pair p = dfsOptimised(root);

	p.isBal ? cout << "height-balanced" << endl : cout << "not height-balanced" << endl;

	return 0;
}
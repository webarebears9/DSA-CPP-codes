/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Data {
public :
    int sum;
    int minVal;
    int maxVal;
    bool isBST;
    int maxBSTSum;
};

class Solution {
public:

    Data dfs(TreeNode* root) {
        Data d;

        // base case
        if (root == NULL) {
            d.isBST = true;
            d.minVal = INT_MAX;
            d.maxVal = INT_MIN;
            d.sum = 0;
            d.maxBSTSum = 0;
            return d;
        }

        // recursive case

        Data left = dfs(root->left);
        Data right = dfs(root->right);

        d.minVal = min(left.minVal, min(right.minVal, root->val));
        d.maxVal = max(left.maxVal, max(right.maxVal, root->val));
        d.isBST = left.isBST and right.isBST and root->val > left.maxVal and root->val < right.minVal;
        d.sum = left.sum + right.sum + root->val;

        if (d.isBST) { // given tree is a BST
            d.maxBSTSum = max(left.maxBSTSum, max(right.maxBSTSum, d.sum));
        } else {
            // given tree is not a BST
            d.maxBSTSum = max(left.maxBSTSum, right.maxBSTSum);
        }

        return d;

    }

    int maxSumBST(TreeNode* root) {
        Data d = dfs(root);
        return d.maxBSTSum;
    }
};
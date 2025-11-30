#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int value=0) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

bool isBstHelper(TreeNode* root, int min, int max) {
    if (!root) return true;

    if (root->val < min || root->val > max) return false;

    return isBstHelper(root->left, min, root->val-1) && isBstHelper(root->right, root->val+1, max);
    
}

bool isBST(TreeNode* root) {
    return isBstHelper(root, INT_MIN, INT_MAX);
}
int main() {
    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(11);
    root->right = new TreeNode(20);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(30);

    cout << isBST(root);

    return 0;
}
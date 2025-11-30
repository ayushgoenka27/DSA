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

void preorder(TreeNode* root) {
    if(!root) {
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val<< " ";
}

int main() {
    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(20);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(30);

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    
    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    return 0;
}
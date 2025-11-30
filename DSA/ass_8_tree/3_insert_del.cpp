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

TreeNode* insert(TreeNode* root, int value) {
    if (!root) {
        return new TreeNode(value);
    }
    if (value < root->val) {
        root->left = insert(root->left, value);
    }
    else if (value > root->val) {
        root->right = insert(root->right, value);
    }
    return root;
}

TreeNode* findMin(TreeNode* root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

TreeNode* deleteNode(TreeNode* root, int value) {
    if (!root) return nullptr;
    
    if (value < root->val) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->val) {
        root->right = deleteNode(root->right, value);
    }
    else {
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }
        else if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        else {
            TreeNode* temp = findMin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }
    return root;
}

int maxDepth(TreeNode* root) {
    if (!root) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}

int minDepth(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    if (!root->left) return minDepth(root->right) + 1;
    if (!root->right) return minDepth(root->left) + 1;
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    return min(leftDepth, rightDepth) + 1;
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = nullptr;
    
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 15);
    root = insert(root, 30);
    
    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;
    
    root = insert(root, 7);
    cout << "After inserting duplicate 7: ";
    inorder(root);
    cout << endl;
    
    cout << "Maximum depth: " << maxDepth(root) << endl;
    cout << "Minimum depth: " << minDepth(root) << endl;
    
    root = deleteNode(root, 5);
    cout << "After deleting 5: ";
    inorder(root);
    cout << endl;
    
    root = deleteNode(root, 20);
    cout << "After deleting 20: ";
    inorder(root);
    cout << endl;
    
    cout << "Maximum depth: " << maxDepth(root) << endl;
    cout << "Minimum depth: " << minDepth(root) << endl;
    
    return 0;
}
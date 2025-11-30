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

bool search_rec(TreeNode* root, int target) {
    if (!root) return false;
    if (root->val == target) {
        return true;
    }
    else if (target > root->val) 
        return search_rec(root->right, target);
    else
        return search_rec(root->left, target);
}

bool search_non_rec(TreeNode* root, int target) {
    TreeNode* curr = root;
    while (curr) {
        if (curr->val == target) {
            return true;
        }
        else if (target > curr->val) {
            curr = curr->right;
        }
        else {
            curr = curr->left;
        }
    }
    return false;
}

int maximum(TreeNode* root) {
    if (!root) return -1;
    TreeNode* curr = root;
    while (curr->right) {
        curr = curr->right;
    }
    return curr->val;
}

int minimum(TreeNode* root) {
    if (!root) return -1;
    TreeNode* curr = root;
    while (curr->left) {
        curr = curr->left;
    }
    return curr->val;
}

TreeNode* inorder_successor(TreeNode* root, TreeNode* node) {
    if (!node) return nullptr;
    
    if (node->right) {
        TreeNode* curr = node->right;
        while (curr->left) {
            curr = curr->left;
        }
        return curr;
    }
    
    TreeNode* successor = nullptr;
    TreeNode* curr = root;
    while (curr) {
        if (node->val < curr->val) {
            successor = curr;
            curr = curr->left;
        }
        else if (node->val > curr->val) {
            curr = curr->right;
        }
        else {
            break;
        }
    }
    return successor;
}

TreeNode* inorder_predecessor(TreeNode* root, TreeNode* node) {
    if (!node) return nullptr;
    
    if (node->left) {
        TreeNode* curr = node->left;
        while (curr->right) {
            curr = curr->right;
        }
        return curr;
    }
    
    TreeNode* predecessor = nullptr;
    TreeNode* curr = root;
    while (curr) {
        if (node->val > curr->val) {
            predecessor = curr;
            curr = curr->right;
        }
        else if (node->val < curr->val) {
            curr = curr->left;
        }
        else {
            break;
        }
    }
    return predecessor;
}

int main() {
    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(20);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(30);

    cout << "Search 7 (recursive): " << search_rec(root, 7) << endl;
    cout << "Search 2 (recursive): " << search_rec(root, 2) << endl;
    cout << "Search 7 (non-recursive): " << search_non_rec(root, 7) << endl;
    cout << "Search 2 (non-recursive): " << search_non_rec(root, 2) << endl;
    
    cout << "Maximum: " << maximum(root) << endl;
    
    cout << "Minimum: " << minimum(root) << endl;
    
    TreeNode* node = root->left->right;
    TreeNode* succ = inorder_successor(root, node);
    cout << "Inorder successor of 7: " << (succ ? succ->val : -1) << endl;
    
    TreeNode* pred = inorder_predecessor(root, node);
    cout << "Inorder predecessor of 7: " << (pred ? pred->val : -1) << endl;
    
    return 0;
}
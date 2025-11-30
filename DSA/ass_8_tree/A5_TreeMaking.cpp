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

TreeNode* buildTree(vector<int>& preorder, int& preIndex, vector<int>& inorder, int inStart, int inEnd) {
    if(inStart > inEnd) {
        return nullptr;
    }
    
    TreeNode* root = new TreeNode(preorder[preIndex]);
    preIndex++;
    
    if(inStart == inEnd) {
        return root;
    }
    
    int inIndex;
    for(int i = inStart; i <= inEnd; i++) {
        if(inorder[i] == root->val) {
            inIndex = i;
            break;
        }
    }
    
    root->left = buildTree(preorder, preIndex, inorder, inStart, inIndex - 1);
    root->right = buildTree(preorder, preIndex, inorder, inIndex + 1, inEnd);
    
    return root;
}

TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder) {
    int preIndex = 0;
    return buildTree(preorder, preIndex, inorder, 0, inorder.size() - 1);
}

void preorderPrint(TreeNode* root) {
    if(!root) return;
    cout << root->val << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

void inorderPrint(TreeNode* root) {
    if(!root) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

void postorderPrint(TreeNode* root) {
    if(!root) return;
    postorderPrint(root->left);
    postorderPrint(root->right);
    cout << root->val << " ";
}

int main() {
    vector<int> preorder = {10, 5, 3, 7, 20, 15, 30};
    vector<int> inorder = {3, 5, 7, 10, 15, 20, 30};
    
    TreeNode* root = constructTree(preorder, inorder);
    
    cout << "Preorder: ";
    preorderPrint(root);
    cout << endl;
    
    cout << "Inorder: ";
    inorderPrint(root);
    cout << endl;
    
    cout << "Postorder: ";
    postorderPrint(root);
    cout << endl;
    
    return 0;
}

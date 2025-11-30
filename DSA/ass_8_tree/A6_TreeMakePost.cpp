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

TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder, int inStart, int inEnd, int& postIndex) {
    if (inStart > inEnd) return nullptr;
    TreeNode* root = new TreeNode(postorder[postIndex]);
    postIndex--;
    
    if (inStart == inEnd) {
        return root;
    }
    int inIndex;
    for (int i = inStart; i < inEnd; i++) {
        if (i == root->val) {
            inIndex = i;
            break;
        }
    }
    root->left = buildTree(postorder, inorder, inStart, inIndex-1, postIndex);
    root->right = buildTree(postorder, inorder, inIndex+1, inEnd, postIndex);
    return root;
}
int main() {

    return 0;
}
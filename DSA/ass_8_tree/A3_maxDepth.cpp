#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int value = 0)
    {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

int findDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(findDepth(root->left), findDepth(root->right));
}
int main() {
    TreeNode *root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(20);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(30);

    cout << findDepth(root);

    return 0;
}
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

int sumOfLeft(TreeNode *root)
{
    if (!root)
        return 0;
    int sum = 0;
    if (root->left && !root->left->left && !root->left->right)
    {
        sum += root->left->val;
    }
    sum += sumOfLeft(root->left);
    sum += sumOfLeft(root->right);
    return sum;
}

int main()
{
    TreeNode *root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(20);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(30);

    cout << sumOfLeft(root);
    return 0;
}
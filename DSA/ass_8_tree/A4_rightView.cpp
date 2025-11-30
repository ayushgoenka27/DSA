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

//DFS
vector<int>rightStdeview(TreeNode* root) {
    vector<int>res;
    rightView(root, 0, res);
    return res;
}
void rightView(TreeNode* root, int level, vector<int>& res) {
    if (!root) return;
    if (res.size() == level) {
        res.push_back(root->val);
    }
    rightView(root->right, level+1, res);
    rightView(root->left, level+1, res);

}
int main() {

    return 0;
}
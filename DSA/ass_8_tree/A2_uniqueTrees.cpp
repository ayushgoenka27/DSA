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

vector<TreeNode*> getTrees(int start, int end) {
    vector<TreeNode*> trees;
    if (start > end) {
        trees.push_back(nullptr);
        return trees;
    }
    for (int i = start; i <= end; i++) {
        vector<TreeNode*> leftTree = getTrees(start, i-1);
        vector<TreeNode*> rightTree = getTrees(i+1, end);
        for (TreeNode* left : leftTree) {
            for (TreeNode* right : rightTree) {
                TreeNode* root = new TreeNode(i);
                root->left = left;
                root->right = right;
                trees.push_back(root); 
            }
        }

    }
    return trees;
}

void preorder(TreeNode* root) {
    if (root!=nullptr) {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
vector<TreeNode*>trees =  getTrees(1,3);
for(int i = 0; i < trees.size(); i++) {
    preorder(trees[i]);
    cout << endl;
}
    return 0;
}
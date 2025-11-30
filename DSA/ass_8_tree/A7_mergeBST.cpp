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

void inorderStore(TreeNode* root, vector<int>& arr) {
    if(!root) return;
    inorderStore(root->left, arr);
    arr.push_back(root->val);
    inorderStore(root->right, arr);
}

vector<int> mergeSorted(vector<int>& arr1, vector<int>& arr2) {
    vector<int> merged;
    int i = 0, j = 0;
    
    while(i < arr1.size() && j < arr2.size()) {
        if(arr1[i] <= arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }
    
    while(i < arr1.size()) {
        merged.push_back(arr1[i]);
        i++;
    }
    
    while(j < arr2.size()) {
        merged.push_back(arr2[j]);
        j++;
    }
    
    return merged;
}

TreeNode* createDLL(vector<int>& arr) {
    if(arr.size() == 0) return nullptr;
    
    TreeNode* head = new TreeNode(arr[0]);
    TreeNode* curr = head;
    
    for(int i = 1; i < arr.size(); i++) {
        TreeNode* newNode = new TreeNode(arr[i]);
        curr->right = newNode;
        newNode->left = curr;
        curr = newNode;
    }
    
    return head;
}

TreeNode* mergeBSTs(TreeNode* root1, TreeNode* root2) {
    vector<int> arr1, arr2;
    
    inorderStore(root1, arr1);
    inorderStore(root2, arr2);
    
    vector<int> merged = mergeSorted(arr1, arr2);
    
    return createDLL(merged);
}

void printDLL(TreeNode* head) {
    TreeNode* curr = head;
    cout << "Forward: ";
    while(curr) {
        cout << curr->val << " ";
        if(curr->right == nullptr) break;
        curr = curr->right;
    }
    cout << endl;
    
    cout << "Backward: ";
    while(curr) {
        cout << curr->val << " ";
        curr = curr->left;
    }
    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(10);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(15);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(7);
    
    TreeNode* root2 = new TreeNode(20);
    root2->left = new TreeNode(12);
    root2->right = new TreeNode(25);
    root2->left->left = new TreeNode(8);
    root2->left->right = new TreeNode(18);
    
    TreeNode* dllHead = mergeBSTs(root1, root2);
    
    printDLL(dllHead);
    
    return 0;
}

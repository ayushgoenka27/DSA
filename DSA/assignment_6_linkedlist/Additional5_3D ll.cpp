#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* next;
    Node* prev;
    Node* up;
    Node* down;
    int val;
    Node(int value) : val(value), next(NULL), prev(NULL), up(NULL), down(NULL) {}
};

Node* Matrix_DLL(vector<vector<int>>& M) {
    int m = M.size();
    int n = M[0].size();
    Node* nodes[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            nodes[i][j] = new Node(M[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) nodes[i][j]->prev = nodes[i][j-1];
            if (i > 0) nodes[i][j]->up = nodes[i-1][j];
            if (j < n) nodes[i][j]->next = nodes[i][j+1];
            if (i < m) nodes[i][j]->down = nodes[i+1][j];
        }
    }
    return nodes[0][0]; 
}


void print2DLL(Node* head, int rows, int cols) {
    Node* curr;
    Node* row = head;
    for (int i = 0; i < rows; i++) {
        curr = row;
        for (int j = 0; j < cols; j++) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
        row = row->down;
    }
}

int main() {    
vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
Node* head = Matrix_DLL(mat);
print2DLL(head, mat.size(), mat[0].size());
    return 0;
}
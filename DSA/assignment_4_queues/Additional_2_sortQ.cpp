#include <bits/stdc++.h>
using namespace std;

int minIndex(queue<int> &q, int sortedIndex) {
    int min_index = -1;
    int min_val = INT_MAX;
    int n = q.size();
    for (int i  = 0; i < n; i++) {
        int curr = q.front();
        q.pop();
        if (curr < min_val && i <= sortedIndex) {
            min_val = curr;
            min_index = i;
        }
        q.push(curr);
    }
    return min_index;
}

void addtoRear(queue<int> &q, int min_Index) {
    int minVal;
    int n = q.size();
    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();
        if (i!=min_Index) {
            q.push(curr);
        } else {
            minVal = curr; 
        }
    }
    q.push(minVal);

}

void finale(queue<int> &q) {
    int n = q.size();
    for (int i = 0; i < n; i++) {
        int min_index = minIndex(q, n-i-1);
        addtoRear(q, min_index);
    }
}




int main() {
    queue<int> q;
    q.push(8);
    q.push(7);
    q.push(2);
    q.push(5);
    q.push(1);
    q.push(3);
    finale(q);
    while(!q.empty()) {
        cout << q.front();
        q.pop();
    }
    

    return 0;
}
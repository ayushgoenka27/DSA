#include <bits/stdc++.h>
using namespace std;
void interleave(queue<int>& q) {
    stack<int> s;
    int n = q.size();
    for (int i = 0; i < n/2; i++) {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    for (int i = 0; i < n/2; i++) {
        q.push(q.front());
        q.pop();
    }
    for (int i = 0; i < n/2;i++) {
        s.push(q.front());
        q.pop();
    }
    //interleave
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }

} 

int main() {
queue<int> q;
int n = 6;
for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    q.push(val);
}
interleave(q);
while(!q.empty()) {
    cout << q.front() << " ";
    q.pop();
}
    return 0;
}
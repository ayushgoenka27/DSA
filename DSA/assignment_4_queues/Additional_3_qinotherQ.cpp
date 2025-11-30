#include <bits/stdc++.h>
using namespace std;

bool checkSorted(queue<int>& q) {
    int expected = 1;
    stack<int> st;
    int n = q.size();

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == expected) {
            expected++;
        } 
        else {
            if (st.empty())
                st.push(curr);
            else if (st.top() < curr)
                return false; // violates decreasing order
            else
                st.push(curr);
        }

        // Move from stack to expected sequence if possible
        while (!st.empty() && st.top() == expected) {
            st.pop();
            expected++;
        }
    }

    return (expected - 1 == n && st.empty());
}

int main() {
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << (checkSorted(q) ? "Yes" : "No") << endl;

    return 0;
}

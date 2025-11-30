#include <bits/stdc++.h>
using namespace std;
class Stack {
    queue <int> q;

    public:
    void push(int x) {
        q.push(x);
        int n = q.size();
        for (int i = 0; i < n-1; i++) {
            q.push(q.front());
            q.pop();
        }

    }

    void pop() {
        if (q.front() == q.back() && q.back() == -1) {
            cout << "Empty";
        }
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }

    bool empty() {
        return q.empty();
    }

};
int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl;
    st.pop();

    cout << st.top() << endl;
    st.pop();

    cout << st.top() << endl; 
    st.pop();

    cout << st.empty() << endl; 
    return 0;
}
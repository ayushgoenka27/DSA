#include <bits/stdc++.h>
using namespace std;

void firstNonRepeating(string s) {
    vector<int> freq(26, 0);
    queue<char> q;

    for (char ch : s) {
        freq[ch - 'a']++;
        q.push(ch);

        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (q.empty()) 
            cout << "-1 ";
        else 
            cout << q.front() << " ";
    }
}

int main() {
    string s = "aabc";
    firstNonRepeating(s);
    return 0;
}

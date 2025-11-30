#include <bits/stdc++.h>
using namespace std;
vector<int>bfs(vector<vector<int>> &adj) {
    int V = adj.size();
    vector<bool>visited(V, false);
    vector<int>res;
    queue<int> q;
    int start = 0;
    visited[start] = true;
    q.push(start);

    while(!q.empty()) {
        int curr = q.front();
        res.push_back(curr);
        q.pop();
        for (int i : adj[curr]) {
            if (!visited[i]) {
                q.push(i);
            }
        }
    }
    return res;         
}
int main() {

    return 0;
}
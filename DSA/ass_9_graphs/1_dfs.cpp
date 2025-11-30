#include <bits/stdc++.h>
using namespace std;

void dfsVisit(int s, vector<vector<int>> &adj, vector<bool> &visited, vector<int>& res) {
    visited[s] = true;
    res.push_back(s);
    for (int i : adj[s]) {
        if (!visited[i]) {
            dfsVisit(i, adj, visited,res);
        }
    }
}
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
vector<int>dfs(vector<vector<int>>&adj) {
    vector<bool>visited(adj.size(), false);
    vector<int>res;
    dfsVisit(0, adj, visited, res);
    return res;
}
int main() {
    int V = 6;
    vector<vector<int>> adj(V);
    
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 0);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 5);
    vector<int>res;
    res = dfs(adj);
    for (int i : res)
    cout << i <<" ";
    return 0;
}
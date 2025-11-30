#include <bits/stdc++.h>
using namespace std;
void dfsVisit(int s, vector<bool>&visited, vector<vector<int>>&adj) {
    visited[s] = true;
    for (int i : adj[s]) {
        if (!visited[i]) {
            dfsVisit(i, visited, adj);
        }
    }
}
vector<vector<int>> buildAdj(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    for (auto it: edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    return adj;
}

int countConnected(int V, vector<vector<int>>& adj) {
int count = 0;
vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
    if(!visited[i]) {
        dfsVisit(i, visited, adj);
        count++;
    }
}
return count;
}

int main() {
int V = 5, E = 3;
vector<vector<int>> edges = {{0,1}, {1,2}, {3,4}};
vector<vector<int>>adj = buildAdj(V, edges);

cout << countConnected(V, adj);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> convertToAdj(vector<vector<int>>&grid) {
    int m = grid.size();
    int n = grid[0].size();
    
    vector<vector<pair<int,int>>> adj(m * n);

    int dy[] = {-1, 1, 0, 0};
    int dx[] = {0, 0, -1, 1};
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int u = i * n + j;
            
            for (int k = 0; k < 4; k++) {
                int ni = i + dy[k];
                int nj = j + dx[k];
                
                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    int v = ni * n + nj;
                    int weight = grid[ni][nj];
                    adj[u].push_back({v, weight});
                }
            }
        }
    }
    return adj;
}

vector<int> dijkstra(vector<vector<pair<int,int>>> &adj, int src) {
    int V = adj.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int>dist(V,INT_MAX);
    dist[src] = 1;
    pq.push({1, src});
    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int d = top.first;
        int u = top.second;
        if (d > dist[u]) continue;
        for (auto i : adj[u]) {
                int v = i.first;
                int weight = i.second;
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
        }
    }
    return dist;
}
int main() {
vector<vector<int>> grid =  {{1,2,3}, {4,5,6}, {7,8,9}};

vector<vector<pair<int,int>>>adj(3);
adj = convertToAdj(grid);
vector<int>distance(3);

distance = dijkstra(adj,0);
for (int i : distance) {
    cout << i<< " ";
}
cout << "distance of last node = " << distance[adj.size()-1];
return 0;
}
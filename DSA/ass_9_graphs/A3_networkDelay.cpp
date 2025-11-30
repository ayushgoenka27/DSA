#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> convertToAdj(int N, vector<vector<int>>& times) {
    vector<vector<pair<int,int>>> adj(N + 1); // N nodes, 1-indexed
    
    for (auto& edge : times) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v, w});
    }
    
    return adj;
}

vector<int> dijkstra(vector<vector<pair<int,int>>>& adj, int src) {
    int V = adj.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);
    
    dist[src] = 0;
    pq.push({0, src});
    
    while (!pq.empty()) {
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

int networkDelayTime(int N, int K, vector<vector<int>>& times) {
    vector<vector<pair<int,int>>> adj = convertToAdj(N, times);
    vector<int> distance = dijkstra(adj, K);
    
    int maxTime = 0;
    for (int i = 1; i <= N; i++) {
        if (distance[i] == INT_MAX) {
            return -1;
        }
        maxTime = max(maxTime, distance[i]);
    }
    
    return maxTime;
}

int main() {
    int N = 4, K = 2;
    vector<vector<int>> times = {{2,1,1}, {2,3,1}, {3,4,1}};
    
    int result = networkDelayTime(N, K, times);
    cout << "Network delay time: " << result << endl;
    
    return 0;
}
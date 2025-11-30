#include <bits/stdc++.h>
using namespace std;
int prims(int V, vector<vector<int>> adj[]) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<bool>visited(V, false);
    pq.push({0,0});
    int sum = 0;
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int u= it.second;
        if(visited[u] == true) continue;
        visited[u] = true;
        sum+=wt;
        for(auto it : adj[u]) {
            int v = it[0];
            int edgeW = it[1];
            if(!visited[v]) {
                pq.push({edgeW, v});
            }

        }
    }
    return sum;
}
int main() {
int V = 5;
	vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
	vector<vector<int>> adj[V];
	for (auto it : edges) {
		vector<int> tmp(2);
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[1]].push_back(tmp);
	}

	
	int sum = prims(V, adj);
	cout << "The sum of all the edge weights: " << sum << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int to;
    long long weight;
};

long long dfs(int node, int parent, const vector<vector<Edge>>& adj, long long& maxGoodness) {
    long long currentGoodness = 0;
    
    for (const Edge& edge : adj[node]) {
        if (edge.to != parent) {
            long long childGoodness = dfs(edge.to, node, adj, maxGoodness);
            if (childGoodness + edge.weight > 0) {
                currentGoodness += childGoodness + edge.weight;
            }
        }
    }
    
    maxGoodness = max(maxGoodness, currentGoodness);
    
    return currentGoodness;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<vector<Edge>> adj(n + 1);
        
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            long long w;
            cin >> u >> v >> w;
            adj[u].emplace_back(Edge{v, w});
            adj[v].emplace_back(Edge{u, w});
        }
        
        long long maxGoodness = 0;
        dfs(1, -1, adj, maxGoodness);
        
        cout << maxGoodness << endl;
    }
    
    return 0;
}

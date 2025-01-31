#include "bits/stdc++.h"
using namespace std;
#define int long long

struct Edge {
    int u, v, weight;
    bool operator<(const Edge &other) const {
        return weight < other.weight;
    }
};

struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    int total_cost = 0, edges_used = 0;

    for (auto &edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            total_cost += edge.weight;
            edges_used++;
        }
    }

    // Check if all nodes are connected
    if (edges_used != n - 1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << total_cost << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

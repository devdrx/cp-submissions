#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <limits.h>

using namespace std;

// Function to perform DFS and calculate the maximum possible value at the root
pair<long long, long long> dfs(int node, const vector<vector<int>>& tree, vector<long long>& a) {
    if (tree[node].empty()) {  // If the node is a leaf
        return {a[node], 0};
    }

    long long total_subtree_value = 0;
    long long max_increase = 0;
    for (int child : tree[node]) {
        pair<long long, long long> child_result = dfs(child, tree, a);
        long long child_subtree_value = child_result.first;
        long long child_max_increase = child_result.second;
        total_subtree_value += child_subtree_value;
        max_increase = max(max_increase, child_max_increase);
    }

    long long max_transfers = min(max_increase, a[node]);
    return {total_subtree_value + a[node] - max_transfers, max_transfers};
}

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<vector<int>> tree(n);
        for (int i = 2; i <= n; ++i) {
            int p;
            cin >> p;
            tree[p - 1].push_back(i - 1);
        }

        pair<long long, long long> result = dfs(0, tree, a);
        long long root_value = result.first;
        long long max_increase_at_root = result.second;
        cout << root_value + max_increase_at_root << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int computeChanges(const vector<vector<int>> &a, int type) {
    int n = a.size(), m = a[0].size(), total = n * m;
    map<int, int> freq;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int dx;
            if (type == 0) dx = i + j;
            else if (type == 1) dx = -i - j;
            else if (type == 2) dx = j - i;
            else dx = i - j;

            int base = a[i][j] - dx;
            freq[base]++;
        }
    }

    int best = total;
    for (auto &[val, f] : freq) {
        best = min(best, total - f);
    }

    return best;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];

        int ans = n * m;
        for (int type = 0; type < 4; type++)
            ans = min(ans, computeChanges(a, type));

        cout << ans << endl;
    }

    return 0;
}

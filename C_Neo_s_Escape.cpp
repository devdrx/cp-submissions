#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_clones(const vector<int>& a) {
    int n = a.size();

    vector<int> L(n), R(n);

    // Build L: longest non-increasing sequence ending at each index from the left
    L[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] >= a[i - 1])
            L[i] = L[i - 1];
        else
            L[i] = i;
    }

    // Build R: longest non-increasing sequence starting at each index from the right
    R[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] >= a[i + 1])
            R[i] = R[i + 1];
        else
            R[i] = i;
    }

    // Identify peaks and form intervals
    vector<pair<int, int>> intervals;
    for (int i = 0; i < n; ++i) {
        bool is_peak = false;
        if (n == 1) {
            is_peak = true;
        } else if (i == 0 && a[i] >= a[i + 1]) {
            is_peak = true;
        } else if (i == n - 1 && a[i] >= a[i - 1]) {
            is_peak = true;
        } else if (i > 0 && i < n - 1 && a[i] >= a[i - 1] && a[i] >= a[i + 1]) {
            is_peak = true;
        }

        if (is_peak) {
            intervals.emplace_back(L[i], R[i]);
        }
    }

    // Greedy cover of [0, n-1]
    sort(intervals.begin(), intervals.end()); // sort by left bound

    int clones = 0;
    int cur = 0;
    int i = 0;

    while (cur < n) {
        int farthest = -1;
        while (i < intervals.size() && intervals[i].first <= cur) {
            farthest = max(farthest, intervals[i].second);
            ++i;
        }
        ++clones;
        cur = farthest + 1;
    }

    return clones;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        cout << min_clones(a) << '\n';
    }

    return 0;
}

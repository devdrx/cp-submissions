#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n == 1 || n == 2) {
        cout << "-1\n";
        return;
    }

    vector<int> perm(n);
    
    // Odd case: Swap adjacent elements, skipping the first element
    for (int i = 1; i < n; i += 2) {
        perm[i - 1] = i + 1;
        perm[i] = i;
    }
    
    // If n is odd, last element remains untouched
    if (n % 2 == 1) {
        perm[n - 1] = n;
    }
    
    // Print the permutation
    for (int x : perm) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

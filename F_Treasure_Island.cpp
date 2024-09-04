#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int m, n;
    ll k;
    cin >> m >> n >> k;
    
    vector<vector<ll>> grid(m, vector<ll>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    
    vector<ll> dp(m), max_up(m), max_down(m);
    
    for (int r = 0; r < m; ++r) {
        dp[r] = grid[r][0];
    }
    
    for (int c = 1; c < n; ++c) {
        max_up[0] = dp[0] + k * 0;  
        for (int r = 1; r < m; ++r) {
            max_up[r] = max(max_up[r - 1], dp[r] + k * r);
        }
        
        max_down[m - 1] = dp[m - 1] - k * (m - 1);  
        for (int r = m - 2; r >= 0; --r) {
            max_down[r] = max(max_down[r + 1], dp[r] - k * r);
        }
        
        for (int r = 0; r < m; ++r) {
            dp[r] = grid[r][c] + max(max_up[r] - k * r, max_down[r] + k * r);
        }
    }
    
    ll result = *max_element(dp.begin(), dp.end());
    cout << result << endl;

    return 0;
}

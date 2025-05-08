#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
// We consider 61 bits (0..60) since k is capped at 1e18.
const int L = 61;
const ll K_LIMIT = 1000000000000000000LL;  // 1e18
 
// Helper function: returns the i-th bit (0-indexed, bit0 is LSB)
int getBit(ll num, int i) {
    return (num >> i) & 1;
}
 
// dp state: dp[pos][cx][cy][tight] where:
//   pos   = current bit position (from L-1 downto 0)
//   cx    = carry for (x + k) at this bit (0 or 1)
//   cy    = carry for (y + k) at this bit (0 or 1)
//   tight = whether we are bound by the K_LIMIT's bit at this pos (1 = yes, 0 = no)
// This function returns a valid k for the bits [pos...0] or -1 if impossible.
ll solve_dp(int pos, int cx, int cy, int tight,
            const vector<int>& xBits,
            const vector<int>& yBits,
            const vector<int>& kLimitBits,
            int dp[70][2][2][2],
            bool computed[70][2][2][2]) {
    if(pos < 0)
        return (cx == 0 && cy == 0) ? 0LL : -1LL;
    if(computed[pos][cx][cy][tight])
        return dp[pos][cx][cy][tight];
 
    ll ans = -1;
    // Try possible bit for k at current position (0 or 1)
    for (int b = 0; b < 2; b++) {
        if(tight && b > kLimitBits[pos])
            continue;
        int ntight = tight;
        if(tight && b < kLimitBits[pos])
            ntight = 0;
 
        // Compute (x + k)'s current bit and new carry
        int sum_x = xBits[pos] + b + cx;
        int bitA = sum_x & 1;
        int ncx = sum_x >> 1;
 
        // Compute (y + k)'s current bit and new carry
        int sum_y = yBits[pos] + b + cy;
        int bitB = sum_y & 1;
        int ncy = sum_y >> 1;
 
        // The condition (x+k) & (y+k) == 0 in this bit requires that both bits are not 1.
        if(bitA & bitB)
            continue;
 
        ll rec = solve_dp(pos - 1, ncx, ncy, ntight, xBits, yBits, kLimitBits, dp, computed);
        if(rec == -1)
            continue;
 
        // Set the current bit b in k and combine with the rest.
        ans = ((ll)b << pos) | rec;
        break; // any valid answer works
    }
 
    computed[pos][cx][cy][tight] = true;
    dp[pos][cx][cy][tight] = ans;
    return ans;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        ll x, y;
        cin >> x >> y;
        // If x equals y, then (x+k) == (y+k) so (x+k) ⊕ (y+k) == 0,
        // but (x+k)+(y+k) > 0 for any k >= 0. Hence, no solution.
        if(x == y){
            cout << "-1\n";
            continue;
        }
 
        // Precompute bit representations for x, y, and K_LIMIT.
        vector<int> xBits(L, 0), yBits(L, 0), kLimitBits(L, 0);
        for (int i = 0; i < L; i++){
            xBits[i] = getBit(x, i);
            yBits[i] = getBit(y, i);
            kLimitBits[i] = getBit(K_LIMIT, i);
        }
 
        // dp and computed arrays
        int dp[70][2][2][2];
        bool computed[70][2][2][2];
        memset(computed, 0, sizeof(computed));
 
        ll k = solve_dp(L - 1, 0, 0, 1, xBits, yBits, kLimitBits, dp, computed);
        cout << k << "\n";
    }
    return 0;
}
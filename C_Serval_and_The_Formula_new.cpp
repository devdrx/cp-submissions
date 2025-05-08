#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const int L = 61; // consider bits 60 down to 0
const ll K_LIMIT = 1000000000000000000LL; // 1e18
 
// We define a state using pos, carry_x, carry_y, tight.
// This state will be encoded into a single ll key for caching.
 
ll encodeState(int pos, int cx, int cy, int tight) {
    return (((ll)pos << 3) | (cx << 2) | (cy << 1) | tight);
}
 
// We'll use unordered_map for memoization.
unordered_map<ll, ll> memo;
 
// Helper function: get bit i (0-indexed, bit0 is LSB).
int getBit(ll num, int i) {
    return (num >> i) & 1;
}
 
// Recursive DP (from pos = L-1 downto 0).
// xBits, yBits, kLimitBits: bit representation of x, y, and K_LIMIT respectively.
ll solveDP(int pos, int cx, int cy, int tight,
           const vector<int>& kLimitBits,
           const vector<int>& xBits,
           const vector<int>& yBits) {
    if(pos < 0) {
        // if finished all bits, ensure no remaining carry.
        return (cx==0 && cy==0) ? 0 : -1;
    }
    ll state = encodeState(pos, cx, cy, tight);
    if(memo.find(state) != memo.end())
        return memo[state];
    
    ll ans = -1;
    // For current bit position, try k's bit b =0 or 1.
    for (int b = 0; b < 2; b++) {
        // If in a tight state, k's bit must not exceed K_LIMIT's bit.
        if(tight && b > kLimitBits[pos])
            continue;
        int ntight = tight;
        if(tight && b < kLimitBits[pos])
            ntight = 0;
 
        // Calculate the bit and new carry for (x+k) at this position.
        int sum_x = xBits[pos] + b + cx;
        int A = sum_x & 1;       // resulting bit of x+k.
        int ncx = sum_x >> 1;    // carry produced.
 
        // Similarly for (y+k):
        int sum_y = yBits[pos] + b + cy;
        int B = sum_y & 1;
        int ncy = sum_y >> 1;
 
        // The condition requires A and B are not both 1.
        if (A & B)
            continue;
 
        ll rec = solveDP(pos - 1, ncx, ncy, ntight, kLimitBits, xBits, yBits);
        if(rec == -1)
            continue;
        // Set k's bit b at this position.
        ans = (((ll) b) << pos) | rec;
        break; // return any valid answer
    }
    memo[state] = ans;
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
        // if x == y, then (x+k)==(y+k) => their XOR is zero, but their sum is >0.
        if(x == y){
            cout << "-1\n";
            continue;
        }
 
        // Prepare bit representations for x, y, and k-limit.
        vector<int> xBits(L,0), yBits(L,0), kLimitBits(L,0);
        for (int i = 0; i < L; i++){
            xBits[i] = getBit(x, i);
            yBits[i] = getBit(y, i);
            kLimitBits[i] = getBit(K_LIMIT, i);
        }
 
        memo.clear();
        ll k = solveDP(L-1, 0, 0, 1, kLimitBits, xBits, yBits);
        cout << k << "\n";
    }
    return 0;
}
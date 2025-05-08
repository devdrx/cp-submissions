#include <iostream>
using namespace std;

typedef long long ll;

ll maxDesksInRow(ll m, ll L) {
    ll q = m / (L + 1); 
    ll r = m % (L + 1); 
    return q * L + r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--){
        ll n, m, k;
        cin >> n >> m >> k;
        
        ll lo = 1, hi = m, ans = m;
        while(lo <= hi){
            ll mid = lo + (hi - lo) / 2;
            ll perRow = maxDesksInRow(m, mid);
            if(n * perRow >= k){
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}

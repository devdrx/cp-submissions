#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        ll H;
        cin >> N >> H;
        ll D1 = 0, D2 = 0;
        for (int i = 0; i < N; i++) {
            int S;
            ll D;
            cin >> S >> D;
            if (S == 1) D1 = max(D1, D);
            else if (S == 2) D2 = max(D2, D);
        }
        
        // If there's no way to deal any damage, impossible (though constraints guarantee D>=1)
        
        // Compute an upper bound on time
        const ll INF = LLONG_MAX / 4;
        ll hi = INF;
        if (D1 > 0) {
            hi = min(hi, (H + D1 - 1) / D1);
        }
        if (D2 > 0) {
            ll t2 = 2 * ((H + D2 - 1) / D2);
            hi = min(hi, t2);
        }
        if (hi == INF) {
            cout << -1 << '\n';
            continue;
        }
        
        // Binary search minimum t in [1..hi]
        ll lo = 1, ans = hi;
        while (lo <= hi) {
            ll mid = lo + ((hi - lo) >> 1);
            // compute max damage in time mid
            // decide optimal use of S=2 weapon or S=1
            ll damage;
            if (D2 > 2 * D1) {
                ll y = mid / 2;
                // damage = D1*mid + y*(D2 - 2*D1)
                damage = D1 * mid + y * (D2 - 2 * D1);
            } else {
                damage = D1 * mid;
            }
            if (damage >= H) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

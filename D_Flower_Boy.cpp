#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        vector<ll> a(n), b(m);
        for(ll &x: a) cin >> x;
        for(ll &x: b) cin >> x;

        // 1) build lpos
        const int INF = n;
        vector<int> lpos(m+1, -1);
        int idx = 0;
        for(int i = 0; i < m; i++){
            idx = lpos[i] + 1;
            while(idx < n && a[idx] < b[i]) idx++;
            if(idx < n) {
                lpos[i+1] = idx;
            } else {
                lpos[i+1] = INF;
            }
        }

        // 2) early exit: no-insert works?
        if(lpos[m] < n){
            cout << 0 << "\n";
            continue;
        }

        // 3) build rpos
        vector<int> rpos(m+1, n);
        idx = n-1;
        for(int i = m-1; i >= 0; i--){
            idx = rpos[i+1] - 1;
            while(idx >= 0 && a[idx] < b[i]) idx--;
            if(idx >= 0){
                rpos[i] = idx;
            } else {
                rpos[i] = -1;
            }
        }


        ll answer = LLONG_MAX;
        for(int t = 0; t < m; t++){
            if(lpos[t] < rpos[t+1]){
                answer = min(answer, b[t]);
            }
        }
        if(answer == LLONG_MAX) answer = -1;
        cout << answer << "\n";
    }
    return 0;
}

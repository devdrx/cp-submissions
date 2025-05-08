#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)4e18;

// Solve the “line” problem of length n, where choosing state x[p] ∈ {0,1} at each
// position p costs cost[p] if x[p]==1, and you have a forbidden set of transitions
// (u→v) at each edge (p→p+1) whenever D(k,p)==(v-u) for any k in [0..n).
// We return min total cost or INF if infeasible.
ll solve_line(int n,
              const vector<ll>& cost,
              function<ll(int,int)> D)
{
    // allowed[p][u][v] = true if we may go from x[p]=u to x[p+1]=v
    static vector<array<array<bool,2>,2>> allowed;
    allowed.assign(n-1, { array<bool,2>{true,true}, array<bool,2>{true,true} });

    // Build allowed[]
    for(int p = 0; p < n-1; p++){
        for(int u = 0; u < 2; u++){
            for(int v = 0; v < 2; v++){
                ll diff = v - u;
                for(int k = 0; k < n; k++){
                    if (D(k, p) == diff) {
                        allowed[p][u][v] = false;
                        break;
                    }
                }
            }
        }
    }

    // dp[p][u] = min cost to assign x[0..p] with x[p]=u
    vector<array<ll,2>> dp(n, {INF, INF});
    // base
    dp[0][0] = 0;
    dp[0][1] = cost[0];

    // transition
    for(int p = 0; p < n-1; p++){
        array<ll,2> nxt = {INF, INF};
        for(int u = 0; u < 2; u++){
            if (dp[p][u] >= INF) continue;
            for(int v = 0; v < 2; v++){
                if (!allowed[p][u][v]) continue;
                ll c = dp[p][u] + (v ? cost[p+1] : 0);
                nxt[v] = min(nxt[v], c);
            }
        }
        dp[p+1] = nxt;
    }

    return min(dp[n-1][0], dp[n-1][1]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<vector<ll>> h(n, vector<ll>(n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> h[i][j];

        vector<ll> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int j = 0; j < n; j++) cin >> b[j];

        // D_row(k, p) = h[p][k] - h[p+1][k]  (vertical adjacency at column k)
        auto D_row = [&](int k, int p) -> ll {
            return h[p][k] - h[p+1][k];
        };
        // D_col(k, p) = h[k][p] - h[k][p+1]  (horizontal adjacency at row k)
        auto D_col = [&](int k, int p) -> ll {
            return h[k][p] - h[k][p+1];
        };

        ll cost_x = solve_line(n, a, D_row);
        ll cost_y = solve_line(n, b, D_col);

        ll ans = (cost_x >= INF || cost_y >= INF)
                 ? -1 
                 : (cost_x + cost_y);

        cout << ans << "\n";
    }
    return 0;
}

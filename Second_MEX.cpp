#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static const int MOD = 998244353;

// fast exponentiation modulo MOD
ll modexp(ll a, ll e) {
    ll r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    const int MAXN = 200000 + 5;
    // precompute powers of two
    static ll pow2[MAXN];
    pow2[0] = 1;
    for (int i = 1; i < MAXN; i++)
        pow2[i] = pow2[i-1] * 2 % MOD;

    while (T--){
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        vector<int> freq(N+2, 0);
        for (int x : A)
            if (0 <= x && x <= N)
                freq[x]++;
        
        vector<ll> B(N+2);
        for (int i = 0; i <= N+1; i++)
            B[i] = (pow2[freq[i]] + MOD - 1) % MOD;

        // list of i<=(N+1) with B[i]==0
        vector<int> zeros;
        for (int i = 0; i <= N+1; i++)
            if (B[i] == 0)
                zeros.push_back(i);

        // prefix product over nonzero B's
        vector<ll> prodNZ(N+3, 1);
        // prefix sum of inverse B's
        vector<ll> sumInv(N+3, 0);
        for (int i = 0; i <= N+1; i++){
            if (B[i] != 0) {
                prodNZ[i+1] = prodNZ[i] * B[i] % MOD;
                // add inverse
                ll invBi = modexp(B[i], MOD-2);
                sumInv[i+1] = (sumInv[i] + invBi) % MOD;
            } else {
                prodNZ[i+1] = prodNZ[i];
                sumInv[i+1] = sumInv[i];
            }
        }

        ll ans = 0;
        int total = N;

        // k = 1 case
        {
            int suf = total - (freq[0] + freq[1]);
            ll R1 = pow2[max(0, suf)];
            ll T1 = (R1 + MOD - 1) % MOD;
            ans = (ans + T1 * 1) % MOD;
        }

        // k = 2..N+1
        for (int k = 2; k <= N+1; k++){
            // suffix power: values > k
            int used = 0;
            for (int i = 0; i <= k; i++) used += freq[i];
            int suf = total - used;
            ll Rk = pow2[max(0, suf)];

            // count zeros in [0..k-1]
            int zerosBelow = int(lower_bound(zeros.begin(), zeros.end(), k) - zeros.begin());
            if (zerosBelow >= 2) 
                continue;
            ll Tk = 0;
            if (zerosBelow == 1) {
                // only one zero at zeros[0]
                // product over i<k, i!= zeros[0] is prodNZ[k]
                Tk = Rk * prodNZ[k] % MOD;
            } else {
                // no zeros: regular formula
                ll prodAll = prodNZ[k];
                ll sumI = sumInv[k];
                Tk = Rk * prodAll % MOD * sumI % MOD;
            }
            ans = (ans + Tk * k) % MOD;
        }

        cout << ans << "\n";
    }
    return 0;
}

#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define fr(i, n) for (int i = 0; i < (n); i++)
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define nl cout << "\n"
#define dbg(var) cerr << #var << "=" << var << " "
#define all(v) v.begin(), v.end()
#define srt(v) sort(v.begin(), v.end())         // sort
#define mxe(v) *max_element(v.begin(), v.end()) // find max element in vector
#define mne(v) *min_element(v.begin(), v.end()) // find min element in vector
#define unq(v) v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed
#define bin(x, y) bitset<y>(x)
using namespace std;
int MOD = 1e9 + 7; // Hardcoded, directly change from here for functions!

const int MX_SZ = 1e5 + 5;
int par[MX_SZ];

void modadd(int &a, int b) { a = ((a % MOD) + (b % MOD)) % MOD; }
void modsub(int &a, int b) { a = ((a % MOD) - (b % MOD) + MOD) % MOD; }
void modmul(int &a, int b) { a = ((a % MOD) * (b % MOD)) % MOD; }
// ================================== take ip/op like vector,pairs directly!==================================
template <typename typC, typename typD>
istream &operator>>(istream &cin, pair<typC, typD> &a) { return cin >> a.first >> a.second; }
template <typename typC>
istream &operator>>(istream &cin, vector<typC> &a)
{
    for (auto &x : a)
        cin >> x;
    return cin;
}
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const pair<typC, typD> &a) { return cout << a.first << ' ' << a.second; }
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a)
{
    for (auto &x : a)
        cout << x << '\n';
    return cout;
}
template <typename typC>
ostream &operator<<(ostream &cout, const vector<typC> &a)
{
    int n = a.size();
    if (!n)
        return cout;
    cout << a[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << a[i];
    return cout;
}
// ===================================END Of the input module ==========================================

/// ====================================PRIME utility ==================================================
int sz = 1e6 + 5;
bool PrimeSieve[1000005]; // 1e6+5
void buildSieve()
{
    for (int i = 2; i <= sz; i++)
        PrimeSieve[i] = 1;
    PrimeSieve[0] = 0; //
    PrimeSieve[1] = 0; // 1 is neither prime nor composite
    for (int i = 2; i < sz; i++)
    {
        if (PrimeSieve[i] == 0)
            continue; // the current number itself is composite
        for (int j = 2; j * i < sz; j++)
        {
            PrimeSieve[i * j] = 0;
        }
    }
}
// add SieveOfEratosthenes
bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

/// ====================================PRIME utility ENDS here==================================================

// ========================================MATH UTIL BEGINS==============================================
//==================================== compute higher powers with mod ===================================
uint power(int x, int y, int p = MOD)
{
    unsigned long long res = 1;

    x = x % p;
    while (y > 0)
    {

        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

// =============================================================================================================

uint modInverse(int n, int p = MOD) // using fermats little thm. [p needs to be prime which is mostly the case as mod value generally is 1e9+7]
{
    return power(n, p - 2, p);
}
// can also derive this using extended euclidean... however this has a much simpler code....

// =========================================Used to calculate nCr of higher values ===================================
uint nCr(int n, int r, int p = MOD) // faster calculation..
{
    if (n < r)
        return 0;

    if (r == 0)
        return 1;

    vector<int> fac(n + 1, 0);
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}
// ==================================== MATH UTIL ENDS=======================================================//
const int MAXV = 200000;

vector<int> allPrimes;

vector<int> sievePrimes(int maxVal) {
    vector<bool> isPrime(maxVal+1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= maxVal; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= maxVal; j += i)
                isPrime[j] = false;
        }
    }
    vector<int> primes;
    for (int i = 2; i <= maxVal; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
    return primes;
}


void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    vector<int> primes;
    for (int p : allPrimes)
    {
        if (p > n)
            break;
        primes.push_back(p);
    }

    int ans = 0;
    int sz = primes.size();
    for (int i = 0; i < sz; i++)
    {
        int p = primes[i];
        int L = p * p;
        if (L <= n)
        {
            ans += freq[p] * freq[p * p] + freq[p * p] * (freq[p * p] + 1) / 2;
        }
        for (int j = i + 1; j < sz; j++)
        {
            int q = primes[j];
            int candidate = p * q;
            if (candidate <= n)
            {
                ans += freq[p] * freq[q] + freq[p] * freq[candidate] + freq[q] * freq[candidate] + freq[candidate] * (freq[candidate] + 1) / 2;
            }
            else
            {
                ans += freq[p] * freq[q];
            }
        }
    }

    cout << ans << "\n";

    // noum
    // i{}el{}ord
    // cCas
    // tleopt
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    cin >> T;
    allPrimes = sievePrimes(MAXV);
    while (T--)
    {
        solve();
    }
    return 0;
}

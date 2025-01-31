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

char ar[1001][1001]; // input
char br[1001][1001];  // parent
bool vis[1001][1001];
int n, m;
vector<char> path;

bool isValid(int x , int y){
	
	if(x < 1 || x > n || y < 1 || y > m) return false;
	
	if(ar[x][y] == '#' || vis[x][y] == true) return false;
	
	return true;
}


bool bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;

    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        if (ar[a][b] == 'B')
        {
            while (1)
            {
                path.push_back(br[a][b]);

                if (path.back() == 'L')
                    b++;
                if (path.back() == 'R')
                    b--;
                if (path.back() == 'U')
                    a++;
                if (path.back() == 'D')
                    a--;

                if (a == x && b == y)
                    break;
            }
            return true;
        }

        // left
        if (isValid(a, b - 1))
            br[a][b - 1] = 'L', q.push({a, b - 1}), vis[a][b - 1] = true;

        // right
        if (isValid(a, b + 1))
            br[a][b + 1] = 'R', q.push({a, b + 1}), vis[a][b + 1] = true;

        // up
        if (isValid(a - 1, b))
            br[a - 1][b] = 'U', q.push({a - 1, b}), vis[a - 1][b] = true;

        // down
        if (isValid(a + 1, b))
            br[a + 1][b] = 'D', q.push({a + 1, b}), vis[a + 1][b] = true;
    }

    return false;
}

void solve()
{
    cin >> n >> m;
    int x; // starting point
    int y;

    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            cin >> ar[i][j];
            if (ar[i][j] == 'A')
                x = i, y = j;
        }
    }

    if (bfs(x, y) == true)
    {
        cout << "YES" << endl
             << path.size() << endl;
        while (path.size() > 0)
            cout << path.back(), path.pop_back();
    }
    else
    {
        cout << "NO";
    }
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
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define nl cout<<"\n"
#define dbg(var) cout<<#var<<"="<<var<<" "
#define all(v) v.begin(),v.end()
#define srt(v)  sort(v.begin(),v.end())         // sort 
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed 
#define bin(x,y)  bitset<y>(x) 
using namespace std;
int MOD=1e9+7;      // Hardcoded, directly change from here for functions!

const int MX_SZ=1e5+5;
int par[MX_SZ];


void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}
// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================


constexpr int N = 200005; // No. of vertices
constexpr int L = 20; // ceil(logN / log2) + 1

// Vertices from 1 to N.
vector<int> adj[N + 1];
int up[N + 1][L];
int level[N + 1];

void dfs(int u, int prev = 0){
 up[u][0] = prev;
 for (auto &v : adj[u]){
     if (v == prev) continue;

     level[v] = level[u] + 1;
     dfs(v, u);
 }
}

void binaryLift(){
 dfs(1);
 for (int i = 1; i < L; i++)
     for (int j = 1; j <= N; j++)
          up[j][i] = up[up[j][i - 1]][i - 1];
}

int LCA(int a, int b){
 if (level[a] > level[b])
     swap(a, b);

 int diff = level[b] - level[a];
 for (int i = 0; i < L; i++){
     if ((diff & (1 << i)))
         b = up[b][i];
 }

 if (a == b) return a;

 for (int i = L - 1; i >= 0; i--){
     if (up[a][i] != up[b][i]){
         a = up[a][i];
         b = up[b][i];
     }
 }
 return up[a][0];
}

void addEdge(int u, int v){
 adj[u].push_back(v);
 adj[v].push_back(u);
}

int dist(int a, int b){
 return level[a] + level[b] - 2 * level[LCA(a, b)];
}
/// ====================================PRIME utility ==================================================
int sz=1e6+5;
bool PrimeSieve[1000005];   // 1e6+5
void buildSieve(){
    for(int i=2;i<=sz;i++)    PrimeSieve[i]=1;
    PrimeSieve[0]=0;// 
    PrimeSieve[1]=0;    // 1 is neither prime nor composite 
    for(int i=2;i<sz;i++){
        if(PrimeSieve[i]==0)    continue;       // the current number itself is composite 
        for(int j=2;j*i<sz;j++){
            PrimeSieve[i*j]=0;
        }
    }
}
// add SieveOfEratosthenes
bool isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)  return 0;
    }
    return 1;
}

/// ====================================PRIME utility ENDS here==================================================

// ========================================MATH UTIL BEGINS==============================================
//==================================== compute higher powers with mod ===================================
uint power(int x, int y, int p =  MOD)
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

uint modInverse(int n, int p=MOD)       // using fermats little thm. [p needs to be prime which is mostly the case as mod value generally is 1e9+7]
{
    return power(n, p - 2, p);
}
// can also derive this using extended euclidean... however this has a much simpler code....


// =========================================Used to calculate nCr of higher values ===================================
uint nCr(int n, int r, int p=MOD)     // faster calculation.. 
{
    if (n < r)
        return 0;

    if (r == 0)
        return 1;
        
    vector<int> fac(n+1,0);
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}
// ==================================== MATH UTIL ENDS=======================================================//


void solve(){
    // int n;
    // cin>>n;
    // vi v(n);
    // cin>>v;
    // vi a = v;
    // int f = 0;
    // for(int i = 0; i < n; i++){
    //     if(v[i]!=i+1){
    //         f = 1;
    //         break;
    //     }
    // }
    // if(f==0){
    //     cout<<"yes\n1 1\n";
    //     return;
    // }
    // vector<pair<int,int>> pp(n);
    // fr(i,n){
    //     pp[i].first = v[i];
    //     pp[i].second = i+1;
    // }
    // sort(all(pp));
    // //check if array a and array pp.second is equal or not
    // fr(i,n){
    //     if(a[i]!=pp[i].second){
    //         cout<<"no\n";
    //         return;
    //     }
    // }
    // cout << "yes\n";
    // int l = 1, r = n;
    // for(int i = 0; i < n; i++){
    //     //find the first index of a[i] where a[i] != i+1
    //     if(a[i]==i+1) l++;
    //     else{
    //         l = i+1;break;
    //     }
    // }
    // for(int i = n-1; i >= 0; i--){
    //     //find the first index of a[i] where a[i] != i+1
    //     if(a[i]==i+1) r--;
    //     else{
    //         r = i+1;break;
    //     }
    // }
    // cout << l << " " << r << endl;

    //my assumption that the array was actually a permutation was incorrect
    //instead made the array a permutation and work on it as usual
    int n;
	cin >> n;
    int a[n], b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	map<int, int> mp;
	sort(b, b + n);
	for (int i = 0; i < n; i++) {
		mp[b[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		a[i] = mp[a[i]]; //giving a_i their permutation based values
	}
    //continue as usual
	int L = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] != i) {
			L = i;
			break;
		}
	}
	int R = -1;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] != i) {
			R = i;
			break;
		}
	}
	if (L == -1 || R == -1) {
		cout << "yes" << endl;
		cout << 1 << " " << 1 << endl;
	} else {
		reverse(a + L, a + R + 1);
		int ok = true;
		for (int i = 0; i < n; i++) {
			if (a[i] != i) {
				ok = false;
			}
		}
		if (ok) {
			cout << "yes" << endl;
			cout << L + 1 << " " << R + 1 << endl;
		} else {
			cout << "no" << endl;
		}
	}
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

    
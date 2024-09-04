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
#define dbg(var) cerr<<#var<<"="<<var<<" "
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
    int n, m, cnt = 0;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    //storing indexes of all these characters.
    vvi ls(26);
    vi lq;
    vvi rs(26);
    vi rq;
    fr(i,n){
        if(s1[i]=='?')  lq.push_back(i);
        else    ls[s1[i]-'a'].push_back(i);
        if(s2[i]=='?')  rq.push_back(i);
        else    rs[s2[i]-'a'].push_back(i);
    }
    vi cntl(26), cntr(26);
    vector<pair<int,int>> ans;

    //pairing same letters together
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < min(ls[i].size(), rs[i].size()); j++){
            ans.push_back({ls[i][j] + 1, rs[i][j] + 1});
        }
        cntl[i] = min(ls[i].size(), rs[i].size()); //how many pairs created
        cntr[i] = cntl[i];
    }

    //pairing letters in right with '?'
    for(int i = 0; i < 26; i++){
        while(cntr[i] < rs[i].size() && lq.size() > 0){
            ans.push_back({lq.back() + 1, rs[i][cntr[i]] + 1});
            cntr[i]++;
            lq.pop_back();
        }
    }
    //pairing letters in left with '?'
    for(int i = 0; i < 26; i++){
        while(cntl[i] < ls[i].size() && rq.size() > 0){
            ans.push_back({ls[i][cntl[i]] + 1, rq.back() + 1});
            cntl[i]++;
            rq.pop_back();
        }
    }
    //pairing '?' with '?'
    while(lq.size() > 0 && rq.size() > 0){
        ans.push_back({lq.back() + 1, rq.back() + 1});
        lq.pop_back();
        rq.pop_back();
    }
    cout << ans.size() << endl;
    for(auto x: ans){
        cout << x.first << " " << x.second << endl;
    }

    

    //noum
    //i{}el{}ord
    //cCas
    //tleopt

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

    
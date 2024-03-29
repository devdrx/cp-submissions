#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
using namespace std;

void solve(){
    // int n=1,nq=0;
    // string s;
    // cin>>n>>nq;
    // vi v(n);
    // for(int i = 0; i < n; i++){
    //     cin >> v[i];
    // }
    // int arr[n];
    // arr[0] = v[0];
    // for(int i = 1; i < n; i++){
    //     arr[i] = arr[i-1] + v[i];
    // }
    // for(int i = 0; i< nq; i++){
    //     int l, r, k;
    //     cin >> l >> r >> k;
    //     int sum = arr[n-1];
    //     if((sum-arr[r-1]+arr[l-2]+(r-l+1)*k)%2==1){
    //         cout << "YES" << endl;
    //     }
    //     else cout << "NO" << endl;
    // }

    //SOMEHOW FAILS IN ONLINE JUDGE WTFFFFFF

    long long n,a[200005],q,sum=0,pref[200005],t;
    sum = 0;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sum+=a[i];
        pref[i]=pref[i-1];
        pref[i]+=a[i];
    }
    for(int i = 0; i < q; i++){
        long long l,r,k;
        cin >> l >> r >> k;
        long long ans = pref[n]-(pref[r]-pref[l-1])+k*(r-l+1);
        if(ans%2==1){
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

    
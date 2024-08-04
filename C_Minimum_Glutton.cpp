#include <bits/stdc++.h>

#define int long long
#define pb push_back

using namespace std;


void solve(){
    int n,sw,sa;
    cin>>n>>sw>>sa;
    vector<int> sweet(n),salty(n);
    for(int i=0;i<n;i++){
        cin>>sweet[i];
    }
    for(int i=0;i<n;i++){
        cin>>salty[i];
    }
    sort(sweet.begin(),sweet.end(),greater<int>());
    sort(salty.begin(),salty.end(),greater<int>());
    int sumsweet=0,sumsalty=0;
    int ans1=n;
    for(int i=0;i<n;i++){
        sumsweet+=sweet[i];
        if(sumsweet>sw){
            ans1=i+1;
            break;
        }    
    }
    int ans2=n;
    for(int i=0;i<n;i++){
        sumsalty+=salty[i];
        if(sumsalty>sa){
            ans2=i+1;
            break;
        }
    }
    cout<<min(ans1,ans2)<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //uncomment for multiple test cases
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
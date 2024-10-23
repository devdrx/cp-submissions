#include <bits/stdc++.h>


#define int long long
#define pb push_back

using namespace std;


void solve(){
    int n,k;
    cin>>n>>k;
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    if(k<5){
        cout<<0<<endl;
        return;
    }
    if(k==26){
        cout<<n<<endl;
        return;
    }
    k-=5;
    vector<string> rem;
    for(int i=0;i<n;i++){
        set<char>temp;
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]=='a' || v[i][j]=='n' || v[i][j]=='t' || v[i][j]=='i' || v[i][j]=='c'){
                continue;
            }
            else{
                temp.insert(v[i][j]);
            }
        }
        string tmp="";
        for(auto j:temp){
            tmp.pb(j);
        }
        rem.pb(tmp);

    }
    int ans=0;
    // for(int i=0;i<n;i++){
    //     cout<<rem[i]<<endl;
    // }
    

    
    for(int i=0;i<rem.size();i++){
        if(rem[i].size()>k){
            continue;
        }
        int xx=0;
        vector<char> mask(26,0);
        int cnt=0;
        int cnt2=0;
        for(int j=0;j<rem[i].size();j++){
            if(mask[rem[i][j]-'a']==0){
                mask[rem[i][j]-'a']=1;
                cnt++;
            }
        }
        for(int j=0;j<rem.size();j++){
            if(rem[j].size()>k) continue;
            for(int l=0;l<rem[j].size();l++){
                if(rem[j][l]=='a' || rem[j][l]=='n' || rem[j][l]=='t' || rem[j][l]=='i' || rem[j][l]=='c'){
                    continue;
                }
                if((mask[rem[j][l]-'a'])==0){
                    cnt2++;
                }
            }
            if((cnt+cnt2)<=k){
                xx++;
            }
        }
        ans=max(ans,xx);
    }
    cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

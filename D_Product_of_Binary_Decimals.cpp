#include<bits/stdc++.h>
using namespace std;

bool check(int n){
    while(n>0){
        int r=n%10;
        if(r==1 || r==0){
            n=n/10;
            continue;
        }
        return false;
    }
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v;
    for(int i=1;i<=1e5;i++){
        if(check(i)){
            v.push_back(i);
        }
    }
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int ix=v.size()-1;
        while(n>0 && ix>=0){
            if(n%v[ix]==0 && v[ix]!=1){
                n=n/v[ix];
                continue;
            }
            ix--;
        }
        if(n>1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    
}

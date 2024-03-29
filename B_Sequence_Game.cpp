#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
         cin>>n;
         vector < long long > v(n),res;
         for(long long i = 0 ; i < n ; i++) {
            cin>>v[i];
         }
         res.push_back(v[0]);
         for(long long i = 1; i < n ; i++) {
           if(v[i-1] > v[i]) {
            res.push_back(v[i]);
            res.push_back(v[i]);
           }
           else
            res.push_back(v[i]);
         }
         cout<<(long long)res.size()<<endl;
         for(long long i = 0 ; i < (long long)res.size() ; i++){
            cout<<res[i]<<" ";
         }
         cout<<endl;
    }
}
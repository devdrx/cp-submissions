#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#define int long long
using namespace std;


int32_t main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int m; cin >> m;
        if(m+n<11 ||  m<4 || n<4){
            cout << -1 << endl;
            continue;
        }
        int v1[n];
        int v2[m];
        for(int i = 0; i < n; i++){
            cin >> v1[i];
        }
        for(int i = 0; i < m; i++){
            cin >> v2[i];
        }

        sort(v1, v1+n);
        sort(v2, v2+m);
        
        
    }
    
}


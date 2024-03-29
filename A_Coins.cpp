#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(n%2==0) cout << "YES";
        else if((n-k)%2==0) cout << "YES";
        else cout << "NO";

        cout << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;

    while(t--){
        int a, b;
        cin >> a >> b;
        if(b%a==0) cout << b * b / a;
        else cout << b*a/__gcd(a, b);
        cout << endl;
    }
}
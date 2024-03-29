#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n;
    cin >> n;

    for(int i=1 ; i<=n; i++){
        cout << (i*i)*(i*i-1)/2 - (i-1)*(i-2)*4<<endl;
    }
}
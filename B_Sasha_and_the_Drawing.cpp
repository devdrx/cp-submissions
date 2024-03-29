#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n , k ;
        cin >> n >> k;
        if(k<=4*n-4) cout << k/2 + k%2;
        else cout << k/2+1;
        cout << endl;
    }
}
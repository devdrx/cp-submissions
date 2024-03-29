#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n; 
    cin >> n;

    while(n--){
        int r, c;
        cin >> r >> c;
        if(r==c){
            cout << r*(c-1) + 1 << endl;
        }
        else if(r<c){
            cout <<   ((c&1^1)?c*c-2*c+r+1:(c-1)*(c-1) +2*c-r) <<endl;
        }
        else cout << ((r&1)?r*(r-1)+1-(r-c):r*(r-1)+1+r-c) <<endl;
    }
}
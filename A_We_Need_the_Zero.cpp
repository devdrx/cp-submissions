#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int xorry;
        cin >> xorry;
        int temp;
        for(int i=1; i<n; i++){
            cin >> temp;
            xorry = xorry^temp; 
        }
        if(n%2==0){
            if(xorry==0) cout << xorry;
            else cout << -1;
        }
        else {
            cout << xorry;
        }
        cout << endl;
    }
}

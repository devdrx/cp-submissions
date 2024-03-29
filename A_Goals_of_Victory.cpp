#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int count = 0;
        int t;
        for(int i = 0; i<n-1; i++){
            cin >> t;
            count += t;
        }
        cout << 0-count << endl;
    }
}

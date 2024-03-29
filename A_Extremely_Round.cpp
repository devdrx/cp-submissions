#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int temp = n;
        int dig = 0;
        while(n!=0){
            dig++;
            n/=10;
        }
        int ans = temp/pow(10,dig-1) + 9*(dig-1);
        cout << ans << endl;
    }
}

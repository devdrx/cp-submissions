#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, s;
        cin >> n >> s;
        string s1, s2;
        cin >> s1 >> s2;
        int count = 6;
        int f = 0;
        int ans = 0;
        while(count--){
            if(s1.find(s2) != string::npos){
                f = 1; break;
            }
            ans++;
            s1+=s1;
        }
        if(f==1)
        cout << ans;
        else cout << -1;
        cout << endl;
    }
}

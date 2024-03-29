#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int flag = 0;
        int count = 0;
        for(int i = 0; i<n; i++){
            if(s[i]=='.') count++;
            if(i>=1){
                if(s[i]==s[i-1]&&s[i]==s[i+1]&&s[i]=='.') flag = 1;
            }
        }
        // cout << count;
        if(flag == 1) cout << 2;
        else cout << count;
        cout << endl;
    }
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++) cin >> arr[i];

        vector<int> ans(n);
        ans[0] = arr[0];
        ans[1] = arr[0] + arr[1];
        cout << ans[0] << " " << ans[1] << " ";
        for(int i=1; i< n-1; i++){
            if(ans[i+1]%2!=arr[i+1]%2){ans[i+1] = ans[i] + arr[i+1] + (i%2?-1:+1); cout << "first ";}
            else ans[i+1] = ans[i] + arr[i+1];
            cout << ans[i+1] << " ";
         }
        // for(int i=0; i<n; i++) cout << ans[i] << " ";
    }
}
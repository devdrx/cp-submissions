#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        int mini = INT_MAX;
        for(int i = 0; i<n; i++){
            cin >> arr[i];
            mini = min(mini, arr[i]);
        }
        if (arr[0]==mini) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}

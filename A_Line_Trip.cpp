#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int arr[n];
        for(int i = 0; i<n; i++){
            cin >> arr[i]; 
        }
        int excess = k-arr[n-1];
        int maxi = arr[0];
        for(int i = 1; i<n; i++){
            maxi = max(arr[i]-arr[i-1], maxi);
        }
        if(maxi > 2*excess) cout << maxi << endl; 
        else cout << 2*excess << endl;
    }
}

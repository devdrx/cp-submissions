#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        int arr[n];
        int flag = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(i>0){
            if(arr[i]<arr[i-1]) flag = 1; 
            }
        }
        if(flag == 1){cout << 0 << endl; continue;}

        int mini = INT_MAX;
        for(int i = 0; i < n-1; i++){
            mini = min(mini, abs(arr[i]-arr[i+1]));
        }
        cout << mini/2+1;
        cout << endl;
    }
}

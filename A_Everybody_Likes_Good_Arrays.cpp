#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i<n; i++){
            cin >> arr[i];
        }
        for(int i = 0; i<n; i++){
            if(arr[i]%2==1){
                arr[i]=1;
            }
            else{
                arr[i]=0;
            }
        }
        int x=0;
        for(int i =0; i<n-1; i++){
            if(arr[i]!=arr[i+1]) x++;
        }
        cout << n-x-1 << endl;
    }
}
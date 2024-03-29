#include<bits/stdc++.h>
using namespace std;

int noOfOnes(int n){
    int count=0;
    while(n){
        if(n%10==1){
            count++;
        }
        n/=10;
    }
    return count;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        int count = 0;
        for(int i =0; i<n; i++){
            cin >> arr[i];
        }
        // for(int i = 0; i<n; i++){
        //     cout << arr[i] << endl;
        // }
        for(int i =0; i<n; i++){
            if(arr[i]==0) continue;
            if(arr[i]==arr[i+1]) {cout << "SQUARE"; break;}
            // else if(noOfOnes(arr[i+1])-noOfOnes(arr[i])==2) 
            else
            cout << "TRIANGLE"; break;
        }
        cout << endl;
    }
}
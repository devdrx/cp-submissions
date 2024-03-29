#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        int oddc = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i]%2==1) oddc++;
        }
        if(oddc%2==0) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}
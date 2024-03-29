#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++){
           cin >> arr[i];
        }
        int flag = 0;
        for(int i = 0; i < n-1; i++){
            if(arr[i]!=arr[i+1]) {flag = 1; break;}
        }
        if(flag == 0) {cout << -1 << endl; continue;}
        else
        sort(arr, arr+n);
        vector<int> b,c; int i = 1;
        b.push_back(arr[0]);
        while(flag){

            if(arr[i-1]==arr[i]) b.push_back(arr[i]);
            else flag = 0;
            i++;
        }
        --i;
        while(i<n){
            c.push_back(arr[i]);
            i++;
        }

        cout << b.size() << " " << c.size() << endl;

        for(auto x : b) cout << x << " ";
        cout << endl;

        for(auto x : c) cout << x << " ";
        cout << endl;
    }
}

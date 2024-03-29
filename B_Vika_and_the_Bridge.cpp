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

        for(int i = 0; i < n; i++){
            cout << arr[i];
        }
        // vector<vector<int>> pp;
        // for(int i =0; i < n; i++){
        //     pp[arr[i]].push_back(i);
        // }

        // for(auto uwu : pp){
        //     for(auto wuw : uwu){
        //         cout << wuw << " ";
        //     }
        //     cout << endl;
        // }

        cout << endl;
    }
}

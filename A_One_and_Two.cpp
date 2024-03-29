#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        vector<int> twos;
        int flag = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i]==2){
                flag = 1;
                twos.push_back(i);
            }
        }
        // for(auto x : twos){
        //     cout << x << " ";
        // }
        if(flag == 0){
            cout << 1;
        }
        else if(twos.size()%2==0){
            cout << twos[twos.size()/2-1]+1;
        }
        else cout << -1;
        cout << endl;
    }
}

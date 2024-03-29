
#include<bits/stdc++.h>
using namespace std;

map<int, int> countFrequency(const vector<int>& arr) {
    map<int, int> frequency;

    for (int num : arr) {
        frequency[num]++;
    }

    return frequency;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr;
        map<int,int> mp;
        int temp;
        for(int i = 0; i<n; i++){
            cin >> temp;
            arr.push_back(temp);
        }
        // for(auto x : arr){
        //     cout << x << " ";
        // }
        mp = countFrequency(arr);

        
        // cout << mp.size() << " ";
        auto endit = --mp.end();
        int uno= mp.begin()->second;
        int secundo = endit->second;
        
        if(mp.size()==2 && abs(uno-secundo)<2){
            cout << "YES ";
        }
        else if(mp.size()==1) cout << "YES";
        else cout << "NO";

        cout << endl;
    }
}

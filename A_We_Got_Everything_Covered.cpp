#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;


    while(t--){
        int n , k;
        cin >> n >> k;
        char c = 'a';
        string s = "";
        for(int i = 0; i < n; i++){
            for(int j = 0; j<k; j++){
                s.push_back(c+j);
            }
        }

        for(auto c: s){
            cout << c;
        }
        cout << endl;
    }

}
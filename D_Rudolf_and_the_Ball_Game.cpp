#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, x, t1; char t2;
        cin >> n >> m >> x;
        vector<pair<int, char>> pp;
        for(int i = 0; i < m; i++){
            cin >> t1 >> t2;
            pp.push_back(make_pair(t1,t2));
        }
        set<int> setto;
        for(auto uwu : pp){
            if(uwu.second==1)
                setto.insert(x-uwu.first%n);
            else if(uwu.second==0)
                setto.insert(x+uwu.first%n);
            else{
                setto.insert(x+uwu.first%n);
                setto.insert(x-uwu.first%n);
            }
        }
        cout << setto.size() << endl;
        for(auto uwu : setto){
            cout << uwu << " ";
        }
    }
}

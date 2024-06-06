#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;char trump; cin >> trump; string str =""; 
        vector<string> cardc; 
        vector<string> cardd;
        vector<string> cardh; 
        vector<string> cards;
        int c = 0, d = 0, h = 0, s = 0;
        for(int i = 0; i<2*n; i++){
            string temp;
            cin >> temp;
            if(temp[1] == 'C'){c++; cardc.push_back(temp); }
            else if(temp[1] == 'D'){ d++; cardd.push_back(temp);}
            else if(temp[1] == 'H') {h++;cardh.push_back(temp);}
            else {s++;cards.push_back(temp);}
        }
        sort(cardc.begin(), cardc.end()); sort(cardd.begin(), cardd.end()); sort(cardh.begin(), cardh.end()); sort(cards.begin(), cards.end());
        
        
    }
}
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
        
        vector<vector<string>> vect;
        vector<string> temp;

        if(trump=='C'){
            if(c<n) cout <<"IMPOSSIBLE"<<endl;
            else 
            {   
                int count = 0;
                for(int i = 0; ;i+=2){
                    if(c!=d+h+s){ vect.push_back({cardc[i], cardc[i+1]}); c-=2;count+=2;}
                    else break;
                }
                int id = 0, ih = 0, is = 0;
                for(int i = 0; i<c; i++){
                    if(id<d){
                        vect.push_back({cardd[id++], cardc[count++]});
                    }
                    else if(ih<h){
                        vect.push_back({cardh[ih++], cardc[count++]});
                    }
                    else if(is<s){
                        vect.push_back({cards[is++], cardc[count++]});
                    }
                }
            }
        }
        if(trump=='D'){
            if(d<n) cout <<"IMPOSSIBLE"<<endl;
            else 
            {   
                int count = 0;
                for(int i = 0; ;i+=2){
                    if(d!=c+h+s){ vect.push_back({cardd[i], cardd[i+1]}); d-=2;count+=2;}
                    else break;
                }
                int ic = 0, ih = 0, is = 0;

                for(int i = 0; i<d; i++){
                    if(ic<c){
                    vect.push_back({cardc[ic++], cardd[count++]});
                    }
                    else if(ih<h){
                    vect.push_back({cardh[ih++], cardd[count++]});
                    }
                    else if(is<s){
                    vect.push_back({cards[is++], cardd[count++]});
                    }
                }
            }
        }
        if(trump=='H'){
            if(h<n) cout <<"IMPOSSIBLE"<<endl;
            else 
            {   
                int count = 0;
                for(int i = 0; ;i+=2){
                    if(h!=c+d+s){ vect.push_back({cardh[i], cardh[i+1]}); h-=2;count+=2;}
                    else break;
                }
                int ic = 0, id = 0, is = 0;
                for(int i = 0; i<h; i++){
                    if(id<d){
                    vect.push_back({cardd[id++], cardh[count++]});
                    }
                    else if(ic<c){
                    vect.push_back({cardc[ic++], cardh[count++]});
                    }
                    else if(is<s){
                    vect.push_back({cards[is++], cardh[count++]});
                    }
                }
            }
        }
        if(trump=='S'){
            if(s<n) cout <<"IMPOSSIBLE"<<endl;
            else 
            {   
                int count = 0;
                for(int i = 0; ;i+=2){
                    if(s!=c+h+d){ vect.push_back({cards[i], cards[i+1]}); s-=2;count+=2;}
                    else break;
                }
                int ic = 0, ih = 0, id = 0;
                for(int i = 0; i<s; i++){
                    if(ic<c){
                    vect.push_back({cardc[ic++], cards[count++]});
                    }
                    else if(ih<h){
                    vect.push_back({cardh[ih++], cards[count++]});
                    }
                    else if(id<d){
                    vect.push_back({cardd[id++], cards[count++]});
                    }
                }
            }
        }
        

        for(auto s: vect){
            for(auto r: s){
                cout << r << " ";
            }
            cout << endl;
        }
    }
}
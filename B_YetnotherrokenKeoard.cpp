#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s1;
        cin >> s1;
        // string s2,s3;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i]=='b'){
                s1.erase(i,1);
                cout << s1 << " HIT b" <<  endl;
                int j = i;
                while(j--){
                    if(islower(s1[j])) {s1.erase(j,0);break;}
                }
                cout << s1 << " HIT b" <<  endl;
            }
            if(s1[i]=='B'){
                s1.erase(i,1);
                cout << s1 << " HIT B" <<  endl;
                int j = i;
                while(j--){
                    if(isupper(s1[j])) {s1.erase(j,0);break;}
                }
                cout << s1 << " HIT B" <<  endl;
            }
        }

        cout << s1 << endl;
    }
}
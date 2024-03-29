#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string str, str2;
    cin>>str>>str2;
    map<char, int> mpstr;
    // map<char, int> mpstr2;
    int p2 = str2.size()-1;  //first we initialize pointers to the end of the strings
    int p1 = str.size()-1;
    while(p2>=0 && p1>=0){ //while both of them are greater than 0th index
        if(str[p1]==str2[p2]){   //if the characters match
            if(mpstr[str[p1]]>0){   //and the character already exists once in map
                cout<<"NO"<<endl;   //then print no
                return;
            }
            p2--;    //if its doesn't then move pointers backward
            p1--;
        }
        else{
            mpstr[str[p1]]++;  //if characters don't match then increment the hash , these are the characters that got deleted.
            p1--;              //and move the pointer of string 1 backward
        }
    }
    if(p2>=0){                 //if after all the operations, p2 pointer is not covering the string, cout NO 
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;         //else cout yes
    

}
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    int n;
    int mini = INT_MAX;
    for(int i = 0; i<t; i++){
        cin >> n;
        mini = min(mini, abs(n));
    }
    cout << mini;
}

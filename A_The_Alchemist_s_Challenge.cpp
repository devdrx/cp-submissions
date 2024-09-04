#include <bits/stdc++.h>
using namespace std;
#define int long long


bool ok2(int n, int x, int y, int mid, int numba){
    return mid*y + (n-mid)*x >= numba;
}

bool ok(vector<int> &a, int mid, int x, int y){
    int n = a.size();
    // mid operations
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        int s1 = 0;
        int e1 = a[i];
        while(s1 < e1){
            int m1 = s1 + (e1-s1)/2;
            if(ok2(mid, x, y, m1, a[i])){
                e1 = m1;
            }
            else{
                s1 = m1 + 1;
            }
        }
        // cout << s1 << " " << a[i] << endl;
       
        cnt += s1;
    }

    return cnt <= mid;
}

void solve(){
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        a.push_back(t);
    }
    sort(a.rbegin(), a.rend());

    int s = 0;
    int e = 1e9;
    while(s < e){
        int m = s + (e-s)/2;
        if(ok(a, m, x, y)){
            e = m;
        }
        else{
            s = m + 1;
        }
    }
    cout << s << endl;
    // cout << ok(a, 4, x, y);

    // cout << oper << endl;
}



int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}
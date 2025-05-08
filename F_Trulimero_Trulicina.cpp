#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    int total = n * m;
   
    if(k == 2){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if((i+j)%2 == 0){
                    cout << 1 << " ";
                }
                else{
                    cout << 2 << " ";
                }
            }
            cout << "\n";
        }
        return;
    }
    int l = 0, r = 100;
    while(l < r){
        int mid = (l + r) / 2;
        if(mid * k >= total){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    if(m % k != 0){
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                ans[i][j] = ((i * m + j) % k) + 1;
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    else
    {
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++){
            if(i % 2 == 0){ 
                for (int j = 0; j < m; j++){
                    ans[i][j] = (j % k) + 1;
                }
            }
            else { 
                for (int j = 0; j < m; j++){
                    ans[i][j] = (((j + 1) % k) + 1);
                }
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

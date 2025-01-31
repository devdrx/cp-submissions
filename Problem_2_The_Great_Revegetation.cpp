#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> A(m+1, 0), B(m+1, 0), g(n+1, 0);
    for(int i = 0; i < m; i++){
        cin >> A[i] >> B[i];
        if(A[i] > B[i]) swap(A[i], B[i]); // lower pasture is processed first
    }

    for(int i = 0; i < n; i++){
        int col = 1;
        for(col = 1; col <= 4; col++){
            int f = 1;

            for(int j = 0; j < m; j++){
                if(B[j] == i+1 and g[A[j]] == col){
                    f = 0;
                }
            }
            if(f){
                break;
            } //if flag is ok, then break else try next color
        }
        g[i+1] = col;
        cout << col;
    }
    cout << "\n";
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("planting.in", "r", stdin);
	freopen("planting.out", "w", stdout);

	int m;
    cin >> m;
    vector<int> deg(m);
    int n = m-1;
    while(n--){
        int a,b;
        cin>>a>>b;
        deg[a]++;
        deg[b]++;
    }
    int mx = 0;
    for(int i = 0; i < m; i++){
        mx = max(mx,deg[i]);
    }
    cout << mx + 1 << endl;
}
#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 3e5 + 20, M = 100 * 1000 * 1000;
int n, a[N];
vector <int> vec;

int32_t main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], vec.push_back(a[i]);
    
    sort(vec.begin(), vec.end());
    
    int ans = 0;
    for (int i = 0; i < n; i++) ans += a[i] * (n - 1);
    
  
    int bad_pairs = 0;
    for (int i = 0; i < n; i++) {
        int id = lower_bound(vec.begin(), vec.end(), M - a[i]) - vec.begin();
        int num = n - id;
        
        if (a[i] + a[i] >= M) num--;
        
        bad_pairs += num;
    }
    
    bad_pairs /= 2;
    
    ans -= bad_pairs * M;
    
    cout << ans << '\n';
}
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
// Function to encode a pair (x, y) into a single long long key.
inline ll encodePair(int x, int y) {
    return ((ll)x << 32) | ((unsigned int)y);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
 
        // Collect indices with fixed values (a[i]==b[i]).
        vector<int> fixedIndices;
        for (int i = 0; i < n; i++){
            if(a[i] == b[i])
                fixedIndices.push_back(i);
        }
 
        // For even n, no index may be fixed.
        // For odd n, exactly one must be fixed.
        if(n % 2 == 0){
            if(!fixedIndices.empty()){
                cout << -1 << "\n";
                continue;
            }
        } else {
            if(fixedIndices.size() != 1){
                cout << -1 << "\n";
                continue;
            }
        }
 
        // Group non-fixed indices by their ordered pair (a[i], b[i]).
        unordered_map<ll, vector<int>> groups;
        for (int i = 0; i < n; i++){
            if(a[i] != b[i]){
                ll key = encodePair(a[i], b[i]);
                groups[key].push_back(i);
            }
        }
 
        // We will now pair indices i and j such that
        // a[i] = b[j] and a[j] = b[i].
        vector<pair<int,int>> pairIndices;
        bool possible = true;
        // To avoid pairing twice, we process only keys where (x,y) is "canonical"
        for(auto &it : groups){
            ll key = it.first;
            int x = key >> 32;
            int y = key & 0xffffffffLL;
            if(x > y) continue; // will be processed when key is (y,x)
 
            ll partnerKey = encodePair(y, x);
            auto &vec1 = it.second;
            if(groups.find(partnerKey) == groups.end()){
                possible = false;
                break;
            }
            auto &vec2 = groups[partnerKey];
            if(vec1.size() != vec2.size()){
                possible = false;
                break;
            }
            for (size_t i = 0; i < vec1.size(); i++){
                pairIndices.push_back({vec1[i], vec2[i]});
            }
        }
 
        // Check that all non–fixed indices are paired.
        int nonFixedCount = n - fixedIndices.size();
        if(nonFixedCount != (int)(2 * pairIndices.size())){
            cout << -1 << "\n";
            continue;
        }
 
        // Build the target ordering T (0-indexed) of indices.
        vector<int> T(n, -1);
        int L = 0, R = n - 1;
        for(auto &p : pairIndices){
            // p.first comes from group (x,y) and p.second from group (y,x).
            T[L] = p.first;
            T[R] = p.second;
            L++;
            R--;
        }
        if(n % 2 == 1){
            T[(n - 1) / 2] = fixedIndices[0];
        }
 
        // We now transform the current ordering (identity) to T using swap operations.
        // The allowed operation is to swap positions i and j (in both arrays).
        vector<int> curr(n);
        for (int i = 0; i < n; i++){
            curr[i] = i;
        }
        // pos[x] will hold the current position of index x.
        vector<int> pos(n);
        for (int i = 0; i < n; i++){
            pos[curr[i]] = i;
        }
 
        vector<pair<int,int>> ops;
        for (int i = 0; i < n; i++){
            if(curr[i] == T[i])
                continue;
            int target = T[i];
            int j = pos[target];
            swap(curr[i], curr[j]);
            pos[curr[i]] = i;
            pos[curr[j]] = j;
            ops.push_back({i, j});
        }
 
        // The problem guarantees a solution with at most n operations.
        if((int)ops.size() > n){
            cout << -1 << "\n";
            continue;
        }
 
        // Output the operations (convert indices to 1-indexed).
        cout << ops.size() << "\n";
        for(auto &op : ops){
            cout << op.first + 1 << " " << op.second + 1 << "\n";
        }
    }
    return 0;
}

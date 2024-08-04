#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        map<int, vector<int>> indexes;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            indexes[x].push_back(i);
        }
        int ans = n+1;
        for(auto i: indexes)
        {
            vector<int> tmp;
            tmp.push_back(-1);
            for(auto j: i.second) tmp.push_back(j);
            tmp.push_back(n);
            
            vector<int> diff;
        
            for(int j = 0; j < (int)tmp.size(); j++)
            {
                if(j==0) continue;
                else diff.push_back(tmp[j]-tmp[j-1] - 1);
            }
            sort (diff.rbegin(), diff.rend());
          
            int m1 = diff[0];
            if(m1>0) m1--;
            m1 = (m1+1) / 2;
            ans = min(ans, max(m1, diff[1]));
        }
        cout << ans << endl;
    }
}

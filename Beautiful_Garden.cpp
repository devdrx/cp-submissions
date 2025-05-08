#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--){
	    int nf, mb, tot;
        long long ans = 0;
        cin >> nf >> mb >> tot;
        
        vector<pair<int,int>> fld(nf);
        for (int i = 0; i < nf; i++){
            cin >> fld[i].first;
        }
        
        for (int i = 0; i < nf; i++){
            fld[i].second = 1;
        }
        
        
        for (int curr = 1; curr <= tot; curr++){
            vector<int> pos;
            for (int i = 0; i < nf; i++){
                if (fld[i].second <= curr)
                    pos.push_back(i);
            }
            int avail = pos.size();
            if(avail <= mb) continue;
            
            int num_pick = avail - mb;
            
            sort(pos.begin(), pos.end(), [&](int a, int b){
                return fld[a].first < fld[b].first;
            });
            
            for (int j = 0; j < num_pick; j++){
                int posn = pos[j];
                fld[posn].second = curr + fld[posn].first;
                ans++;
            }
        }
        cout << ans << "\n";
	}
}

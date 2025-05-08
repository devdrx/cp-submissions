#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Flower {
    int regrow;      // Ti: days needed for regrowth
    int nextAvail;   // next day when this flower blooms
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    
    while (T--) {
        int N, K, D;
        cin >> N >> K >> D;
        
        vector<Flower> flowers(N);
        for (int i = 0; i < N; i++) {
            cin >> flowers[i].regrow;
            flowers[i].nextAvail = 1;  // initially, every flower is in bloom on day 1
        }
        
        // Total number of plucks performed.
        long long totalPlucks = 0;
        
        // Simulate each day from 1 to D.
        for (int day = 1; day <= D; day++) {
            // Collect indices of flowers that are blooming today.
            vector<int> availableIndices;
            for (int i = 0; i < N; i++) {
                if (flowers[i].nextAvail <= day) {
                    availableIndices.push_back(i);
                }
            }
            
            // If there are not more than K flowers, we cannot pluck any.
            int availableCount = availableIndices.size();
            if (availableCount <= K) continue;
            
            // We can pluck at most (availableCount - K) flowers today.
            int plucksToday = availableCount - K;
            
            // To maximize plucks in future days, choose the ones that regrow faster.
            sort(availableIndices.begin(), availableIndices.end(), [&](int a, int b) {
                return flowers[a].regrow < flowers[b].regrow;
            });
            
            // Pluck the chosen flowers.
            for (int j = 0; j < plucksToday; j++) {
                int idx = availableIndices[j];
                // After plucking on day 'day', flower becomes available again on day + regrow time.
                flowers[idx].nextAvail = day + flowers[idx].regrow;
                totalPlucks++;
            }
        }
        
        cout << totalPlucks << "\n";
    }
    
    return 0;
}

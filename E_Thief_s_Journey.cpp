#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

// Function to precompute the smallest prime factor (SPF) for every number up to max_n
void sieve(int max_n, vector<int>& spf) {
    for (int i = 2; i <= max_n; ++i) spf[i] = i;
    for (int i = 2; i * i <= max_n; ++i) {
        if (spf[i] == i) {  // i is prime
            for (int j = i * i; j <= max_n; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

// Function to get the prime factors of x using the smallest prime factor array
vector<int> get_factors(int x, vector<int>& spf) {
    vector<int> factors;
    while (x != 1) {
        factors.push_back(spf[x]);
        x /= spf[x];
    }
    return factors;
}

int thief_journey(int n, int W, vector<pair<int, int>>& items) {
    vector<int> dp(W + 1, 0);  // DP array to store maximum values for given weight capacities
    vector<int> spf(n + 1);
    
    sieve(n, spf);  // Precompute smallest prime factors
    
    // DP approach to maximize value
    for (int i = 1; i <= n; ++i) {
        int w = items[i - 1].first;
        int v = items[i - 1].second;
        
        vector<int> factors = get_factors(i, spf);
        for (int factor : factors) {
            int multiple = factor;
            while (i * multiple <= n) {
                int next_house = i * multiple;
                for (int weight = W; weight >= w; --weight) {
                    dp[weight] = max(dp[weight], dp[weight - w] + v);
                }
                multiple *= factor;
            }
        }
    }
    
    return *max_element(dp.begin(), dp.end());  // Return the maximum value possible
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, W;
        cin >> n >> W;
        vector<pair<int, int>> items(n);
        for (int i = 0; i < n; ++i) {
            cin >> items[i].first >> items[i].second;  // weight and value
        }
        cout << thief_journey(n, W, items) << endl;
    }
    return 0;
}

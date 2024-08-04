#include <iostream>
#include <algorithm>
using namespace std;

long long maxProfit(long long n, long long a, long long b) {
    long long max_profit = n * a; long long x = (b-a>0)?b-a:0;
    long long k = min(n, x);  
    
    long long modifiedPriceProfit = k * (b) - (k * (k - 1)) / 2;
    long long usualPriceProfit = (n - k ) * a;
    long long currentProfit = modifiedPriceProfit + usualPriceProfit;
    
    // Compare with the initial profit and return the maximum
    return max(max_profit, currentProfit);
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;
        cout << maxProfit(n, a, b) << endl;
    }
    
    return 0;
}


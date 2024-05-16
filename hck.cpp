#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
const int mod = 1e9 + 7;

using namespace std;


int calculateSum(vector<int>& a, vector<int>& b, vector<int>& c) {
    int n = a.size();
    vector<vector<int>> triples(n, vector<int>(3));

    for (int i = 0; i < n; ++i) {
        triples[i][0] = a[i];
        triples[i][1] = b[i];
        triples[i][2] = c[i];
    }

    sort(triples.begin(), triples.end());

    vector<int> b_asc(n);
    for (int i = 0; i < n; ++i) {
        b_asc[i] = triples[i][1];
    }

    sort(triples.rbegin(), triples.rend());

    vector<int> c_desc(n);
    for (int i = 0; i < n; ++i) {
        c_desc[i] = triples[i][2];
    }

    int totalSum = 0;
    for (int i = 0; i < n; ++i) {
        totalSum += b_asc[i] * c_desc[i];
    }

    return totalSum;
}
int main() {
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n), b(n), c(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        for(int i = 0; i < n; i++){
            cin >> c[i];
        }
        int result = calculateSum(a, b, c);
   
        cout  << result << endl;
    }
    return 0;
}

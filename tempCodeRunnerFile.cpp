#include <bits/stdc++.h>
using namespace std;

void generateTestCase() {
    int n = 200000; // maximum size of n
    int m = 1; // only one string to check
    int large_number = 1000000000; // large identical integer for array a

    cout << "1\n"; // number of test cases
    cout << n << "\n";
    
    // Print array `a` filled with large identical integers
    for (int i = 0; i < n; ++i) {
        cout << large_number << " ";
    }
    cout << "\n";
    
    cout << m << "\n";
    
    // Print string `s` with a repeated character 'a'
    for (int i = 0; i < n; ++i) {
        cout << 'a';
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    generateTestCase();

    return 0;
}


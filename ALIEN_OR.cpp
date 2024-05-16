#include<bits/stdc++.h>
#define int long long
using namespace std;

bool isPowerOf2(int num) {
    return (num & (num - 1)) == 0 && num != 0;
}

int countUniquePowersOf2(const vector<string>& binaryStrings) {
    unordered_set<int> powersOf2;

    // Iterate through each binary string
    for (const string& binaryString : binaryStrings) {
        // Convert the binary string to an integer
        int num = stoi(binaryString, nullptr, 2);
        
        // Check if the integer is a power of 2
        if (isPowerOf2(num)) {
            powersOf2.insert(num);
        }
    }

    return powersOf2.size();
}
int32_t main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int k; cin >> k;
        vector<string> words;
        string temp;
        for(int i = 0; i < n; i++){
            cin >> temp;
            words.push_back(temp);
        }
        
        // vector<int> x = findPowersOf2(words);
        int u = countUniquePowersOf2(words);
        if(u==k){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        
    }
    
}
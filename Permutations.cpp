// A permutation of integers 1,2,\ldots,n is called beautiful if there are no adjacent elements whose difference is 1.
// Given n, construct a beautiful permutation if such a permutation exists.
// Input
// The only input line contains an integer n.
// Output
// Print a beautiful permutation of integers 1,2,\ldots,n. If there are several solutions, you may print any of them. If there are no solutions, print "NO SOLUTION".
// Constraints

// 1 \le n \le 10^6

// Example 1
// Input:
// 5

// Output:
// 4 2 5 3 1
// Example 2
// Input:
// 3

// Output:
// NO SOLUTION

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n; 
    cin >> n;

    vector<int> ans;

    if(n==1){
        cout << 1;
        return 0;
    }
    else if(n==2 || n==3){
        cout << "NO SOLUTION";
        return 0;
    }
    else if(n==4){
        cout << "2 4 1 3";
        return 0;
    }
    else if(n<5) {
        cout << "NO SOLUTION";
        return 0;
    }
    else{
        for(int i=2; i<=n; i+=2){
            ans.push_back(i);
        }
        for(int i=1; i<=n; i+=2){
            ans.push_back(i);
        }
    }

    for(auto i: ans){
        cout << i << " ";
    }
}
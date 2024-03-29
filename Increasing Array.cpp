// You are given an array of n integers. You want to modify the array so that it is increasing, i.e., every element is at least as large as the previous element.
// On each move, you may increase the value of any element by one. What is the minimum number of moves required?

// Input
// The first input line contains an integer n: the size of the array.
// Then, the second line contains n integers x_1,x_2,....,x_n: the contents of the array.
// Output
// Print the minimum number of moves.
// Constraints

// 1 < n < 2 * 10^5
// 1 < x_i < 10^9

// Example
// Input:   
// 5
// 3 2 5 1 7

// 6 10 4 10 2 8 9 2 7 7

//     6     8 2 1 8 3 3 = 31


// Output:
// 5

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n; 
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int ans = 0;
    for(int i=0; i<n-1; i++){
        if(arr[i]>arr[i+1]){
            ans += arr[i]-arr[i+1];
            arr[i+1] = arr[i];
        }
    }

    cout << ans;
}
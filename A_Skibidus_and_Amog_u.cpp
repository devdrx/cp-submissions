#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        string W;
        cin >> W;
        string plural = W.substr(0, W.size() - 2) + "i";
        cout << plural << "\n";
    }
    return 0;
}

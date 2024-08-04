#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        vector<int> pages(n);
        //initialize max prefix array
        vector<int> max_prefix(n);
        for (int i = 0; i < n; i++) {
            cin >> pages[i];
        }
        int x = *max_element(pages.begin(), pages.end()-1);
        cout << x + pages[n-1] << endl;
        
    }
    
    return 0;
}

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int q;
        cin >> q;

        deque<int> arr;
        bool reverse_flag = false;

        for (int i = 0; i < q; ++i) {
            int s;
            cin >> s;

            if (s == 1) {  // cyclic shift
                if (!reverse_flag) {
                    int val = arr.back();
                    arr.pop_back();
                    arr.push_front(val);
                } else {
                    int val = arr.front();
                    arr.pop_front();
                    arr.push_back(val);
                }

            } else if (s == 2) {  // reverse
                reverse_flag = !reverse_flag;

            } else if (s == 3) {  // append
                int k;
                cin >> k;
                if (!reverse_flag) {
                    arr.push_back(k);
                } else {
                    arr.push_front(k);
                }
            }

            // calculate rizziness
            long long rizz = 0;
            if (!reverse_flag) {
                for (int j = 0; j < arr.size(); ++j) {
                    rizz += 1LL * (j + 1) * arr[j];
                }
            } else {
                for (int j = 0; j < arr.size(); ++j) {
                    rizz += 1LL * (j + 1) * arr[arr.size() - 1 - j];
                }
            }

            cout << rizz << "\n";
        }
    }

    return 0;
}

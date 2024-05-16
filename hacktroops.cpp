#include <bits/stdc++.h>
using namespace std;
int minLengthSubarrayGreaterThanX(vector<int>& nums, int x) {
    int n = nums.size();
    int left = 0, right = 0;
    int minLength = n + 1;
    int currentSum = 0;

    while (right < n) {
        currentSum += nums[right];

        while (currentSum > x) {
            minLength = min(minLength, right - left + 1);
            currentSum -= nums[left];
            left++;
        }

        right++;
    }

    return (minLength == n + 1) ? -1 : minLength;
}

int main() {
	int num;
	cin >> num; 
	while(num--){
		int n;
		cin >> n;
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin >> arr[n];
		}
		int target;
		cin >> target;
		int ans = minLengthSubarrayGreaterThanX(arr, target);
		cout << ans << endl;
	}
}

#include <bits/stdc++.h>
using namespace std;

int denomination[] = { 1, 2, 5, 10, 20, 50 };
int n = sizeof(denomination) / sizeof(denomination[0]);

void findMin(int V)
{
	sort(denomination, denomination + n);

	vector<int> ans;

	for (int i = n - 1; i >= 0; i--) {

		while (V >= denomination[i]) {
			V -= denomination[i];
			ans.push_back(denomination[i]);
		}
	}
	cout<<endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}

int main()
{
	int n = 93;
	cout << "Following is minimal"
		<< " number of change for " << n << ": ";

	// Function Call
	findMin(n);
	return 0;
}

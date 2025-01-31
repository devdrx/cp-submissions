#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
    int x, y, z, w;
    cin >> x >> y >> z >> w;

    int ans = max((max(z,c) - min(a, x)) , (max(w, d) - min(b, y)));

    ans*=ans;
	
	cout << ans << "\n";
}
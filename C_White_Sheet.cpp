#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct Rect {
	ll x1, y1, x2, y2;
	ll area() { return abs(y2 - y1) * abs(x2 - x1); }
};

ll intersect(Rect a, Rect b) {
	ll xOverlap = max(min(a.x2, b.x2) - max(a.x1, b.x1), (ll)0);
	ll yOverlap = max(min(a.y2, b.y2) - max(a.y1, b.y1), (ll)0);
	return xOverlap * yOverlap;
}

ll intersectThree(Rect a, Rect b, Rect c) {
	ll xOverlap = max(min(min(a.x2, b.x2), c.x2) - max(max(a.x1, b.x1), c.x1), (ll)0);
	ll yOverlap = max(min(min(a.y2, b.y2), c.y2) - max(max(a.y1, b.y1), c.y1), (ll)0);
	return xOverlap * yOverlap;
}

void solve() {
	Rect w, b1, b2;
	cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
	cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
	cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;
	ll vis = w.area() - (intersect(w, b1) + intersect(w, b2)) + intersectThree(w, b1, b2);
	if (vis) cout << "YES\n";
	else cout << "NO\n";
}

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0);
	if (name.length()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main() {
	setIO("");

	int t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
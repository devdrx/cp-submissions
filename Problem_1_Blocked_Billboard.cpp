#include <bits/stdc++.h>
using namespace std;

struct Rect{
    int x1, y1, x2, y2;
    int area() {return (x2 - x1) * (y2 - y1);}
};

int intersect(Rect p, Rect q){
    int x_overlap = max(0, min(p.x2, q.x2) - max(p.x1, q.x1));
    int y_overlap = max(0, min(p.y2, q.y2) - max(p.y1, q.y1));
    return x_overlap * y_overlap;
}

int main(){
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    Rect a, b, t;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;

    cout << a.area() + b.area() - intersect(a, t) - intersect(b, t) << "\n";
}
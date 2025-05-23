#include <bits/stdc++.h>
using namespace std;

struct Rect
{
    int x1, y1, x2, y2;
    int area() { return (x2 - x1) * (y2 - y1); }
};

int intersect(Rect p, Rect q)
{
    int x_overlap = max(0, min(p.x2, q.x2) - max(p.x1, q.x1));
    int y_overlap = max(0, min(p.y2, q.y2) - max(p.y1, q.y1));
    return x_overlap * y_overlap;
}

int main()
{
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    Rect a, b;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2; //lawn mower billboard behind the cow feed billboard
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2; 

    if (a.x1 >= b.x1 && a.x2 <= b.x2 && ((a.y2 >= b.y1 && a.y2 <= b.y2) || (a.y1 >= b.y1 && a.y1 <= b.y2)))
    {
        cout << a.area() - intersect(a, b) << '\n';
    }
    else if (a.y1 >= b.y1 && a.y2 <= b.y2 && ((a.x2 >= b.x1 && a.x2 <= b.x2) || (a.x1 >= b.x1 && a.x1 <= b.x2)))
    {
        cout << a.area() - intersect(a, b) << '\n';
    }
    else
    {
        cout << a.area() << '\n';
    }
}
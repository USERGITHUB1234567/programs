#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

struct Point {
    int x, y;
};
int area(Point a, Point b, Point c) {
    return abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}
int cal(Point a, Point b) {
    return __gcd(abs(a.x - b.x), abs(a.y - b.y)) + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, p;
    cin >> n >> m >> p;
    Point A = {0, 0};
    Point B = {n, m};
    Point C = {p, 0};
    int s = area(A, B, C);
    int b = cal(A, B) + cal(B, C) + cal(C, A) - 3;
    int kq = (s - b + 2) / 2;
    cout << kq;
    return 0;
}

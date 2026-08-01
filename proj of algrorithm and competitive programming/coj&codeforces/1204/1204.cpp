#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

struct Point {
    double x, y;
};
double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Point A, B;
    double r1, r2;
    cin >> A.x >> A.y >> r1 >> B.x >> B.y >> r2;
    double d = distance(A, B);
    if (d >= r1 + r2) {
        cout << fixed << setprecision(6) << (d - r1 - r2) / 2.0;
    }
    else {
        double overlap = max(r1, r2) - d - min(r1, r2);
        cout << fixed << setprecision(6) << (overlap / 2.0 <= 0 ? 0 : overlap / 2.0);
    }
    return 0;
}

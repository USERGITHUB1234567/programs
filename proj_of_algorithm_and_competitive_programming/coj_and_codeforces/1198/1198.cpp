#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
struct point {
    long double x, y;
};
long double tdt(const point& a, const point& b, const point& c) {
    return (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2.0;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin >> n;
    point p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    long double kq = -1e9;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long double t1 = -1e5, t2 = -1e5;
            for (int k = 0; k < n; k++) {
                if (k != i && k != j) {
                    long double area = tdt(p[i], p[j], p[k]);
                    if (area >= 0) {
                        t2 = max(t2, area);
                    } else {
                        t1 = max(t1, -area);
                    }
                    if(t1>=0 and t2>=0)kq = max(kq, t1 + t2);
                }
            }
        }
    }
    cout << fixed << setprecision(6) << kq;
    return 0;
}

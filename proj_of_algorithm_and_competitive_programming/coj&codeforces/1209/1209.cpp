#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int n, bx, by;

struct cir {
    int x, y, r;
};

pair<double, double> inter(int bx, int by, int cx, int cy, int r) {
    double a = (cy - by) * (cy - by) - r * r;
    double b = (cx - bx) * (cy - by);
    double c = (cx - bx) * (cx - bx) - r * r;
    double sqrt_d = sqrt(b * b - a * c);
    double k1 = (-b - sqrt_d) / a;
    double k2 = (-b + sqrt_d) / a;
    double x1 = k1 * by + bx;
    double x2 = k2 * by + bx;
    return {x1, x2};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    pair<double, double> a[500];
    cin >> n >> bx >> by;

    for (int i = 1; i <= n; i++) {
        cir c;
        cin >> c.x >> c.y >> c.r;
        a[i] = inter(bx, by, c.x, c.y, c.r);
    }

    sort(a + 1, a + n + 1);
    double x1 = a[1].first, x2 = a[1].second;

    cout << fixed << setprecision(2);
    for (int i = 2; i <= n; i++) {
        if (a[i].first <= x2) {
            x2 = max(x2, a[i].second);
        } else {
            cout << x1 << " " << x2 << "\n";
            x1 = a[i].first;
            x2 = a[i].second;
        }
    }
    cout << x1 << " " << x2;
    return 0;
}

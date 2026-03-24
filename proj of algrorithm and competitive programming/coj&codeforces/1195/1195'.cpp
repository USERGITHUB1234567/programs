#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

struct point {
    double x, y;
};

int cut[17][4] = {
    {0, 2, 3, 0}, {0, 2, 4, 0}, {0, 2, 4, 5}, {1, 2, 3, 1}, {1, 2, 4, 1},
    {1, 2, 4, 5}, {1, 6, 0, 1}, {1, 7, 0, 1}, {2, 4, 5, 2}, {2, 4, 6, 2},
    {2, 4, 6, 7}, {3, 4, 5, 3}, {3, 4, 6, 3}, {3, 4, 6, 7}, {3, 4, 6, 0},
    {4, 6, 7, 4}, {5, 6, 7, 5}
};

double x[8], y[8];

double area(int i) {
    double s = 0;
    double x1 = x[cut[i][3]], y1 = y[cut[i][3]];
    for (int j = 0; j <= 3; j++) {
        double x2 = x[cut[i][j]], y2 = y[cut[i][j]];
        s += x1 * y2 - y1 * x2;
        x1 = x2;
        y1 = y2;
    }
    return abs(s) / 2.0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 8; i += 2) cin >> x[i] >> y[i];
    for (int i = 1; i <= 5; i += 2) {
        x[i] = (x[i - 1] + x[i + 1]) / 2;
        y[i] = (y[i - 1] + y[i + 1]) / 2;
    }
    x[7] = (x[6] + x[0]) / 2;
    y[7] = (y[6] + y[0]) / 2;

    double s = area(0), ans1 = s, ans2 = 0;
    for (int i = 1; i < 17; i++) {
        double s1 = area(i), s2 = s - s1;
        if (abs(s1 - s2) < abs(ans1 - ans2)) {
            ans1 = s1;
            ans2 = s2;
        }
    }
    if (ans1 > ans2) swap(ans1, ans2);
    cout << fixed << setprecision(3) << ans1 << " " << ans2 << endl;
    return 0;
}

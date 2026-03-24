#include <bits/stdc++.h>
using namespace std;

const int cake[17][4] = {
    {0, 2, 4, 6}, {0, 2, 3, 0}, {0, 2, 4, 0}, {0, 2, 4, 5},
    {1, 2, 3, 1}, {1, 2, 4, 1}, {1, 2, 4, 5}, {1, 2, 4, 6},
    {1, 7, 0, 1}, {2, 4, 5, 2}, {2, 4, 6, 2}, {2, 7, 0, 2},
    {3, 4, 5, 3}, {3, 4, 6, 3}, {3, 4, 6, 7}, {4, 6, 7, 4},
    {5, 6, 7, 5}
};

int n;
double x[8], y[8];

double area(int i) {
    // Tính diện tích của 1 phần trong cách cắt i
    double s = 0, x1 = x[cake[i][3]], y1 = y[cake[i][3]];
    for (int j = 0; j <= 3; j++) {
        double x2 = x[cake[i][j]], y2 = y[cake[i][j]];
        s += x1 * y2 - x2 * y1;
        x1 = x2;
        y1 = y2;
    }
    return 0.5 * abs(s);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("test01.in", "r", stdin);
    //freopen("", "w", stdout);

    for (int i = 0; i <= 3; i++)
        cin >> x[2 * i] >> y[2 * i];

    for (int i = 0; i <= 2; i++) {
        x[2 * i + 1] = (x[2 * i] + x[2 * i + 2]) / 2;
        y[2 * i + 1] = (y[2 * i] + y[2 * i + 2]) / 2;
    }

    x[7] = (x[6] + x[0]) / 2;
    y[7] = (y[6] + y[0]) / 2;

    double s = area(0), s1 = 0, s2 = s;
    for (int i = 1; i <= 16; i++) {
        double size1 = area(i), size2 = s - size1;
        if (abs(size1 - size2) < abs(s1 - s2)) {
            s1 = size1;
            s2 = size2;
        }
    }

    if (s1 > s2) swap(s1, s2);
    cout << fixed << setprecision(3) << s1 << " " << s2 << "\n";
    return 0;
}

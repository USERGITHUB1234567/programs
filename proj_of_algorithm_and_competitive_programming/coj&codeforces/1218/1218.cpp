#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

struct point {
    double x, y;
};

struct vec {
    double x, y;
};

double crpd(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

vector<point> a;

int side(point a, point b, point c) {
    vec ab = {b.x - a.x, b.y - a.y}, ac = {c.x - a.x, c.y - a.y};
    double s = crpd(ab, ac);
    if (s > 0) return 1;
    if (s < 0) return -1;
    return 0;
}

bool inside(point m, vector<point>& a) {
    if (side(a[0], a[1], m) >= 0 || side(a[0], a[a.size() - 1], m) <= 0) return false;
    int l = 1, r = a.size() - 1;
    while (l < r) {
        int c = (l + r) >> 1;
        if (side(a[0], a[c], m) < 0) l = c + 1;
        else r = c;
    }
    return side(a[l - 1], a[l], m) < 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    reverse(a.begin(), a.end());
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        point x;
        cin >> x.x >> x.y;
        if (inside(x, a)) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}

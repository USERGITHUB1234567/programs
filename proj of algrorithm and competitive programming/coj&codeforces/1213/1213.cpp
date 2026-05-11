#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

#pragma GCC optimize("O3")
using namespace std;

struct point {
    int x, y;
};

struct vect {
    double x, y;
};

struct segment {
    long long a, b, c;
    int x1, x2;
};

bool cmp(segment u, segment v) {
    return (u.a < v.a || (u.a == v.a && u.b < v.b) || (u.a == v.a && u.b == v.b && u.c < v.c));
}

double crpd(vect a, vect b) {
    return a.x * b.y - a.y * b.x;
}

int side(point a, point b, point c) {
    vect ab = {b.x - a.x, b.y - a.y};
    vect ac = {c.x - a.x, c.y - a.y};
    double s = crpd(ab, ac);
    if (s > 0) return 1;
    if (s < 0) return -1;
    return 0;
}

bool inck(point a, point b, point c, point d) {
    int s1 = side(a, b, c);
    int s2 = side(a, b, d);
    int s3 = side(c, d, a);
    int s4 = side(c, d, b);
    if (s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0) {
        if (max(a.x, b.x) < min(c.x, d.x) || max(c.x, d.x) < min(a.x, b.x) || max(a.y, b.y) < min(c.y, d.y) || max(c.y, d.y) < min(a.y, b.y))
            return false;
        return true;
    }
    return (s1 * s2 <= 0 && s3 * s4 <= 0);
}

void brf() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, kq = 0;
    cin >> n;
    vector<point> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y >> b[i].x >> b[i].y;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (inck(a[i], b[i], a[j], b[j])) kq++;
        }
    }
    cout << kq;
}

void solve() {
    int n;
    cin >> n;
    vector<segment> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if ((x1 > x2) || (x1 == x2 && y1 > y2)) {
            swap(x1, x2);
            swap(y1, y2);
        }
        s[i].a = y2 - y1;
        s[i].b = x1 - x2;
        int gcd = __gcd(abs(s[i].a), abs(s[i].b));
        s[i].a /= gcd;
        s[i].b /= gcd;
        s[i].c = -s[i].a * x1 - s[i].b * y1;
        if (x1 != x2) {
            s[i].x1 = x1;
            s[i].x2 = x2;
        } else {
            s[i].x1 = y1;
            s[i].x2 = y2;
        }
    }
    long long ans = 0;
    sort(s.begin() + 1, s.end(), cmp);
    for (int i = 1; i <= n;) {
        vector<pair<int, int>> a;
        for (int j = i; i <= n; ++i) {
            if (s[i].a == s[j].a && s[i].b == s[j].b && s[i].c == s[j].c) {
                a.push_back({s[i].x1, 1});
                a.push_back({s[i].x2, -1});
            } else break;
        }
        sort(a.begin(), a.end());
        for (int j = 0, cur = 0; j < a.size(); ++j) {
            cur += a[j].second;
            if (a[j].second == -1) ans += cur;
        }
    }
    cout << ans;
}

int main() {
    solve();
    return 0;
}

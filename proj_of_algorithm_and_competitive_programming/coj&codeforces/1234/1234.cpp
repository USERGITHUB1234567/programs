#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

struct point {
    long long x, y;
};

long long tdt(const vector<point>& a) {
    long long area = 0;
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area += a[i].x * a[j].y;
        area -= a[j].x * a[i].y;
    }
    return abs(area);
}

int side(const point& p1, const point& p2, const point& p3) {
    long long s = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
    if (s > 0) return 1;
    if (s < 0) return -1;
    return 0;
}

bool cmp(const point& a, const point& b) {
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

long long cb(const vector<point>& a) {
    int n = a.size();
    long long k = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        long long dx = abs(a[j].x - a[i].x);
        long long dy = abs(a[j].y - a[i].y);
        k += __gcd(dx, dy);
    }
    return k;
}

vector<point> cvh(vector<point> a) {
    if (a.size() == 1) return a;
    sort(a.begin(), a.end(), cmp);
    point p1 = a[0], p2 = a.back();
    vector<point> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < a.size(); i++) {
        if (i == a.size() - 1 || side(p1, a[i], p2) < 0) {
            while (up.size() >= 2 && side(up[up.size() - 2], up[up.size() - 1], a[i]) >= 0)
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || side(p1, a[i], p2) > 0) {
            while (down.size() >= 2 && side(down[down.size() - 2], down[down.size() - 1], a[i]) <= 0)
                down.pop_back();
            down.push_back(a[i]);
        }
    }
    vector<point> res;
    for (int i = 0; i < up.size(); i++) res.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--) res.push_back(down[i]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    vector<point> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
    vector<point> k = cvh(p);
    long long s = tdt(k);
    long long b = cb(k);
    cout << (s - b) / 2 + 1;
    return 0;
}

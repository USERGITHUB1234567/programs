#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
struct point {
    int x, y;
};
double tdt(point a, point b, point c) {
    return abs((a.x * b.y - a.y * b.x) +
               (b.x * c.y - b.y * c.x) +
               (c.x * a.y - c.y * a.x)) * 0.5;
}
int side(point p1, point p2, point p3) {
    double s = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
    if (s > 0) return 1;
    if (s < 0) return -1;
    return 0;
}
double dist(point a, point b) {
    double t1 = abs(a.x - b.x), t2 = abs(a.y - b.y);
    return t1 * t1 + t2 * t2;
}
int n;
bool cmp(point a, point b) {
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}
vector<point> cvh(vector<point>& a) {
    if (a.size() == 1) return a;
    sort(a.begin(), a.end(), cmp);
    vector<point> up, dow;
    point p1 = a[0], p2 = a.back();
    up.push_back(p1);
    dow.push_back(p1);
    for (int i = 1; i < a.size(); i++) {
        if (side(p1, a[i], p2) < 0 || i == a.size() - 1) {
            while (up.size() >= 2 && side(up[up.size() - 2], up.back(), a[i]) >= 0)
                up.pop_back();
            up.push_back(a[i]);
        }
        if (side(p1, a[i], p2) > 0 || i == a.size() - 1) {
            while (dow.size() >= 2 && side(dow[dow.size() - 2], dow.back(), a[i]) >= 0)
                dow.pop_back();
            dow.push_back(a[i]);
        }
    }
    vector<point> kq;
    for (int i = 0; i < up.size(); i++) kq.push_back(up[i]);
    for (int i = dow.size() - 2; i > 0; i--) kq.push_back(dow[i]);
    return kq;
}
vector<point> p(3003);
void soup1() {
    double kq = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                kq = max(kq, tdt(p[i], p[j], p[k]));
            }
        }
    }
    cout << fixed << setprecision(1) << kq << "\n";
}
void soup2() {
    double kq = 0, ma = 0;
    point p1, p2;
    int id1, id2;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dist(p[i], p[j]) > ma) {
                ma = dist(p[i], p[j]);
                p1 = p[i];
                p2 = p[j];
                id1 = i;
                id2 = j;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (i != id1 && i != id2) {
            kq = max(kq, tdt(p1, p2, p[i]));
        }
    }
    cout << fixed << setprecision(1) << kq << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("tri.inp", "r", stdin);
    freopen("tri.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    if (n <= 100) soup1();
    else soup2();
    return 0;
}

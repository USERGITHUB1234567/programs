#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

struct point {
    int x, y;
};

struct vec {
    int x, y;
};

vector<point> p(500);
int n;

double crpd(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

int side(point A, point B, point C) {
    vec AB = {B.x - A.x, B.y - A.y};
    vec AC = {C.x - A.x, C.y - A.y};
    double s = crpd(AB, AC);
    if (s > 0) return 1;
    if (s < 0) return -1;
    return 0;
}

bool ckin(point A, point B, point C, point D) {
    int s1 = side(A, B, C);
    int s2 = side(A, B, D);
    int s3 = side(C, D, A);
    int s4 = side(C, D, B);
    if (s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0) {
        if (max(A.x, B.x) < min(C.x, D.x) || max(C.x, D.x) < min(A.x, B.x) || max(A.y, B.y) < min(C.y, D.y) || max(C.y, D.y) < min(A.y, B.y))
            return false;
        return true;
    }
    return (s1 * s2 <= 0 && s3 * s4 <= 0);
}

double tdt(int i, int j) {
    double kq = crpd({p[j].x,p[j].y},{p[i].x,p[i].y});
    for (int id = i; id <= j - 1; id++) {
        int jd = (id + 1);
        kq += p[id].x * p[jd].y - p[id].y * p[jd].x;
    }
    return abs(kq) / 2.0;
}

bool diagonal(int i, int j) {
    for (int k = 1; k <= n; k++) {
        if (k != i && k != j && k % n + 1 != i && k % n + 1 != j && ckin(p[i], p[j], p[k], p[k + 1])) {
            return false;
        }
    }
    return true;
}

void solve() {
    double s = tdt(1, n);
    double diff = s;
    pair<int, int> kq;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 2; j <= n; j++) {
            if (diagonal(i, j)) {
                double s1 = tdt(i, j);
                double s2 = tdt(j, n + i);
                if (abs(s1 + s2 - s) < 1e-10 && abs(s1 - s2) < diff) {
                    diff = abs(s1 - s2);
                    kq.first = i;
                    kq.second = j;
                }
            }
        }
    }
    cout << kq.first << " " << kq.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
        p[n + i] = p[i];
    }
    solve();
    return 0;
}

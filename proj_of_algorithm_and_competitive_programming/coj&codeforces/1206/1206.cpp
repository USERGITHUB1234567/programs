#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

struct point {
    int x, y;
};

int side(point a, point b, point c) {
    long long f = 1LL * (b.y - a.y) * (c.x - a.x) - 1LL * (b.x - a.x) * (c.y - a.y);
    if (f > 0) return 1;
    else if (f < 0) return -1;
    else return 0;
}
bool ckinst(point ht[], point tt[], int m, int n) {
    for (int i = 1; i <= m; i++) {
        bool nse = true;
        for (int j = 1; j <= n; j++) {
            if (side(ht[i], ht[i + 1], tt[j]) < 0) {
                nse = false;
                break;
            }
        }
        if (nse) return false;
    }
    for (int i = 1; i <= n; i++) {
        bool nse = true;
        for (int j = 1; j <= m; j++) {
            if (side(tt[i], tt[i + 1], ht[j]) < 0) {
                nse = false;
                break;
            }
        }
        if (nse) return false;
    }
    return true;
}
void solve() {
    int n, m;
    cin >> m;
    point ht[1502], tt[1502];
    for (int i = 1; i <= m; i++) cin >> ht[i].x >> ht[i].y;
    cin >> n;
    ht[m + 1] = ht[1];
    for (int i = 1; i <= n; i++) cin >> tt[i].x >> tt[i].y;
    tt[n + 1] = tt[1];
    if (ckinst(ht, tt, m, n)) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

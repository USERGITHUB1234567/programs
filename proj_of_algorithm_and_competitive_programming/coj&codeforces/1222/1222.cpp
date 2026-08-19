#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main() {
    int x1, y1, x2, y2, x3, y3, r;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> r;
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    long long ans = 0;
    for (int x = x1; x <= x2; x++) {
        if (abs(x3 - x) <= r) {
            int t = sqrt(1LL*r * r - 1LL*(x - x3) * (x - x3));
            int a = y3 - t;
            int b = y3 + t;
            if (b < y1 || y2 < a) continue;
            ans += min(y2, b) - max(a, y1) + 1;
        }
    }
    cout << ans;
    return 0;
}

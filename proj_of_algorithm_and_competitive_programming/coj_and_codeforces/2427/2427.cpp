#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
long long ft[100005], a[100005];
long long su(int i) {
    long long s = 0;
    while (i > 0) {
        s += ft[i];
        i -= (i & -i);
    }
    return s;
}
void up(int i, int v) {
    while (i <= n) {
        ft[i] += v;
        i += (i & -i);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    memset(ft, 0, sizeof(ft));
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = a[1];
    for (int i = 1; i <= n; i++) {
        long long d = abs(a[i] - a[i - 1]);
        up(i, d);
    }
    int q;
    cin >> q;
    while (q--) {
        int t, i, x;
        cin >> t >> i >> x;
        if (t == 1) {
            if (i > 1) {
                long long c = abs(a[i] - a[i - 1]);
                long long m = abs(x - a[i - 1]);
                up(i, m - c);
            }
            if (i < n) {
                long long c = abs(a[i + 1] - a[i]);
                long long m = abs(a[i + 1] - x);
                up(i + 1, m - c);
            }
            a[i] = x;
        } else {
            cout << su(x) - su(i) << "\n";
        }
    }
    return 0;
}

#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, q;
const long double EPS = 1e-13;
int a[100005], b[100005];
long long cnt(long double f) {
    long long d = 0;
    for (int i = 0, j = 0; j < n; j++) {
        while (i < n && (long double) a[i] / b[j] < f - EPS)
            i++;
        d += i;
    }
    return d;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    while (q--) {
        int c;
        cin >> c;

        long double l = 0, r = 1e6;
        while (r - l > EPS) {
            long double m = (l + r) / 2;
            if (c <= cnt(m))
                r = m;
            else
                l = m;
        }
        int x, y;
        for (int i = 0, j = 0; j < n; j++) {
            while (i < n && (long double) a[i] / b[j] < l - EPS)
                i++;
            if (i < n && fabs((long double) a[i] / b[j] - l) < EPS) {
                x = a[i];
                y = b[j];
                break;
            }
        }
        int gcd = __gcd(x, y);
        cout << x / gcd << " " << y / gcd << "\n";
    }
}

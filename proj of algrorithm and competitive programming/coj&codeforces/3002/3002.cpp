#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long MOD = 1e9 + 7;
void f(int n, vector<long long>& p) {
    for (int d = 2; d * d <= n; ++d) {
        while (n % d == 0) {
            p[d]++;
            n /= d;
        }
    }
    if (n > 1) p[n]++;
}
long long d(const vector<int>& a, int m) {
    vector<long long> p(m + 1, 0);
    for (int n : a) {
        f(n, p);
    }
    long long c = 1;
    for (int i = 2; i <= m; ++i) {
        if (p[i] > 0) {
            c = c * (p[i] + 1) % MOD;
        }
    }
    return c;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int m = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > m) {
            m = a[i];
        }
    }
    cout << d(a, m);
}

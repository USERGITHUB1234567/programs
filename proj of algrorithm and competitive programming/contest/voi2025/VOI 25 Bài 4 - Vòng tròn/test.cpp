#include <bits/stdc++.h>
using namespace std;

using ll = long long;

static ll calc(int n, vector<int> p) {
    int k = (int)p.size();
    if (k <= 1) return 0;

    sort(p.begin(), p.end());

    vector<ll> b(2 * k);
    for (int i = 0; i < 2 * k; ++i) {
        b[i] = 1LL * p[i % k] + (i >= k ? n : 0) - (i + 1);
    }

    vector<ll> pref(2 * k + 1, 0);
    for (int i = 0; i < 2 * k; ++i) pref[i + 1] = pref[i] + b[i];

    ll ans = (1LL << 62);
    for (int l = 0; l < k; ++l) {
        int r = l + k - 1;
        int m = (l + r) >> 1;
        ll med = b[m];

        ll left  = med * (m - l) - (pref[m] - pref[l]);
        ll right = (pref[r + 1] - pref[m + 1]) - med * (r - m);
        ans = min(ans, left + right);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m, l;
        cin >> n >> m >> l;

        vector<int> p(m), q(l);
        for (int i = 0; i < m; ++i) cin >> p[i];
        for (int i = 0; i < l; ++i) cin >> q[i];

        cout << calc(n, p) + calc(n, q) << '\n';
    }
    return 0;
}
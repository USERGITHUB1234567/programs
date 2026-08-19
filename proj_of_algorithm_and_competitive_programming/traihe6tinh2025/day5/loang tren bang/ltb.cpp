#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, q;
    cin >> n >> m >> k >> q;

    vector< set<int> > rows(n+1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) rows[i].insert(j);
    }

    long long sum = 0;
    while (q--) {
        int x, y;
        cin >> x >> y;
        int added = 0;
        int top = max(1, x - k);
        int bot = min(n, x + k);
        for (int i = top; i <= bot; ++i) {
            int d = k - abs(x - i);
            int l = max(1, y - d);
            int r = min(m, y + d);
            auto it = rows[i].lower_bound(l);
            while (it != rows[i].end() && *it <= r) {
                ++added;
                it = rows[i].erase(it);
            }
        }
        sum += added;
        cout << sum << '\n';
    }

    return 0;
}

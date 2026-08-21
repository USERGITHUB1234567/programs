#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct sqrt_decomposition {
    int n, block_size;
    vector<ll> a;
    vector<vector<ll>> block;

    sqrt_decomposition(const vector<ll>& _a) {
        a = _a;
        n = (int)a.size();
        block_size = max(1, (int)sqrt(n));
        block.resize((n + block_size - 1) / block_size);
        for (int i = 0; i < n; ++i) block[i / block_size].push_back(a[i]);
        for (auto &v : block) sort(v.begin(), v.end());
    }

    void update(int idx, ll v) {
        int b = idx / block_size;
        // find and erase old value in block[b]
        auto it_old = lower_bound(block[b].begin(), block[b].end(), a[idx]);
        // ensure we found the old value (safety)
        if (it_old != block[b].end() && *it_old == a[idx]) {
            block[b].erase(it_old);
        } else {
            // fallback: try to find by linear scan (robustness)
            for (auto it = block[b].begin(); it != block[b].end(); ++it) {
                if (*it == a[idx]) { block[b].erase(it); break; }
            }
        }
        // insert new value keeping sorted order
        auto it_new = lower_bound(block[b].begin(), block[b].end(), v);
        block[b].insert(it_new, v);
        a[idx] = v;
    }

    ll query(int l, int r, ll x) {
        if (l > r) return 0;
        ll ans = 0;
        int bl = l / block_size, br = r / block_size;
        if (bl == br) {
            for (int i = l; i <= r; ++i) if (a[i] >= x) ++ans;
            return ans;
        }
        int end_left = (bl + 1) * block_size - 1;
        for (int i = l; i <= min(end_left, n-1); ++i) if (a[i] >= x) ++ans;
        for (int b = bl + 1; b <= br - 1; ++b) {
            int f = lower_bound(block[b].begin(), block[b].end(), x) - block[b].begin();
            ans += (ll)block[b].size() - f;
        }
        int start_right = br * block_size;
        for (int i = start_right; i <= r; ++i) if (a[i] >= x) ++ans;
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sqrt_decomposition sd(a);

    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 0) {
            int l, r; ll x;
            cin >> l >> r >> x;
            // If problem uses 1-based indices, uncomment next two lines:
            // --l; --r;
            cout << sd.query(l, r, x) << '\n';
        } else {
            int pos; ll x;
            cin >> pos >> x;
            // If problem uses 1-based indices, uncomment next line:
            // --pos;
            sd.update(pos, x);
        }
    }
    return 0;
}

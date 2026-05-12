#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 300005;
ll a[maxn], pre[maxn];
pair<ll,int> f[maxn];

struct segtree {
    pair<ll,ll> st[4*maxn];
    // type == 0 -> build min(a) / max(a)
    // type == 1 -> build min(f[i].first) / max(f[i].first)
    void build(int id, int l, int r, bool type) {
        if (l == r) {
            if (!type) {
                st[id].first = a[l];
                st[id].second = a[l];
            } else {
                st[id].first = f[l].first;
                st[id].second = f[l].first;
            }
            return;
        }
        int m = (l + r) >> 1;
        build(id<<1, l, m, type);
        build(id<<1|1, m+1, r, type);
        st[id].first = min(st[id<<1].first, st[id<<1|1].first);
        st[id].second = max(st[id<<1].second, st[id<<1|1].second);
    }
    ll querymin(int id, int l, int r, int i, int j) {
        if (l>j || r<i) return LLONG_MAX;
        if (l>=i && r<=j) return st[id].first;
        int m = (l+r)>>1;
        return min(querymin(id<<1,l,m,i,j), querymin(id<<1|1,m+1,r,i,j));
    }
    ll querymax(int id, int l, int r, int i, int j) {
        if (l>j || r<i) return LLONG_MIN;
        if (l>=i && r<=j) return st[id].second;
        int m = (l+r)>>1;
        return max(querymax(id<<1,l,m,i,j), querymax(id<<1|1,m+1,r,i,j));
    }
} seg;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll k;
    if (!(cin >> n >> k)) return 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }

    // Build segment tree over a[] to support min/max in ranges
    seg.build(1, 1, n, false);

    int l = 1, r = 1;
    while (r <= n) {
        // ensure [l..r] satisfies max-min <= k; move l forward while it doesn't
        while (l <= r && seg.querymax(1,1,n,l,r) - seg.querymin(1,1,n,l,r) > k) ++l;
        // after adjustment, [l..r] is valid (or l == r+1 meaning no valid window ending at r)
        if (l <= r) f[r] = { pre[r] - pre[l-1], l };
        else f[r] = { LLONG_MIN, r+1 }; // mark invalid
        ++r;
    }

    // Build segment tree over f[].first (only valid positions meaningful)
    seg.build(1, 1, n, true);

    ll best = LLONG_MIN;
    for (int i = 1; i <= n; ++i) {
        if (f[i].first == LLONG_MIN) continue; // no valid segment ending at i
        int j = f[i].second;
        // combine best segment that ends before j (range [1..j-1]) with current segment f[i]
        if (j > 1) {
            ll left_max = seg.querymax(1,1,n,1,j-1);
            if (left_max != LLONG_MIN) best = max(best, f[i].first + left_max);
        } else {
            // no left segment; consider single segment alone
            best = max(best, f[i].first);
        }
        // also consider using single segment only (in case there is no left part)
        best = max(best, f[i].first);
    }

    if (best == LLONG_MIN) best = 0;
    cout << best << "\n";
    return 0;
}

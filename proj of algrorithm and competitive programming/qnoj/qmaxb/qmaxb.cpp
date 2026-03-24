#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

const int maxn = 100005;
int n, q;
long long st[4 * maxn], a[maxn];

void build(int id, int l, int r) {
    if(l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    st[id] = max(st[2 * id], st[2 * id + 1]);
}

void upd(int id, int l, int r, int i, int v) {
    if(i < l || i > r) return;
    if(l == r) {
        st[id] += v;
        a[l] += v;
        return;
    }
    int mid = (l + r) >> 1;
    if(i <= mid)
        upd(2 * id, l, mid, i, v);
    else
        upd(2 * id + 1, mid + 1, r, i, v);

    st[id] = max(st[2 * id], st[2 * id + 1]);
}

long long query(int id, int l, int r, int u, int v) {
    if(r < u || l > v)
        return 0;
    if(l >= u && r <= v)
        return st[id];
    int mid = (l + r) >> 1;
    long long k1 = query(2 * id, l, mid, u, v);
    long long k2 = query(2 * id + 1, mid + 1, r, u, v);
    return max(k1, k2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        a[i] = 0;
    }

    build(1, 1, n);

    while(q--) {
        int t, i, v;
        cin >> t >> i >> v;
        if(t == 0) {
            upd(1, 1, n, i, v);
        } else {
            cout << query(1, 1, n, i, v) << "\n";
        }
    }

    return 0;
}

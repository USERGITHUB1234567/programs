#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

const int maxn = 200005;
long long p[maxn], st[4 * maxn];
int n, m;
int ql, qr;
void build(int id, int l, int r) {
    if (l == r) {
        st[id] = p[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    st[id] = min(st[id << 1], st[id << 1 | 1]);
}
int query(int id, int l, int r, long long t) {
    if (r < ql || l > qr || st[id] > t)
        return -1;
    if (l == r)
        return l;
    int mid = (l + r) >> 1;
    int res = query(id << 1, l, mid, t);
    if (res != -1)
        return res;
    return query(id << 1 | 1, mid + 1, r, t);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    build(1, 1, n);

    while(m--) {
        long long t;
        int l, r_local;
        cin >> t >> l >> r_local;
        ql = l;
        qr = r_local;
        int vt = l;
        while (vt <= qr) {
            ql = vt;
            int j = query(1, 1, n, t);
            if (j == -1) break;
            t %= p[j];
            vt = j + 1;
        }
        cout << t << "\n";
    }

    return 0;
}

#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

const int maxn = 100005;
int st[4 * maxn], a[maxn];
const int inf = 1e9;
int n, m;

void build(int id, int l, int r) {
    if(l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    st[id] = min(st[2 * id], st[2 * id + 1]);
}

void upd(int id, int l, int r, int i, int v) {
    if(l == r) {
        st[id] = v;
        return;
    }
    int mid = (l + r) >> 1;
    if(i <= mid)
        upd(2 * id, l, mid, i, v);
    else
        upd(2 * id + 1, mid + 1, r, i, v);
    st[id] = min(st[2 * id], st[2 * id + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if(u > r || v < l) return inf;
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) >> 1;
    int ls = get(2 * id, l, mid, u, v);
    int rs = get(2 * id + 1, mid + 1, r, u, v);
    return min(ls, rs);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Xây dựng cây phân đoạn với id bắt đầu từ 1
    build(1, 0, n - 1);

    while(m--) {
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1) {
            // Cập nhật: gán a[x] = y
            upd(1, 0, n - 1, x, y);
        } else if(t == 2) {
            // Truy vấn: lấy giá trị nhỏ nhất trên đoạn [x, y-1]
            cout << get(1, 0, n - 1, x, y - 1) << "\n";
        }
    }

    return 0;
}

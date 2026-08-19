#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

const int maxn = 100005;
const int INF = 1e9 + 1;

struct Node {
    int mn, cnt;
};

int n, m;
int a[maxn];
Node seg[4 * maxn];

Node combine(Node left, Node right) {
    Node res;
    if(left.mn < right.mn) {
        res.mn = left.mn;
        res.cnt = left.cnt;
    } else if(right.mn < left.mn) {
        res.mn = right.mn;
        res.cnt = right.cnt;
    } else {
        res.mn = left.mn;
        res.cnt = left.cnt + right.cnt;
    }
    return res;
}

void build(int idx, int l, int r) {
    if(l == r) {
        seg[idx].mn = a[l];
        seg[idx].cnt = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(idx * 2, l, mid);
    build(idx * 2 + 1, mid + 1, r);
    seg[idx] = combine(seg[idx * 2], seg[idx * 2 + 1]);
}

void update(int idx, int l, int r, int pos, int val) {
    if(l == r) {
        seg[idx].mn = val;
        seg[idx].cnt = 1;
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid)
        update(idx * 2, l, mid, pos, val);
    else
        update(idx * 2 + 1, mid + 1, r, pos, val);
    seg[idx] = combine(seg[idx * 2], seg[idx * 2 + 1]);
}

Node query(int idx, int l, int r, int ql, int qr) {
    if(ql > r || qr < l) return {INF, 0};
    if(ql <= l && r <= qr) return seg[idx];
    int mid = (l + r) >> 1;
    Node leftResult = query(idx * 2, l, mid, ql, qr);
    Node rightResult = query(idx * 2 + 1, mid + 1, r, ql, qr);
    return combine(leftResult, rightResult);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(1, 0, n - 1);

    while(m--) {
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1) {
            update(1, 0, n - 1, x, y);
        }
        else if(t == 2) {
            Node res = query(1, 0, n - 1, x, y - 1);
            cout << res.mn << " " << res.cnt << "\n";
        }
    }
    return 0;
}

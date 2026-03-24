#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define fi first
#define se second
using namespace std;

const int maxn = 100005;
const int inf = INT_MAX;

int n;
int heavy[maxn], par[maxn], d[maxn], pos[maxn], head[maxn], cur = 0;
int a[maxn], e[maxn];
int weight[maxn], nodeAtEdge[maxn];
vector<pair<int,int>> adj[maxn];

// segment tree with range‐flip (negate) and range‐max query
struct segtree {
    // st[id].fi = max in segment, st[id].se = min in segment
    pair<int,int> st[4*maxn];
    bool flip[4*maxn];

    void build(int id, int l, int r) {
        flip[id] = false;
        if (l == r) {
            st[id].fi = st[id].se = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(id<<1,    l, m);
        build(id<<1|1, m+1, r);
        st[id].fi = max(st[id<<1].fi,    st[id<<1|1].fi);
        st[id].se = min(st[id<<1].se,    st[id<<1|1].se);
    }

    // apply a flip (negate) on one node
    void nodeflip(int id) {
        int old_max = st[id].fi;
        int old_min = st[id].se;
        st[id].fi = -old_min;
        st[id].se = -old_max;
        flip[id] = !flip[id];
    }

    // push lazy flag down
    void down(int id) {
        if (!flip[id]) return;
        nodeflip(id<<1);
        nodeflip(id<<1|1);
        flip[id] = false;
    }

    // point‐update: assign a[l==r] = v
    void upd(int id, int l, int r, int idx, int v) {
        if (l == r) {
            st[id].fi = st[id].se = v;
            a[l] = v;
            return;
        }
        down(id);
        int m = (l + r) >> 1;
        if (idx <= m) upd(id<<1,    l, m, idx, v);
        else         upd(id<<1|1, m+1, r, idx, v);
        st[id].fi = max(st[id<<1].fi,    st[id<<1|1].fi);
        st[id].se = min(st[id<<1].se,    st[id<<1|1].se);
    }

    // range‐flip (negate) on [i..j]
    void lazyupd(int id, int l, int r, int i, int j) {
        if (j < l || r < i) return;
        if (i <= l && r <= j) {
            nodeflip(id);
            return;
        }
        down(id);
        int m = (l + r) >> 1;
        lazyupd(id<<1,    l, m, i, j);
        lazyupd(id<<1|1, m+1, r, i, j);
        st[id].fi = max(st[id<<1].fi,    st[id<<1|1].fi);
        st[id].se = min(st[id<<1].se,    st[id<<1|1].se);
    }

    // range‐max query on [u..v]
    int query(int id, int l, int r, int u, int v) {
        if (r < u || v < l) return -inf;
        if (u <= l && r <= v) {
            return st[id].fi;
        }
        down(id);
        int m = (l + r) >> 1;
        return max(
            query(id<<1,    l, m, u, v),
            query(id<<1|1, m+1, r, u, v)
        );
    }
} seg;

int dfs(int u) {
    int sz = 1, szm = 0;
    heavy[u] = 0;
    for (auto &ed : adj[u]) {
        int v = ed.fi, idx = ed.se;
        if (v == par[u]) continue;
        par[v] = u;
        d[v] = d[u] + 1;
        e[v] = weight[idx];
        nodeAtEdge[idx] = v;
        int csz = dfs(v);
        if (csz > szm) {
            szm = csz;
            heavy[u] = v;
        }
        sz += csz;
    }
    return sz;
}

void decompose(int u, int h) {
    head[u] = h;
    pos[u] = ++cur;
    a[cur] = e[u];
    if (heavy[u])
        decompose(heavy[u], h);
    for (auto &ed : adj[u]) {
        int v = ed.fi;
        if (v == par[u] || v == heavy[u]) continue;
        decompose(v, v);
    }
}

// path‐max query
int hldquery(int a, int b) {
    if (a == b) return 0;
    int res = -inf;
    while (head[a] != head[b]) {
        if (d[ head[a] ] > d[ head[b] ]) swap(a, b);
        int curmx = seg.query(1, 1, n, pos[ head[b] ], pos[b]);
        res = max(res, curmx);
        b = par[ head[b] ];
    }
    // same head
    if (a != b) {
        if (d[a] > d[b]) swap(a, b);
        // exclude a (LCA) itself
        int curmx = seg.query(1, 1, n, pos[a] + 1, pos[b]);
        res = max(res, curmx);
    }
    return res;
}

// path‐negate update
void hldupdate(int a, int b) {
    if (a == b) return;
    while (head[a] != head[b]) {
        if (d[ head[a] ] > d[ head[b] ]) swap(a, b);
        seg.lazyupd(1, 1, n, pos[ head[b] ], pos[b]);
        b = par[ head[b] ];
    }
    if (a != b) {
        if (d[a] > d[b]) swap(a, b);
        seg.lazyupd(1, 1, n, pos[a] + 1, pos[b]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        par[i] = 0; d[i] = 0; e[i] = 0;
    }
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        weight[i] = w;
    }

    // build HLD
    par[1] = 0; d[1] = 0; e[1] = 0;
    dfs(1);
    cur = 0;
    decompose(1, 1);

    // build segment tree
    seg.build(1, 1, n);

    // process commands
    string cmd;
    while (cin >> cmd) {
        if (cmd == "DONE") break;
        if (cmd == "QUERY") {
            int u, v;
            cin >> u >> v;
            cout << hldquery(u, v) << "\n";
        }
        else if (cmd == "CHANGE") {
            int idx, v;
            cin >> idx >> v;
            int node = nodeAtEdge[idx];
            seg.upd(1, 1, n, pos[node], v);
        }
        else if (cmd == "NEGATE") {
            int u, v;
            cin >> u >> v;
            hldupdate(u, v);
        }
    }
    return 0;
}

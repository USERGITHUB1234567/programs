#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
vector<int> adj[MAXN + 1];
int parent[MAXN + 1], depth[MAXN + 1], heavy[MAXN + 1];
int head[MAXN + 1], pos[MAXN + 1], invp[MAXN + 1];
int curPos = 0;
int color[MAXN + 1]; 
int dfs(int u) {
    int size = 1, maxSub = 0;
    for (int v : adj[u]) {
        if (v == parent[u]) continue;
        parent[v] = u;
        depth[v] = depth[u] + 1;
        int sub = dfs(v);
        if (sub > maxSub) {
            maxSub = sub;
            heavy[u] = v;
        }
        size += sub;
    }
    return size;
}

void decompose(int u, int h) {
    head[u]  = h;
    pos[u]   = ++curPos;
    invp[curPos] = u;
    if (heavy[u]) 
        decompose(heavy[u], h);
    for (int v : adj[u]) {
        if (v == parent[u] || v == heavy[u]) continue;
        decompose(v, v);
    }
}
struct SegTree {
    int n;
    vector<int> st;
    const int INF = MAXN + 5;

    SegTree(int _n = 0) { init(_n); }

    void init(int _n) {
        n = _n;
        st.assign(4 * (n + 1), INF);
    }
    void update(int id, int l, int r, int idx, int val) {
        if (l == r) {
            st[id] = val ? l : INF;
            return;
        }
        int m = (l + r) >> 1;
        if (idx <= m) update(id << 1, l, m, idx, val);
        else          update(id << 1 | 1, m + 1, r, idx, val);
        st[id] = min(st[id << 1], st[id << 1 | 1]);
    }

    int queryFirst(int id, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return INF;
        if (ql <= l && r <= qr) return st[id];
        int m = (l + r) >> 1;
        int left = queryFirst(id << 1,     l,    m, ql, qr);
        if (left != INF) return left;
        return queryFirst(id << 1 | 1, m + 1, r, ql, qr);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    parent[1] = 0;
    depth[1] = 0;
    dfs(1);
    decompose(1, 1);

    SegTree seg(n);

    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int u;
            cin >> u;
            color[u] ^= 1;
            seg.update(1, 1, n, pos[u], color[u]);
        } 
        else {
            int v;
            cin >> v;
            vector<pair<int,int>> chains;
            int x = v;
            while (head[x] != 1) {
                chains.emplace_back(pos[head[x]], pos[x]);
                x = parent[head[x]];
            }
            chains.emplace_back(pos[1], pos[x]);
            int answer = -1;
            for (auto it = chains.rbegin(); it != chains.rend(); ++it) {
                int L = it->first, R = it->second;
                int found = seg.queryFirst(1, 1, n, L, R);
                if (found <= n) {
                    answer = invp[found];
                    break;
                }
            }
            cout << answer << "\n";
        }
    }

    return 0;
}

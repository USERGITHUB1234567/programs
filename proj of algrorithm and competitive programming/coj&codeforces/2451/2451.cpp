#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
const int maxn = 100005, maxl = 20;

int n, m;
int d[maxn], p[maxn][maxl], mx[maxn][maxl];
vector<pair<int,int>> adj[maxn];

struct disjoint_sets {
    int pa[maxn];
    disjoint_sets() {
        for (int i = 0; i < maxn; i++) 
            pa[i] = i;
    }
    int found(int u) {
        return pa[u] == u ? u : pa[u] = found(pa[u]);
    }
    void unite(int u, int v) {
        u = found(u);
        v = found(v);
        if (u != v) pa[u] = v;
    }
} dsu;

// build depths, p[][0], mx[][0]
void dfs(int u, int pr) {
    for (auto [v, w] : adj[u]) {
        if (v == pr) continue;
        d[v] = d[u] + 1;
        p[v][0] = u;
        mx[v][0] = w;
        dfs(v, u);
    }
}

int mxlca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    int res = 0;
    // lift u up so depth[u] == depth[v]
    for (int i = maxl - 1; i >= 0; i--) {
        if (d[u] - (1 << i) >= d[v]) {
            res = max(res, mx[u][i]);
            u = p[u][i];
        }
    }
    if (u == v) return res;
    // lift both until parents equal
    for (int i = maxl - 1; i >= 0; i--) {
        if (p[u][i] != p[v][i]) {
            res = max(res, mx[u][i]);
            res = max(res, mx[v][i]);
            u = p[u][i];
            v = p[v][i];
        }
    }
    // last edge to LCA
    res = max(res, mx[u][0]);
    res = max(res, mx[v][0]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    vector<tuple<int,int,int>> edges;
    edges.reserve(m);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(w, u, v);
    }

    ll res = 0;
    sort(all(edges));
    for (auto &e : edges) {
        int w, u, v;
        tie(w, u, v) = e;
        if (dsu.found(u) != dsu.found(v)) {
            dsu.unite(u, v);
            adj[u].eb(v, w);
            adj[v].eb(u, w);
            res += w;
        }
    }

    // initialize root = 1
    d[1] = 0;
    p[1][0] = 0;
    mx[1][0] = 0;
    dfs(1, 0);

    // binary‐lift preprocessing
    for (int j = 1; j < maxl; j++) {
        for (int i = 1; i <= n; i++) {
            p[i][j] = p[p[i][j-1]][j-1];
            mx[i][j] = max(mx[i][j-1], mx[p[i][j-1]][j-1]);
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << res - mxlca(u, v) << "\n";
    }
    return 0;
}

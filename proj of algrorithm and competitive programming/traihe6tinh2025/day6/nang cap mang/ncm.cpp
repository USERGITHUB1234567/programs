#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

const int maxn = 1e5 + 5;
const int maxl = 20;

int n, m, logn;
int p[maxn][maxl], pr[maxn], d[maxn], mn[maxn][maxl];
vector<pair<int, int>> adj[maxn];

struct Edge {
    int u, v, w;
    bool operator < (const Edge& other) const {
        return w > other.w;
    }
};

vector<Edge> edges;
int findset(int u) {
    if (pr[u] == 0) return u;
    return pr[u] = findset(pr[u]);
}
bool unite(int u, int v) {
    u = findset(u);
    v = findset(v);
    if (u == v) return false;
    pr[u] = v;
    return true;
}
void dfs(int u, int pa, int w) {
    p[u][0] = pa;
    mn[u][0] = w;
    for (int i = 1; i <= logn; i++) {
        if (p[u][i - 1] == -1) break;
        p[u][i] = p[p[u][i - 1]][i - 1];
        mn[u][i] = min(mn[u][i - 1], mn[p[u][i - 1]][i - 1]);
    }
    for (auto [v, wt] : adj[u]) {
        if (v != pa) {
            d[v] = d[u] + 1;
            dfs(v, u, wt);
        }
    }
}

int minlca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    int res = INT_MAX;
    for (int j = logn; j >= 0; j--) {
        if (p[u][j] != -1 && d[p[u][j]] >= d[v]) {
            res = min(res, mn[u][j]);
            u = p[u][j];
        }
    }
    if (u == v) return res;
    for (int j = logn; j >= 0; j--) {
        if (p[u][j] != -1 && p[u][j] != p[v][j]) {
            res = min({res, mn[u][j], mn[v][j]});
            u = p[u][j];
            v = p[v][j];
        }
    }
    return min({res, mn[u][0], mn[v][0]});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    edges.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end());

    vector<Edge> extraEdges;
    for (auto &e : edges) {
        if (unite(e.u, e.v)) {
            adj[e.u].emplace_back(e.v, e.w);
            adj[e.v].emplace_back(e.u, e.w);
        } else {
            extraEdges.push_back(e);
        }
    }
    logn = 0;
    while ((1 << logn) <= n) logn++;
    memset(p, -1, sizeof p);
    d[1] = 0;
    dfs(1, -1, INT_MAX);
    long long totalCost = 0;
    for (auto &e : extraEdges) {
        int bottleneck = minlca(e.u, e.v);
        totalCost += (bottleneck - e.w);
    }

    cout << totalCost << '\n';
    return 0;
}

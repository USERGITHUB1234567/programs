#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

vector<pair<int,int>> adj[100005];
int n, m, logn, p[100005][17], d[100005], mn[100005][17], mx[100005][17];

int lca(int u, int v, int &cmin, int &cmax) {
    if (d[u] < d[v]) swap(u, v);
    cmin = 1e9; cmax = 0;
    for (int j = logn; j >= 0; j--) {
        if (d[u] - (1 << j) >= d[v]) {
            cmin = min(cmin, mn[u][j]);
            cmax = max(cmax, mx[u][j]);
            u = p[u][j];
        }
    }
    if (u == v) return u;
    for (int j = logn; j >= 0; j--) {
        if (p[u][j] != p[v][j]) {
            cmin = min({cmin, mn[u][j], mn[v][j]});
            cmax = max({cmax, mx[u][j], mx[v][j]});
            u = p[u][j];
            v = p[v][j];
        }
    }
    cmin = min({cmin, mn[u][0], mn[v][0]});
    cmax = max({cmax, mx[u][0], mx[v][0]});
    return p[u][0];
}

void dfs(int u, int f) {
    for (auto [v, w] : adj[u]) {
        if (v != f) {
            d[v] = d[u] + 1;
            p[v][0] = u;
            mn[v][0] = mx[v][0] = w;
            dfs(v, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for (logn = 1; (1 << logn) <= n; logn++);
    logn--;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= logn; j++) {
            p[i][j] = -1;
            mn[i][j] = 1e9;
            mx[i][j] = 0;
        }
    }
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    d[1] = 0;
    dfs(1, -1);
    for (int j = 1; j <= logn; j++) {
        for (int i = 1; i <= n; i++) {
            if (p[i][j-1] != -1) {
                p[i][j] = p[p[i][j-1]][j-1];
                mn[i][j] = min(mn[i][j-1], mn[p[i][j-1]][j-1]);
                mx[i][j] = max(mx[i][j-1], mx[p[i][j-1]][j-1]);
            }
        }
    }
    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        int cmin, cmax;
        lca(u, v, cmin, cmax);
        cout << cmin << " " << cmax << "\n";
    }
    return 0;
}


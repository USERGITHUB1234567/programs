#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

const int MAXN = 200001;
int n, k, logn, p[MAXN][18], d[MAXN];
vector<int> adj[MAXN], g[100001];

void dfs(int u, int f) {
    for (int v : adj[u]) {
        if (v != f) {
            d[v] = d[u] + 1;
            p[v][0] = u;
            dfs(v, u);
        }
    }
}
int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    for (int j = logn; j >= 0; j--) {
        if (d[p[u][j]] >= d[v]) u = p[u][j];
    }
    if (u == v) return u;
    for (int j = logn; j >= 0; j--) {
        if (p[u][j] != p[v][j]) {
            u = p[u][j];
            v = p[v][j];
        }
    }
    return p[u][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int a, pn;
        cin >> a >> pn;
        g[a].push_back(i);
        if (pn != 0) {
            adj[i].push_back(pn);
            adj[pn].push_back(i);
        }
    }

    for (logn = 1; (1 << logn) <= n; logn++);
    logn--;
    dfs(1, 0);

    for (int j = 1; j <= logn; j++) {
        for (int i = 1; i <= n; i++) {
            //if (p[i][j - 1] != 0) {
                p[i][j] = p[p[i][j - 1]][j - 1];
            //}
        }
    }

    for (int i = 1; i <= k; i++) {
        int u = g[i][0];
        for (int v : g[i]) {
            if (d[v] > d[u]) u = v;
        }
        int ans = 0;
        for (int v : g[i]) {
            int anc = lca(u, v);
            ans = max(ans, d[u] + d[v] - 2 * d[anc]);
        }
        cout << ans << "\n";
    }

    return 0;
}

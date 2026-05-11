#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int n, m, logn, r;
vector<int> adj[100005];
int d[100005], p[100005][17];
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
void dfs(int u, int f) {
    for (int i : adj[u]) {
        if (i != f) {
            p[i][0] = u;
            d[i] = d[u] + 1;
            dfs(i, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (logn = 1; (1 << logn) <= n; logn++);
    logn--;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(d, 0, sizeof(d));
    dfs(1, 0);

    for (int j = 1; j <= logn; j++) {
        for (int i = 1; i <= n; i++) {
            p[i][j] = p[p[i][j - 1]][j - 1];
        }
    }

    cin >> m;
    while (m--) {
        char c;
        cin >> c;
        if (c == '!') {
            cin >> r;
        } else {
            int u, v;
            cin >> u >> v;
            int an0 = lca(u, v), an1 = lca(u, r), an2 = lca(v, r);
            if (an0 == an1) cout << an2 << "\n";
            else if (an0 == an2) cout << an1 << "\n";
            else cout << an0 << "\n";
        }
    }

    return 0;
}

#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int n, m, q;
int ans[100005], u[100005], d[100005], c[100005];
bool vis[100005], vis2[100005][11];
vector<int> adj[100005];

void dfs1(int i, int depth, int color) {
    if (depth < 0 || vis[i]) return;
    ans[i] = color;
    vis[i] = true;
    for (int v : adj[i]) {
        if (!vis[v]) {
            dfs1(v, depth - 1, color);
        }
    }
}

void dfs2(int u, int depth, int color) {
    if (depth < 0 || vis2[u][depth]) return;
    if (ans[u] == 0) ans[u] = color;
    vis2[u][depth] = true;
    for (int v : adj[u]) dfs2(v, depth - 1, color);
}

void sub1() {
    while (q--) {
        int u, d, c;
        memset(vis, false, sizeof(vis));
        cin >> u >> d >> c;
        dfs1(u, d, c);
    }
}

void sub2() {
    for (int i = 1; i <= q; i++) cin >> u[i] >> d[i] >> c[i];
    memset(vis2, false, sizeof(vis2));
    for (int i = q; i >= 1; i--) dfs2(u[i], d[i], c[i]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> q;
    sub2();
    for (int i = 1; i <= n; i++) cout << ans[i] << "\n";
    return 0;
}

/*#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m, logn, p[100001][17], d[100001];
vector<pair<int,int>>adj[100005];
long long dist[100005];
int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    for (int j = logn; j >= 0; j--)
        if (d[p[u][j]] >= d[v]) u = p[u][j];
    if (u == v) return u;
    for (int j = logn; j >= 0; j--)
        if (p[u][j] != p[v][j]) {
            u = p[u][j];
            v = p[v][j];
        }
    return p[u][0];
}
void dfs(int u, int f) {
    for (int i = 0; i < adj[u].size(); i++) {
        if (adj[u][i].first != f) {
            int t=adj[u][i].first;
            p[t][0] = u;
            d[t] = d[u] + 1;
            dist[t] = dist[u] + adj[u][i].second;
            dfs(t, u);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for (logn = 1; (1 << logn) <= n; logn++);
    logn--;

    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    memset(d, 0, sizeof(d));
    dist[1]=0;
    dfs(1, 0);
    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        int t = lca(u, v);
        cout << d[u] + d[v] - 2*d[t] << "\n";
    }
    return 0;
}*/
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

const int MAXN = 100005;
int n, m, logn, p[MAXN][17], d[MAXN];
vector<pair<int, int>> adj[MAXN];
long long dist[MAXN];

int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    for (int j = logn; j >= 0; j--)
        if (d[p[u][j]] >= d[v]) u = p[u][j];
    if (u == v) return u;
    for (int j = logn; j >= 0; j--)
        if (p[u][j] != p[v][j]) {
            u = p[u][j];
            v = p[v][j];
        }
    return p[u][0];
}

void dfs(int u, int f) {
    for (auto &edge : adj[u]) {
        int t = edge.first;
        if (t != f) {
            p[t][0] = u;
            d[t] = d[u] + 1;
            dist[t] = dist[u] + edge.second;
            dfs(t, u);
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
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    memset(d, 0, sizeof(d));
    dist[1] = 0;
    dfs(1, 0);

    for (int j = 1; j <= logn; j++)
        for (int i = 1; i <= n; i++)
            if (p[i][j - 1] != 0)
                p[i][j] = p[p[i][j - 1]][j - 1];

    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        int t = lca(u, v);
        cout << dist[u] + dist[v] - 2 * dist[t] << "\n";
    }

    return 0;
}


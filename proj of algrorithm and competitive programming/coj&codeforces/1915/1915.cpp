#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;

const int maxn = 200005;
struct edge {
    int u, v, w, i;
} e[maxn];

int p[maxn], n, m, pr[maxn][20], d[maxn], mx[maxn][20], ans[maxn], logn;
vector<pair<int,int>> adj[maxn], a2[maxn];
bool mk[maxn];

int findset(int u) {
    if (p[u] == 0) return u;
    return p[u] = findset(p[u]);
}

bool unite(int u, int v) {
    u = findset(u);
    v = findset(v);
    if (u == v) return false;
    p[u] = v;
    return true;
}

void dfs(int u, int pa) {
    pr[u][0] = pa;
    d[u] = (u == pa ? 1 : d[pa] + 1);
    if (u == pa) mx[u][0] = 0;
    for (auto [v, w] : a2[u]) {
        if (v == pa) continue;
        mx[v][0] = w;
        dfs(v, u);
    }
}

pair<int,int> lca(int u, int v) {
    int re = 0;
    if (d[u] < d[v])
        swap(u, v);
    for (int i = logn; i >= 0; i--) {
        if (d[ pr[u][i] ] >= d[v]) {
            re = max(re, mx[u][i]);
            u = pr[u][i];
        }
    }
    if (u == v)
        return {u, re};
    for (int i = logn; i >= 0; i--) {
        if (pr[u][i] != pr[v][i]) {
            re = max({ re, mx[u][i], mx[v][i] });
            u = pr[u][i];
            v = pr[v][i];
        }
    }
    re = max({ re, mx[u][0], mx[v][0] });
    return { pr[u][0], re };
}


bool cmp(edge a, edge b) {
    return a.w < b.w;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        e[i].u = u;
        e[i].v = v;
        e[i].w = w;
        e[i].i = i;
    }
    sort(e + 1, e + 1 + m, cmp);
    int t = 0;
    for (int i = 1; i <= m; i++) {
        int u = e[i].u, v = e[i].v, w = e[i].w, id = e[i].i;
        if (unite(u, v)) {
            t += w;
            a2[u].push_back({v, w});
            a2[v].push_back({u, w});
            mk[id] = true;
        }
    }
    for (logn = 1; (1 << logn) <= n; logn++);
    logn--;
    dfs(1, 1);
    for (int j = 1; j <= logn; j++) {
        for (int i = 1; i <= n; i++) {
            pr[i][j] = pr[pr[i][j - 1]][j - 1];
            mx[i][j] = max(mx[i][j - 1], mx[pr[i][j - 1]][j - 1]);
        }
    }
    for (int i = 1; i <= m; i++) {
        int id = e[i].i;
        if (mk[id]) {
            ans[id] = t;
        } else {
            auto re = lca(e[i].u, e[i].v);
            ans[id] = t + e[i].w - re.second;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}

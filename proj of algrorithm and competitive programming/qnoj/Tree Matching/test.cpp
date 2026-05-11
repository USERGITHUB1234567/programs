#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 200000 + 5;
int n;
vector<int> adj[MAXN];
ll f[MAXN][2];

void dfs(int u, int p) {
    // khởi tạo cho nút u
    f[u][0] = 0;
    f[u][1] = 0;

    // tính tổng các max(dp0, dp1) của con
    ll sumBest = 0;
    for (int v : adj[u]) if (v != p) {
        dfs(v, u);
        sumBest += max(f[v][0], f[v][1]);
    }
    f[u][0] = sumBest;

    // thử ghép u với từng con v
    ll bestWithChild = 0;
    for (int v : adj[u]) if (v != p) {
        ll cand = 1 + f[v][0] + (sumBest - max(f[v][0], f[v][1]));
        if (cand > bestWithChild) bestWithChild = cand;
    }
    f[u][1] = bestWithChild;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n)) return 0;
    for (int i = 1; i <= n; ++i) adj[i].clear();

    for (int i = 0; i < n-1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    cout << max(f[1][0], f[1][1]) << '\n';
    return 0;
}

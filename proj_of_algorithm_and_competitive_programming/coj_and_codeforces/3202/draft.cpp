#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<pair<int,int>> edges;
    edges.reserve(m);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v; --u; --v;
        edges.emplace_back(u, v);
    }

    int N = 2 * n;
    vector<vector<int>> g(N);
    vector<int> indeg(N, 0);
    // build G' as described
    for (auto &e : edges) {
        int u = e.first, v = e.second;
        if (a[u] == a[v]) {
            int from1 = u;
            int to1 = n + v;
            int from2 = v;
            int to2 = n + u;
            g[from1].push_back(to1); indeg[to1]++;
            g[from2].push_back(to2); indeg[to2]++;
        } else {
            int from1 = n + u;
            int to1 = v;
            int from2 = n + v;
            int to2 = u;
            g[from1].push_back(to1); indeg[to1]++;
            g[from2].push_back(to2); indeg[to2]++;
        }
    }

    // Kahn topological sort to detect cycle and get order
    queue<int> q;
    for (int i = 0; i < N; ++i) if (indeg[i] == 0) q.push(i);
    vector<int> topo;
    topo.reserve(N);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        topo.push_back(v);
        for (int to : g[v]) {
            if (--indeg[to] == 0) q.push(to);
        }
    }
    if ((int)topo.size() < N) {
        cout << "infinity\n";
        return 0;
    }

    // part assignment: part[i] = a[i], part[n+i] = 2 + a[i]
    vector<int> part(N);
    for (int i = 0; i < n; ++i) {
        part[i] = a[i];
        part[n + i] = 2 + a[i];
    }

    // DP longest path following part increment by 1 mod 4
    const int INF_NEG = -1000000000;
    vector<int> dp(N, 1); // path length in nodes, at least 1 (single vertex)
    for (int v : topo) {
        for (int to : g[v]) {
            if (part[to] == (part[v] + 1) % 4) {
                if (dp[to] < dp[v] + 1) dp[to] = dp[v] + 1;
            }
        }
    }

    // For each residue r compute max dp ending at part == r
    vector<int> maxLen(4, 0);
    for (int i = 0; i < N; ++i) {
        int p = part[i];
        maxLen[p] = max(maxLen[p], dp[i]);
    }

    int k = INT_MAX;
    for (int r = 0; r < 4; ++r) {
        // if no vertex has this part, dp values remain 0 -> treat as 0 length
        if (maxLen[r] > 0) k = min(k, maxLen[r]);
    }
    if (k == INT_MAX) {
        // no vertices? degenerate, but print infinity for safety
        cout << "infinity\n";
    } else {
        cout << (k + 1) << "\n";
    }
    return 0;
}

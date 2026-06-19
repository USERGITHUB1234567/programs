#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

struct Dinic {
    struct Edge {
        int to, rev, cap, flow;
    };

    int n;
    vector<vector<Edge>> g;
    vector<int> level, it;

    Dinic(int n = 0) { init(n); }

    void init(int n_) {
        n = n_;
        g.assign(n, {});
        level.assign(n, 0);
        it.assign(n, 0);
    }

    void addEdge(int v, int to, int cap) {
        Edge a{to, (int)g[to].size(), cap, 0};
        Edge b{v, (int)g[v].size(), 0, 0};
        g[v].push_back(a);
        g[to].push_back(b);
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (auto &e : g[v]) {
                if (level[e.to] == -1 && e.flow < e.cap) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }

    int dfs(int v, int t, int f) {
        if (!f || v == t) return f;
        for (int &i = it[v]; i < (int)g[v].size(); ++i) {
            Edge &e = g[v][i];
            if (level[e.to] == level[v] + 1 && e.flow < e.cap) {
                int got = dfs(e.to, t, min(f, e.cap - e.flow));
                if (got) {
                    e.flow += got;
                    g[e.to][e.rev].flow -= got;
                    return got;
                }
            }
        }
        return 0;
    }

    long long maxflow(int s, int t) {
        long long ans = 0;
        while (bfs(s, t)) {
            fill(it.begin(), it.end(), 0);
            while (int pushed = dfs(s, t, INT_MAX)) ans += pushed;
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    long long sa = 0, sb = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sa += a[i];
    }
    for (int j = 0; j < n; ++j) {
        cin >> b[j];
        sb += b[j];
    }

    if (sa != sb) {
        cout << -1;
        return 0;
    }

    int S = 2 * n;
    int T = 2 * n + 1;
    Dinic dinic(2 * n + 2);

    for (int i = 0; i < n; ++i) dinic.addEdge(S, i, a[i]);
    for (int j = 0; j < n; ++j) dinic.addEdge(n + j, T, b[j]);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dinic.addEdge(i, n + j, 1);
        }
    }

    long long flow = dinic.maxflow(S, T);
    if (flow != sa) {
        cout << -1;
        return 0;
    }

    vector<string> ans(n, string(n, '.'));

    for (int i = 0; i < n; ++i) {
        for (auto &e : dinic.g[i]) {
            if (n <= e.to && e.to < 2 * n && e.flow == 1) {
                int j = e.to - n;
                ans[i][j] = 'X';
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}
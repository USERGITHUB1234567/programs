#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long INF = 1e18;
struct E {
    int u, v;
    long long w;
};
int n, m;
vector<E> edges;
vector<long long> d;
vector<bool> reach;
void dij() {
    vector<vector<int>> rev_adj(n + 1);
    for (auto &e : edges) {
        rev_adj[e.v].push_back(e.u);
    }
    queue<int> q;
    q.push(n);
    reach[n] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : rev_adj[u]) {
            if (!reach[v]) {
                reach[v] = true;
                q.push(v);
            }
        }
    }
}
int main() {
    cin >> n >> m;
    edges.resize(m);
    d.assign(n + 1, -INF);
    reach.assign(n + 1, false);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    dij();
    d[1] = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (auto &e : edges) {
            if (d[e.u] != -INF && d[e.u] + e.w > d[e.v]) {
                d[e.v] = d[e.u] + e.w;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto &e : edges) {
            if (d[e.u] != -INF && d[e.u] + e.w > d[e.v] && reach[e.v]) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << d[n];
    return 0;
}

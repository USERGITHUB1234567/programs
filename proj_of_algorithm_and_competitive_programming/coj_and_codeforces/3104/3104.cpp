#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

const long long INF = 9e18;
long long n, m, k;
long long t[1000006], c[1000006];
vector<pair<long long, pair<long long, long long>>> adj[1100006];
pair<long long, long long> f[1100006];

pair <long long, long long> operator + (pair <long long, long long> a, pair <long long, long long> b)
{
    return {a.first + b.first, a.second + b.second};
}

void dijkstra(int s) {
    for (int i = 1; i <= n + k; i++) {
        f[i] = {INF, INF};
    }
    f[s] = {0, 0};
    priority_queue<
        pair<pair<long long, long long>, long long>
    > pq;
    pq.push({{0, 0}, s});

    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();
        pair <long long, long long> cur = {-top.first.first, -top.first.second};
        long long u       = top.second;
        if (cur > f[u]) continue;
        for (auto &e : adj[u]) {
            long long v        = e.first;
            long long add_cost = e.second.first;
            long long is_bus   = e.second.second;
            pair <long long, long long> ss = e.second, neww = cur + ss;
            if (neww < f[v]) {
                f[v] = neww;
                pq.push({{-neww.first, -neww.second}, v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        cin >> t[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < m; i++) {
        long long u, v, tp;
        cin >> u >> v >> tp;
        long long virtual_node = n + tp;
        adj[u].push_back({virtual_node, {c[tp], t[tp]}});
        adj[v].push_back({virtual_node, {c[tp], t[tp]}});
        adj[virtual_node].push_back({u, {0, 0}});
        adj[virtual_node].push_back({v, {0, 0}});
    }

    dijkstra(1);
    cout << f[n].first << " " << f[n].second;
    return 0;
}

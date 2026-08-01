#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

const int INF = 1e9;
vector<pair<int, int>> adj[200005];
int dist[200005];
int n, m, k, s, V;
vector<int> v, h, t;

void dijkstra(int s, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist, dist + n + 1, INF);
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d != dist[u]) continue;
        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

bool check(long long T) {
    vector<long long> production;
    for (int i = 1; i <= s; i++) {
        if (dist[v[i]] != INF)
            production.push_back(max((T - 2 * dist[v[i]] - h[i]) / t[i], 0LL));
    }
    auto pos = production.begin();
    if (k <= production.size()) {
        pos = production.begin() + (int)(production.size() - k);
        nth_element(production.begin(), pos, production.end());
    }
    long long sum = 0;
    while (pos != production.end()) {
        sum += *pos;
        if (sum >= V)
            return true;
        pos++;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cin >> s;
    v.resize(s + 1);
    h.resize(s + 1);
    t.resize(s + 1);
    for (int i = 1; i <= s; i++) {
        cin >> v[i] >> h[i] >> t[i];
    }
    cin >> V;

    dijkstra(1, n);

    long long l = 0, r = 1e18, kq = -1;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check(mid)) {
            kq = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << kq;
    return 0;
}

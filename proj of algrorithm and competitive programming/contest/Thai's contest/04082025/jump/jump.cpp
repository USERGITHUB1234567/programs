#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using PairLL = pair<ll, ll>;
using PairPLL = pair<PairLL, ll>;
static const ll MAXN = 1003;
static const ll INF  = (ll)1e18;
ll n, m, q;
ll d[MAXN][MAXN];
vector<ll> adj[MAXN];
void floyd_warshall() {
    for (ll k = 1; k <= n; ++k) {
        for (ll i = 1; i <= n; ++i) {
            for (ll j = 1; j <= n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
void solve_sub1() {
    floyd_warshall();
    ll current = 1, answer = 0;
    while (q--) {
        ll u, v;
        cin >> u >> v;
        if (current == u || binary_search(adj[current].begin(), adj[current].end(), u)) {
            current = u;
            answer += d[u][v];
        }
    }
    cout << answer;
}
int main() {
    freopen("jump.inp", "r", stdin);
    freopen("jump.out", "w", stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);cin >> n >> m >> q;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            d[i][j] = (i == j ? 0 : INF);
        }
    }
    for (ll i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        d[u][v] = w;
        d[v][u] = w;
    }
    for (ll i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }
    solve_sub1();
    return 0;
}

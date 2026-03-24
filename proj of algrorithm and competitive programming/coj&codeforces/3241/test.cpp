#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 500005;

int n, m;
int p[MAXN];        // parent of node i (i = 2..n)
int owner[MAXN];    // owner[factory] = entrepreneur index (1..m)
int q;
int depthArr[MAXN], timerArr, tin[MAXN], tout[MAXN];
ll target[MAXN];    // target per entrepreneur (1..m)

struct Query { int f, x, d; };
Query queries[MAXN];

vector<int> adj[MAXN];   // tree adjacency parent -> child
vector<int> fac[MAXN];   // fac[entrepreneur] = list of factories owned by him

void dfs(int u) {
    tin[u] = ++timerArr;
    for (int v : adj[u]) {
        depthArr[v] = depthArr[u] + 1;
        dfs(v);
    }
    tout[u] = timerArr;
}

struct Fenwick {
    vector<ll> bit;
    int n;
    Fenwick(int _n = 0) : n(_n), bit(_n + 1, 0) {}
    void add(int idx, ll val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }
    ll sum(int idx) {
        if (idx > n) idx = n;
        ll res = 0;
        while (idx > 0) {
            res += bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }
    // add v to range [l..r]
    void range_add(int l, int r, ll v) {
        if (l < 1) l = 1;
        if (l <= n) add(l, v);
        if (r + 1 <= n) add(r + 1, -v);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> m)) return 0;

    // read tree parents and build adjacency parent -> child
    for (int i = 2; i <= n; ++i) {
        cin >> p[i];
        adj[p[i]].push_back(i);
    }

    // read owner of each factory (factories are 1..n)
    for (int i = 1; i <= n; ++i) {
        cin >> owner[i];
        if (owner[i] >= 1 && owner[i] <= m) fac[owner[i]].push_back(i);
    }

    // read target for each entrepreneur (1..m)
    for (int i = 1; i <= m; ++i) cin >> target[i];

    cin >> q;
    for (int i = 1; i <= q; ++i) cin >> queries[i].f >> queries[i].x >> queries[i].d;

    // binary search per entrepreneur (1..m)
    vector<int> L(m + 1, 1), R(m + 1, q + 1);

    // prepare tin/tout and depth
    timerArr = 0;
    depthArr[1] = 0;
    dfs(1);

    while (true) {
        bool done = true;
        vector<vector<int>> bucket(q + 2);
        for (int e = 1; e <= m; ++e) {
            if (L[e] < R[e]) {
                done = false;
                int mid = (L[e] + R[e]) >> 1;
                bucket[mid].push_back(e);
            }
        }
        if (done) break;

        Fenwick fenA(n), fenB(n); // fenA stores base, fenB stores slope (d)

        for (int year = 1; year <= q; ++year) {
            auto Q = queries[year];
            int f = Q.f;
            int x = Q.x;
            int d = Q.d;
            // add (x - depth[f]*d) to subtree f as base, and add d as slope
            fenA.range_add(tin[f], tout[f], (ll)x - (ll)depthArr[f] * d);
            fenB.range_add(tin[f], tout[f], d);

            for (int ent : bucket[year]) {
                ll total = 0;
                // sum over all factories owned by entrepreneur ent
                for (int factory : fac[ent]) {
                    ll val = fenA.sum(tin[factory]) + fenB.sum(tin[factory]) * depthArr[factory];
                    total += val;
                    if (total >= target[ent]) break;
                }
                if (total >= target[ent]) R[ent] = year;
                else L[ent] = year + 1;
            }
        }
    }

    for (int e = 1; e <= m; ++e) {
        if (L[e] == q + 1) cout << "rekt\n";
        else cout << L[e] << '\n';
    }

    return 0;
}

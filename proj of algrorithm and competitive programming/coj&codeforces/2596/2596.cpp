#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300000 + 5;
int n, m;
int timer;
int disc[MAXN], low[MAXN];
bool isBridge[MAXN];
int comp[MAXN];
bool ck[MAXN];
struct Edge { int u, v, z; };
Edge E[MAXN];
vector<pair<int,int> > adj[MAXN];
vector<pair<int,int> > tree[MAXN];
void dfs_br(int u, int pe) {
    disc[u] = low[u] = ++timer;
    for (auto &ed : adj[u]) {
        int v = ed.first, id = ed.second;
        if (id == pe) continue;
        if (!disc[v]) {
            dfs_br(v, id);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u]) 
                isBridge[id] = true;
        } else {
            low[u] = min(low[u], disc[v]);
        }
    }
}
void dfs_cc(int u, int cid) {
    comp[u] = cid;
    for (auto &ed : adj[u]) {
        int v = ed.first, id = ed.second;
        if (comp[v] == 0 && !isBridge[id])
            dfs_cc(v, cid);
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, z;
        cin >> u >> v >> z;
        E[i] = {u, v, z};
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }
    int A, B;
    cin >> A >> B;
    for (int i = 1; i <= n; i++) {
        if (!disc[i]) dfs_br(i, 0);
    }
    int C = 0;
    for (int i = 1; i <= n; i++) {
        if (comp[i] == 0) {
            ++C;
            dfs_cc(i, C);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (!isBridge[i] && E[i].z == 1) {
            int c = comp[E[i].u];
            ck[c] = true;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (isBridge[i]) {
            int cu = comp[E[i].u];
            int cv = comp[E[i].v];
            int z  = E[i].z;
            tree[cu].emplace_back(cv, z);
            tree[cv].emplace_back(cu, z);
        }
    }

    int ca = comp[A];
    int cb = comp[B];
    vector<int> parent(C+1, -1), pz(C+1, 0);
    vector<char> vis(C+1, 0);
    queue<int> q;
    q.push(ca);
    vis[ca] = 1;
    parent[ca] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto &ed : tree[u]) {
            int v = ed.first, z = ed.second;
            if (!vis[v]) {
                vis[v] = 1;
                parent[v] = u;
                pz[v] = z;
                q.push(v);
            }
        }
    }
    bool ok = false;
    int cur = cb;
    while (cur != 0) {
        if (ck[cur]) ok = true;
        if (cur == ca) break;
        if (pz[cur] == 1) ok = true;
        cur = parent[cur];
    }
    cout << (ok ? "YES\n" : "NO\n");
    return 0;
}

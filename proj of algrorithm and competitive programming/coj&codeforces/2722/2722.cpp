#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
int n, m;
int timer = 0;
int num[MAXN], low[MAXN], comp[MAXN],dbr=0;
bool vis[MAXN], isBridge[MAXN];
pair<int,int> edges[MAXN];
vector<pair<int,int>> adj[MAXN];
vector<int> tree[MAXN];
void dfs_bridge(int u, int pe) {
    vis[u] = true;
    num[u] = low[u] = ++timer;
    for (auto &e : adj[u]) {
        int v = e.first, idx = e.second;
        if (idx == pe) 
            continue;
        if (vis[v]) {
            low[u] = min(low[u], num[v]);
        } else {
            dfs_bridge(v, idx);
            low[u] = min(low[u], low[v]);
            if (low[v] > num[u])
                isBridge[idx] = true;
        }
    }
}
void dfs_comp(int u, int cid) {
    comp[u] = cid;
    for (auto &e : adj[u]) {
        int v = e.first, idx = e.second;
        if (!comp[v] && !isBridge[idx]) {
            dfs_comp(v, cid);
        }
    }
}
pair<int,int> bfs(int start, int C) {
    vector<int> dist(C+1, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    pair<int,int> far = {0, start};
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : tree[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
                if (dist[v] > far.first) {
                    far = {dist[v], v};
                }
            }
        }
    }
    return far;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    for(int i = 1; i <= n; i++){
        if (!vis[i]) 
            dfs_bridge(i, 0);
    }
    int C = 0;
    for(int i = 1; i <= n; i++){
        if (!comp[i]) {
            ++C;
            dfs_comp(i, C);
        }
    }
    for(int i = 1; i <= m; i++){
        if (isBridge[i]) {
            int u = comp[edges[i].first];
            int v = comp[edges[i].second];
            tree[u].push_back(v);
            tree[v].push_back(u);
            dbr++;
        }
    }
    if (C == 1) {
        cout << 0 << "\n";
        return 0;
    }
    auto p1 = bfs(1, C);
    auto p2 = bfs(p1.second, C);
    cout << dbr-p2.first;
    return 0;
}
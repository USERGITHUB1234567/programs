#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    unordered_map<long long, long long> dirCost;
    const long long factor = 100001LL;
    long long totalCost = 0;
    for (int i = 0; i < n; i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        totalCost += w;
        long long key = (long long) u * factor + v;
        dirCost[key] = w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> cycle;
    cycle.push_back(1);
    int next = adj[1][0];
    cycle.push_back(next);
    int prev = 1;
    int cur = next;
    while (true) {
        int nxt = (adj[cur][0] == prev ? adj[cur][1] : adj[cur][0]);
        if(nxt == 1) break;
        cycle.push_back(nxt);
        prev = cur;
        cur = nxt;
    }
    long long cost_order = 0;
    int m = cycle.size();
    for (int i = 0; i < m; i++){
        int u = cycle[i];
        int v = cycle[(i+1) % m];
        long long key = (long long) u * factor + v;
        if(dirCost.find(key) == dirCost.end()){
            long long key2 = (long long) v * factor + u;
            cost_order += dirCost[key2];
        }
    }
    long long ans = min(cost_order, totalCost - cost_order);
    cout << ans;
    return 0;
}

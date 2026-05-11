#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,k,logn,d[200005],p[200005][17],w[200005],mx[200005][17];
vector<int>adj[200005];
void dfs(int u, int f) {
    for (auto [v, w] : adj[u]) {
        if (v != f) {
            d[v] = d[u] + 1;
            p[v][0] = u;
            mx[v][0] = w;
            dfs(v, u);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(logn=1; (1<<logn)<=n; logn++)
    logn--;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=logn; j++) {
            p[i][j]==0;
            mx[i][j]=0;
        }
    }
    for(int i=1; i<=n; i++) cin >> w[i];
    for(int i=1; i<n; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> k;

}

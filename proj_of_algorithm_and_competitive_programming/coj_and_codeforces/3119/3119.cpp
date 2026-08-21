#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=100005,maxm=200005;
int n,m,cnt=0;
int num[maxn],low[maxn],par[maxn];
vector<int> adj[maxn];
pair<int,int> edge[maxm];
void dfs(int u) {
    num[u]=low[u]=++cnt;
    for (auto v:adj[u]) {
        if (!par[v]) {
            par[v]=u;
            cout << u << " " << v << "\n";
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(low[v]==num[v]) {
                cout << v << " " << u << "\n";
            }
        } else {
            if (v != par[u]) {
                low[u] = min(low[u], num[v]);
                if(num[v] < num[u]) {
                    cout << u << " " << v << "\n";
                }
            }
            
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    par[1]=-1;
    dfs(1);
    return 0;
}
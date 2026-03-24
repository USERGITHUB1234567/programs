#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=100005,maxm=200005;
int n,m,cnt=0,kq=0;
int num[maxn],low[maxn],par[maxn];
vector<int> adj[maxn];
vector<pair<int,int>> ans;
pair<int,int> edge[maxm];
void dfs(int u) {
    num[u]=low[u]=++cnt;
    for (auto v:adj[u]) {
        if (!par[v]) {
            par[v]=u;
            //cout << u << " " << v << "\n";
            ans.push_back({u,v});
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(low[v]==num[v]) {
                //cout << v << " " << u << "\n";
                kq++;
            }
        } else {
            if (v != par[u]) {
                low[u] = min(low[u], num[v]);
                if(num[v] < num[u]) {
                    //cout << u << " " << v << "\n";
                    ans.push_back({u,v});
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
    for(int i=1; i<=n; i++) {
        if (!par[i]) {
            par[i]=-1;
            kq++;
            dfs(i);
        }
    }
    cout << kq << "\n";
    for (auto p:ans) {
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}
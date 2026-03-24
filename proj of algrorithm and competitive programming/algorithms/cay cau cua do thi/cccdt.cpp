#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
const int maxn=100005;
int n,m,cnt=0,num[maxn],low[maxn],dcomp,comp[maxn];
vector<pair<int,int> >adj[maxn];
pair<int,int>edge[maxn];
bool vis[maxn],bridge[maxn];
vector<int>bridgetree[maxn];
void dfs(int u, int p) {
    vis[u]=true;
    num[u]=low[u]=++cnt;
    //cout << u << ' ' << num[u] << ' ' << low[u] << '\n';
    for(auto[v,i]:adj[u]) {
        if(v==p) continue;
        if(vis[v]) low[u]=min(low[u],num[v]);
        else {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            //if(low[u]==0) cout << u << ' ';
            if(low[u]==num[u]) bridge[i]=true;
        }
    }
    vis[u]=true;
    //cout << u << ' ' << num[u] << ' ' << low[u] << '\n';
}
void dfs1(int u) {
    comp[u]=dcomp;
    for(auto[v,i]:adj[u]) {
        if(comp[v]==0 && !bridge[i]) dfs1(v);
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        cin >> edge[i].first >> edge[i].second;
        adj[edge[i].first].emplace_back(edge[i].second,i);
        adj[edge[i].second].emplace_back(edge[i].first,i);
    }
    for(int i=1; i<=n; i++) {
        if(!vis[i]) dfs(i,0);
    }
    for(int i=1; i<=n; i++) {
        if(comp[i]==0) {
            dcomp++;
            dfs1(i);
 
       }
    }
    for(int i=1; i<=m; i++) {
        if(bridge[i]) {
            int u=comp[edge[i].first],v=comp[edge[i].second];
            bridgetree[u].push_back(v);
            bridgetree[v].push_back(u);
        }
    }
    //for(int i=1; i<=m; ++i) cout << bridge[i] << ' ';
    cout << dcomp;
}
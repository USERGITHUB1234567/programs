#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,m,id[maxn],coin[maxn],scc;
vector<int>adj[maxn],rev[maxn],dag[maxn],order;
long long f[maxn],total[maxn];
bool vis[maxn];
void dfs1(int u) {
    vis[u]=true;
    for(int v:adj[u]) {
        if(!vis[v]) dfs1(v);
    }
    order.push_back(u);
}
void dfs2(int u) {
    vis[u]=true;
    id[u]=scc;
    total[scc]+=coin[u];
    for(int v:rev[u]) {
        if(!vis[v]) dfs2(v);
    }
}
long long query(int u) {
    if(f[u]) return f[u];
    long long mx=0;
    for(int v:dag[u]) {
        mx=max(mx,query(v));
    }
    return f[u]=mx+total[u];
}
int main(int argc, char** argv) {
    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> coin[i];
    for(int i=1; i<=m; ++i) {
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }
    for(int i=1; i<=n; ++i) {
        if(!vis[i]) dfs1(i);
    }
    reverse(order.begin(),order.end());
    for(int i=1; i<=n; ++i) vis[i]=false;
    for(int i:order) {
        if(!vis[i]) {
            ++scc;
            dfs2(i);
        }
    }
    for(int i=1; i<=n; ++i) {
        for(int j:adj[i]) {
            if(id[j]!=id[i]) dag[id[i]].push_back(id[j]);
        }
    }
    long long ans=0;
    for(int i=1; i<=scc; ++i) ans=max(ans,query(i));
    cout << ans;
}
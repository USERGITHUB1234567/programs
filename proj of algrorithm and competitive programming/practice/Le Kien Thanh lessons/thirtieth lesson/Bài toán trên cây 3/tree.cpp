#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,m,q,comp[maxn],num[maxn],low[maxn],timer,ncomp,tin[maxn],tout[maxn],up[maxn][20],d[maxn],logn;
vector<pair<int,int>>adj[maxn];
pair<int,int>edge[maxn];
vector<int>g[maxn];
bool bridge[maxn];
void dfs(int u, int p) {
    low[u]=num[u]=++timer;
    for(auto[v,i]:adj[u]) {
        if(v==p) continue;
        if(!num[v]) {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>num[u]) bridge[i]=true; 
        }
        else low[u]=min(low[u],num[v]);
    }
}
void labeling(int u) {
    comp[u]=ncomp;
    for(auto[v,i]:adj[u]) {
        if(!comp[v] && !bridge[i]) labeling(v);
    }
}
void dfs2(int u, int p) {
    tin[u]=++timer;
    for(int v:g[u]) {
        if(v!=p) {
            d[v]=d[u]+1;
            up[v][0]=u;
            dfs2(v,u);
        }
    }
    tout[u]=timer;
}
int lca(int u, int v) {
    if(d[u]<d[v]) swap(u,v);
    int len=d[u]-d[v];
    for(len; len; len&=(len-1)) {
        int i=__builtin_ctz(len);
        u=up[u][i];
    }
    if(u==v) return u;
    for(int i=logn; i>=0; --i) {
        if(up[u][i]!=up[v][i]) u=up[u][i],v=up[v][i];
    }
    return up[u][0];
}
int intersect(int u, int lu, int v, int lv) {
    int l=lca(u,v);
    if(d[l]<max(d[lu],d[lv])) return 0;
    return d[l]-max(d[lv],d[lu]);
}
int overlap(int x, int y, int u, int v) {
    int l1=lca(x,y),l2=lca(u,v);
    return intersect(x,l1,u,l2)+intersect(x,l1,v,l2)+intersect(y,l1,u,l2)+intersect(y,l1,v,l2);
}
int main(int argc, char** argv) {
    freopen("bridge.inp", "r", stdin);
    freopen("bridge.out", "w", stdout);
    cin >> n >> m >> q;
    for(int i=1,u,v; i<=m; ++i) {
        cin >> u >> v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
        edge[i]={u,v};
    }
    dfs(1,0);
    for(int i=1; i<=n; ++i) {
        if(!comp[i]) {
            ++ncomp;
            labeling(i);
        }
    }
    for(int i=1; i<=m; ++i) {
        if(bridge[i]) {
            auto[u,v]=edge[i];
            u=comp[u],v=comp[v];
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    dfs2(1,0);
    timer=0;
    logn=32-__builtin_clz(ncomp);
    for(int j=1; j<=logn; ++j) {
        for(int i=1; i<=ncomp; ++i) up[i][j]=up[up[i][j-1]][j-1];
    }
    while(q--) {
        int x,y,u,v;cin >> x >> y >> u >> v;
        x=comp[x],y=comp[y],u=comp[u],v=comp[v];
        int dist=d[u]+d[v]-(d[lca(u,v)]<<1);
        cout << dist-overlap(x,y,u,v) << '\n';
    }
}
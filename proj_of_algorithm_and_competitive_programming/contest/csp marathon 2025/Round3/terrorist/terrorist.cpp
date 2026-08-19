#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define fi first
#define se second
#define int long long
using namespace std;
const int maxn=200005,maxl=20;
int n,m,q,num[maxn],low[maxn],timer=0,comp[maxn],ncomp=0,cntc[maxn],p[maxn][maxl],d[maxn],path[maxn],logn;
vector<pair<int,int>>adj[maxn];
bool bridge[maxn];
pair<int,int>edge[maxn];
vector<int>tree[maxn];
void dfs(int u, int p) {
    num[u]=low[u]=++timer;
    for(auto[v,i]:adj[u]) {
        if(v==p) continue;
        if(num[v]) low[u]=min(low[u],num[v]);
        else {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>num[u]) bridge[i]=true;
        }
    }
}
void dfs1(int u) {
    comp[u]=ncomp;
    for(auto[v,i]:adj[u]) {
        if(!bridge[i] && !comp[v]) dfs1(v);
    }
}
void dfslca(int u, int pr) {
    d[u]=(u==pr?0:d[pr]+1);
    p[u][0]=pr;
    path[u]=(u==pr?cntc[u]:path[pr]+cntc[u]);
    for(int v:tree[u]) {
        if(v!=pr) dfslca(v,u);
    }
}
int lca(int u, int v) {
    if(d[u]<d[v]) swap(u,v);
    for(int i=logn; i>=0; i--) {
        if(d[p[u][i]]>=d[v]) u=p[u][i];
    }
    if(u==v) return u;
    for(int i=logn; i>=0; i--) {
        if(p[u][i]!=p[v][i]) {
            u=p[u][i];
            v=p[v][i];
        }
    }
    return p[u][0];
}
int dist(int u, int v) {
    return d[u]+d[v]-2*d[lca(u,v)];
}
void solve() {
    cin >> q;
    while(q--) {
        int x,y;
        cin >> x >> y;
        if(comp[x]==comp[y]) {
            cout << 0 << " " << cntc[comp[x]] << "\n"; 
            continue;
        }
        int u=comp[x], v=comp[y];
        int d=dist(u,v);
        int l=lca(u,v);
        int ans=path[u]+path[v]-2*path[l]+d+cntc[l];
        cout << d << " " << ans << "\n";
    }
}
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("terrorist");
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        cin >> edge[i].fi >> edge[i].se;
        adj[edge[i].fi].push_back({edge[i].se,i});
        adj[edge[i].se].push_back({edge[i].fi,i});
    }
    dfs(1,0);
    for(int i=1; i<=n; i++) {
        if(!comp[i]) {
            ncomp++;
            dfs1(i);
        }
    }
    for(int i=1; i<=m; i++) {
        if(bridge[i]) {
            int u=comp[edge[i].fi], v=comp[edge[i].se];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        else {
            cntc[comp[edge[i].fi]]++;
        }
    }
    dfslca(1,1);
    for(logn=1; (1<<logn)<=n; logn++);
    logn--;
    for(int j=1; j<=logn; j++) {
        for(int i=1; i<=n; i++) p[i][j]=p[p[i][j-1]][j-1];
    }
    solve();
}
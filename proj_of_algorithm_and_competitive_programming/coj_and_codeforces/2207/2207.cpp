#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;
const int maxn=100005,maxm=200005;
int n,m,p[maxn][20],pr[maxn],d[maxn],logn,mx[maxn][20],t=0,kq=LLONG_MAX;
bool mk[maxn];
vector<pair<int,int>>adj[maxn];
struct edge
{
    int u,v,w,id;
}e[maxm];
int findset(int u)
{
    if(pr[u]==0) return u;
    return pr[u]=findset(pr[u]);
}
bool unite(int u, int v)
{
    u=findset(u);
    v=findset(v);
    if(u==v) return false;
    pr[u]=v;
    return true;
}
void dfs(int u, int pa)
{
    p[u][0]=pa;
    d[u]=(u==pa?1:d[pa]+1);
    for(auto [v,w]:adj[u]) {
        if(v==pa) continue;
        mx[v][0]=w;
        dfs(v,u);
    }
}
pair<int,int>lca(int u, int v)
{
    int re=0;
    if(d[u]<d[v]) swap(u,v);
    for(int j=logn; j>=0; j--) {
        if(d[p[u][j]]>=d[v]) {
            re=max(re,mx[u][j]);
            u=p[u][j];
        }
    }
    if(u==v) return {u,re};
    for(int j=logn; j>=0; j--) {
        if(p[u][j]!=p[v][j]) {
            re=max({re,mx[u][j],mx[v][j]});
            u=p[u][j];
            v=p[v][j];
        }
    }
    re=max({re,mx[u][0],mx[v][0]});
    return {p[u][0],re};
}
bool cmp(edge a, edge b)
{
    return a.w<b.w;
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for(logn=1; (1<<logn)<=n; logn++);
    logn--;
    for(int i=1; i<=m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        e[i].u=u;e[i].v=v;e[i].w=w;e[i].id=i;
        //adj[u].push_back({v,w});
        //adj[v].push_back({u,w});
    }
    sort(e+1,e+1+m,cmp);
    for(int i=1; i<=m; i++) {
        int u=e[i].u,v=e[i].v,w=e[i].w,id=e[i].id;
        if(unite(u,v)) {
            adj[v].push_back({u,w});
            adj[u].push_back({v,w});
            mk[id]=true;
            t+=w;
        }
    }
    dfs(1,1);
    for(int j=1; j<=logn; j++) {
        for(int i=1; i<=n; i++) {
            p[i][j]=p[p[i][j-1]][j-1];
            mx[i][j]=max(mx[i][j-1],mx[p[i][j-1]][j-1]);
        }
    }
    for(int i=1; i<=m; i++) {
        int u=e[i].u,v=e[i].v,w=e[i].w,id=e[i].id;
        if(!mk[id]) {
            auto re=lca(u,v);
            int cnd=t-re.second+w;
            if(cnd>t) kq=min(kq,cnd);
        }
    }
    cout << kq;
}

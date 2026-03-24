#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
const int maxn=200005,maxl=20;
int n,q,st[maxn],en[maxn],timer=0,p[maxn][maxl],d[maxn],logn;
long long ft[maxn+10];
vector<pair<int,int>>adj[maxn];
struct edge {
    int u,v,w;
}e[maxn];
long long sum(int i) {
    long long s=0;
    while(i>0) {
        s+=ft[i];
        i-=i&-i;
    }
    return s;
}
void upd(int i, long long v) {
    while(i<=n) {
        ft[i]+=v;
        i+=i&-i;
    }
}
void dfs(int u, int pr) {
    st[u]=++timer;
    d[u]=(u==pr?0:d[pr]+1);
    p[u][0]=pr;
    for(auto[v,w]:adj[u]) {
        if(v==pr) continue;
        dfs(v,u);
    }
    en[u]=timer;
}
int lca(int u, int v) {
    if(d[u]<d[v]) swap(u,v);
    for(int i=logn; i>=0; i--) {
        if(d[p[u][i]]>=d[v]) u=p[u][i];
    }
    if(v==u) return u;
    for(int i=logn; i>=0; i--) {
        if(p[u][i]!=p[v][i]) {
            u=p[u][i];
            v=p[v][i];
        }
    }
    return p[u][0];
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=1; i<n; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        e[i].u=u;e[i].v=v;e[i].w=w;
    }
    dfs(1,1);
    for(logn=1; (1<<logn)<=n; logn++);
    logn--;
    for(int j=1; j<=logn; j++) {
        for(int i=1; i<=n; i++) {
            p[i][j]=p[p[i][j-1]][j-1];
        }
    } 
    for(int i=1; i<n; i++) {
        int u=e[i].u,v=e[i].v;
        if (d[u]<d[v]) swap(u, v);
        long long w=e[i].w;
        upd(st[u],w);
        upd(en[u]+1,-w);
    }
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        if(t==1) {
            int i,w;
            cin >> i >> w;
            auto[u,v,x]=e[i];
            if(d[u]<d[v]) swap(u,v);
            upd(st[u],w-x);
            upd(en[u]+1,-(w-x));
            e[i].w=w;
        }
        else {
            int u,v;
            cin >> u >> v;
            cout << sum(st[u])+sum(st[v])-2*sum(st[lca(u,v)]) << "\n";
        }
    }
}
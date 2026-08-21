#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
const int maxn=100005;
int n,par[maxn],d[maxn],heavy[maxn],head[maxn],pos[maxn],a[maxn],e[maxn],cur=0;
vector<pair<int,int>>adj[maxn];
struct edge {
    int u,v,id;
}ed[maxn];
struct segtree {
    int st[4*maxn];
    void build(int id, int l, int r) {
        if(l==r) {
            st[id]=e[l];
            return;
        }
        int mid=(l+r)>>1;
        build(2*id,l,mid);
        build(2*id+1,mid+1,r);
        st[id]=max(st[2*id],st[2*id+1]);
    }
    void upd(int id, int l, int r, int i, int v) {
        if(l==r) {
            st[id]=v;
            e[l]=v;
            return;
        }
        int mid=(l+r)>>1;
        if(i<=mid) upd(2*id,l,mid,i,v);
        else upd(2*id+1,mid+1,r,i,v);
        st[id]=max(st[2*id],st[2*id+1]);
    }
    int query(int id, int l, int r, int u, int v) {
        if(r<u || l>v) return 0;
        if(l>=u && r<=v) return st[id];
        int mid=(l+r)>>1;
        return max(query(2*id,l,mid,u,v),query(2*id+1,mid+1,r,u,v));
    }
}seg;
int dfs(int u) {
    int sz=1,szm=0;
    for(auto[v,w]:adj[u]) {
        if(v==par[u]) continue;
        par[v]=u;
        d[v]=d[u]+1;
        int csz=dfs(v);
        sz+=csz;
        a[v]=w;
        if(csz>szm) {
            szm=csz;
            heavy[u]=v;
        }
    }
    return sz;
}
void decompose(int u, int h) {
    head[u]=h;
    pos[u]=++cur;
    e[cur]=a[u];
    if(heavy[u]) decompose(heavy[u],h);
    for(auto[v,w]:adj[u]) {
        if(v!=par[u] && v!=heavy[u]) decompose(v,v);
    }
}
int hldquery(int a, int b) {
    int res=0;
    for(;head[a]!=head[b];b=par[head[b]]) {
        if(d[head[a]]>d[head[b]]) swap(a,b);
        res=max(res,seg.query(1,1,n,pos[head[b]],pos[b]));
    }
    if(d[a]<d[b]) swap(a,b);
    res=max(res,seg.query(1,1,n,pos[b]+1,pos[a]));
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    //file("1695")
    for(int i=1; i<n; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        ed[i]={u,v,w};
    }
    dfs(1);
    decompose(1,1);
    seg.build(1,1,n);
    string s;
    while(cin >> s) {
        if(s=="CHANGE") {
            int i,t;
            cin >> i >> t;
            auto[u,v,w]=ed[i];
            if(d[u]>d[v]) swap(u,v);
            seg.upd(1,1,n,pos[v],t);
        }
        else if(s=="QUERY") {
            int u,v;
            cin >> u >> v;
            cout << hldquery(u,v) << "\n";
        }
        else if(s=="DONE") break;
    }
}
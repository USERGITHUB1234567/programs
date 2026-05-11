#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define int long long
using namespace std;
const int maxn=100005;
int n,q,par[maxn],d[maxn],heavy[maxn],cur=0,head[maxn],pos[maxn],e[maxn],a[maxn];
vector<int>adj[maxn];
struct segtree {
    int st[4*maxn];
    void build(int id, int l, int r) {
        if(l==r) {
            st[id]=a[l];
            return;
        }
        int mid=(l+r)>>1;
        build(2*id,l,mid);
        build(2*id+1,mid+1,r);
        st[id]=st[2*id]^st[2*id+1];
    }
    void upd(int id, int l, int r, int i, int v) {
        if(l==r) {
            st[id]=v;
            a[l]=v;
            return;
        }
        int mid=(l+r)>>1;
        if(i<=mid) upd(2*id,l,mid,i,v);
        else upd(2*id+1,mid+1,r,i,v);
        st[id]=st[2*id]^st[2*id+1];
    }
    int query(int id, int l, int r, int u, int v) {
        if(l>v || r<u) return 0;
        if(u<=l && r<=v) return st[id];
        int mid=(l+r)>>1;
        return query(2*id,l,mid,u,v)^query(2*id+1,mid+1,r,u,v);
    }
}seg;
int dfs(int u) {
    int sz=1,szmax=0;
    for(int v:adj[u]) {
        if(v==par[u]) continue;
        par[v]=u;
        d[v]=d[u]+1;
        int szchild=dfs(v);
        sz+=szchild;
        if(szchild>szmax) {
            szmax=szchild;
            heavy[u]=v;
        }
    }
    return sz;
}
void decompose(int u, int h) {
    head[u]=h;
    pos[u]=++cur;
    a[cur]=e[u];
    if(heavy[u]!=0) {
        decompose(heavy[u],h);
    }
    for(int v:adj[u]) if(v!=par[u] && v!=heavy[u]) decompose(v,v);
}
int hldquery(int a, int b) {
    int res=0;
    for(;head[a]!=head[b];b=par[head[b]]) {
        if(d[head[a]]>d[head[b]]) swap(a,b);
        res^=seg.query(1,1,n,pos[head[b]],pos[b]);
    }
    if(d[a]>d[b]) swap(a,b);
    res^=seg.query(1,1,n,pos[a],pos[b]);
    return res;
}
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    //file("2625");
    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> e[i];
    for(int i=1; i<n; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    decompose(1,1);
    seg.build(1,1,n);
    while(q--) {
        int t;
        cin >> t;
        if(t==1) {
            int i,v;
            cin >> i >> v;
            seg.upd(1,1,n,pos[i],v);
        }
        else {
            int i,j;
            cin >> i >> j;
            cout << hldquery(i,j) << "\n";
        }
    }
}
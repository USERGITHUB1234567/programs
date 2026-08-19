#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
const int maxn=100005;
int n,p[maxn],heavy[maxn],d[maxn],head[maxn],pos[maxn],a[maxn],cur=0;
vector<int>adj[maxn];
struct segtree {
    int st[4*maxn];
    void build(int id, int l, int r) {
        if(l==r) {
            st[id]=a[l];
            return;
        }
        int m=(l+r)>>1;
        build(id<<1,l,m);
        build(id<<1|1,m+1,r);
        st[id]=st[id<<1]^st[id<<1|1];
    }
    void upd(int id, int l, int r, int i, int v) {
        if(l==r) {
            st[id]=v;
            return;
        }
        int m=(l+r)>>1;
        if(i<=m) upd(id<<1,l,m,i,v);
        else upd(id<<1|1,m+1,r,i,v);
        st[id]=st[id<<1]^st[id<<1|1];
    }
    int query(int id, int l, int r, int u, int v) {
        if(l>v || r<u) return 0;
        if(l>=u && r<=v) return st[id];
        int m=(l+r)>>1;
        return query(id<<1,l,m,u,v)^query(id<<1|1,m+1,r,u,v);
    }
}seg;
int dfs(int u) {
    int sz=1,szm=0;
    for(int v:adj[u]) {
        if(v==p[u]) continue;
        p[v]=u;
        d[v]=d[u]+1;
        int csz=dfs(v);
        sz+=csz;
        if(csz>szm) {
            szm=csz;heavy[u]=v;
        }
    }
    return sz;
}
void decompose(int u, int h) {
    head[u]=h;
    pos[u]=++cur;
    if(heavy[u]) decompose(heavy[u],h);
    for(int v:adj[u]) {
        if(v!=heavy[u] && v!=p[u]) decompose(v,v);
    }
}
int hldquery(int a, int b) {
    int res=0;
    for(;head[a]!=head[b]; b=p[head[b]]) {
        if(d[head[a]]>d[head[b]]) swap(a,b);
        res^=seg.query(1,1,n,pos[head[b]],pos[b]);
    }
    if(d[a]>d[b]) swap(a,b);
    res^=seg.query(1,1,n,pos[a],pos[b]);
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1);
    decompose(1, 1);
    seg.build(1, 1, n);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) { // Update
            int i, v;
            cin >> i >> v;
            seg.upd(1, 1, n, pos[i], v);
        } else if (type == 2) { // Query
            int u, v;
            cin >> u >> v;
            cout << hldquery(u, v) << '\n';
        }
    }

    return 0;
}
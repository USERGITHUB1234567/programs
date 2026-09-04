#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,q;
long long a[maxn];
array<int,4>query[maxn];
vector<int>adj[maxn];
namespace soup1{
    int p[1003],d[1003];
    long long b[1003];
    void dfs_init(int u) {
        for(int v:adj[u]) {
            if(v!=p[u]) {
                p[v]=u;
                d[v]=d[u]+1;
                dfs_init(v);
            }
        }
    }
    void init(int s) {
        for(int i=1; i<=n; ++i) {p[i]=0;d[i]=0;}
        dfs_init(s);
    }
    int lca(int u, int v) {
        if(d[u]<d[v]) swap(u,v);
        while(d[u]>d[v]) u=p[u];
        while(u!=v) {
            u=p[u],v=p[v];
        }
        return u;
    }
    void update(int u, int &x) {
        b[u]+=x;
        //cerr << u << ' ';
        for(int v:adj[u]) {
            if(p[u]!=v) {
                update(v,x);
            }
        }
    }
    void sum(int u, long long &tot) {
        tot+=b[u];
        for(int v:adj[u]) {
            if(p[u]!=v) {
                sum(v,tot);
            }
        }
    }
    void implement() {
        for(int i=1; i<=n; ++i) b[i]=a[i];
        init(1);
        for(int t=1; t<=q; ++t) {
            auto[type,u,v,x]=query[t];
            //cout << type << ' ' << u << ' ' << v << ' ' << x << '\n';
            if(type==1) {
                init(u);
            }else if(type==2) {
                int l=lca(u,v);
                //cout << t << '\n';
                update(l,x);
            }else {
                long long tot=0;
                sum(u,tot);
                cout << tot << '\n';
            }
        }
    }
}
namespace soup2{
    int up[maxn][20],d[maxn],tin[maxn],tout[maxn],rev[maxn],timer=0,logn;
    struct segment_tree{
        long long st[maxn<<2],laz[maxn<<2];
        void build(int id, int l, int r) {
            if(l==r) {
                st[id]=a[rev[l]];
                return;
            }
            int mid=(l+r)>>1;
            build(id<<1,l,mid);
            build(id<<1|1,mid+1,r);
            st[id]=st[id<<1]+st[id<<1|1];
        }
        void push_down(int id, int l, int r) {
            if(laz[id]) {
                int mid=(l+r)>>1;
                long long t=laz[id];
                st[id<<1]+=(mid-l+1)*t;
                st[id<<1|1]+=(r-mid)*t;
                laz[id<<1]+=t;
                laz[id<<1|1]+=t;
                laz[id]=0;
            }
        }
        void update(int id, int l, int r, int i, int j, int v) {
            push_down(id,l,r);
            if(l>j || r<i) return;
            if(l>=i && r<=j) {
                st[id]+=(long long)v*(r-l+1);
                laz[id]+=v;
                return;
            }
            int mid=(l+r)>>1;
            update(id<<1,l,mid,i,j,v);
            update(id<<1|1,mid+1,r,i,j,v);
            st[id]=st[id<<1]+st[id<<1|1];
        }
        long long query(int id, int l, int r, int i, int j) {
            push_down(id,l,r);
            if(l>j || r<i) return 0;
            if(l>=i && r<=j) {return st[id];}
            int mid=(l+r)>>1;
            return query(id<<1,l,mid,i,j)+query(id<<1|1,mid+1,r,i,j);
        }
    };
    segment_tree seg;
    void dfs_init(int u) {
        tin[u]=++timer;
        for(int v:adj[u]) {
            if(v!=up[u][0]) {
                up[v][0]=u;
                d[v]=d[u]+1;
                dfs_init(v);
            }
        }
        tout[u]=timer;
    }
    int lca(int u, int v) {
        if(d[u]<d[v]) swap(u,v);
        int dif=d[u]-d[v];
        for(; dif; dif&=(dif-1)) {
            int i=__builtin_ctz(dif);
            u=up[u][i];
        }
        if(u==v) return u;
        for(int i=logn; i>=0; --i) {
            if(up[u][i]!=up[v][i]) u=up[u][i],v=up[v][i];
        }
        return up[u][0];
    }
    void implement() {
        dfs_init(1);
        for(int i=1; i<=n; ++i) rev[tin[i]]=i;
        seg.build(1,1,n);
        logn=31-__builtin_clz(n);
        for(int j=1; j<=logn; ++j) {
            for(int i=1; i<=n; ++i) up[i][j]=up[up[i][j-1]][j-1];
        }
        for(int t=1; t<=q; ++t) {
            auto[type,u,v,x]=query[t];
            if(type==2) {
                int l=lca(u,v);
                //cout << l << '\n';
                seg.update(1,1,n,tin[l],tout[l],x);
            }
            else if(type==3) {
                cout << seg.query(1,1,n,tin[u],tout[u]) << '\n';
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("dothi.inp", "r", stdin);
    freopen("dothi.out", "w", stdout);
    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1,u,v; i<n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=q; ++i) {
        cin >> query[i][0] >> query[i][1];
        if(query[i][0]==2) cin >> query[i][2] >> query[i][3];
    }
    //soup2::implement();
    //cout << '\n';
    if(n*q<=10000000) soup1::implement();
    else soup2::implement();
    //cout << '\n';
    //soup2::implement();
}
/*
4 6
4 3 5 6
1 2
2 3
3 4
3 1
1 3
2 2 4 3
1 1
2 2 4 -3
3 1

4 6
4 3 5 6
1 2
2 3
3 4
3 1
1 1
2 2 4 3
2 3 4 7
3 2
3 1

*/


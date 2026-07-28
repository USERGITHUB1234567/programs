#pragma GCC optimize("O3","Ofast")
#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,q,a[maxn];
vector<int>adj[maxn];
array<int,3>query[maxn];
namespace soup1{
    int d[maxn],up[maxn];
    void dfs(int u, int p) {
        for(int v:adj[u]) {
            if(v!=p) {
                d[v]=d[u]+1;
                up[v]=u;
                dfs(v,u);
            }
        }
    }
    void update(int u, int v, int w) {
        if(d[u]<d[v]) swap(u,v);
        while(d[u]>d[v]) {
            a[u]=a[u]%w;
            u=up[u];
        }
        while(u!=v) {
            a[u]=a[u]%w;
            a[v]=a[v]%w;
            u=up[u],v=up[v];
        }
        a[u]=a[u]%w;
    }
    void implement() {
        dfs(1,0);
        for(int t=1; t<=q; ++t) {
            auto[x,y,w]=query[t];
            update(x,y,w);
            //if(t==1) {cout << 0 << '\n';continue;}
            long long ans=0;
            for(int i=1; i<=n; ++i) {
                ans+=a[i]%t;
                //cout << a[i] << ' ';
            }
            cout << ans << '\n';
        }
    }
}
struct fenwick_tree{
    vector<int>bit;
    int n;
    fenwick_tree(int _n):n(_n) {bit.resize(n+1);}
    void update(int i, int v) {
        while(i<=n) {
            bit[i]+=v;
            i+=i&-i;
        }
    }
    int sum(int i) {
        int res=0;
        while(i) {
            res+=bit[i];
            i-=i&-i;
        }
        return res;
    }
    int range(int i, int j) {return sum(j)-sum(i-1);}
};
struct segment_tree{
    int n;
    vector<pair<int,int>>st;
    segment_tree(int _n):n(_n){st.resize(n<<2);}
    pair<int,int>mer(pair<int,int>a,pair<int,int>b) {
        if(a.first>b.first) return a;
        else return b;
    }
    void build(int id, int l, int r) {
        if(l==r) {
            st[id]={a[l],l};
            return;
        }
        int mid=(l+r)>>1;
        build(id<<1,l,mid);
        build(id<<1|1,mid+1,r);
        st[id]=mer(st[id<<1],st[id<<1|1]);
    }
    pair<int,int>query(int id, int l, int r, int i, int j) {
        
    }
};
namespace soup2{
    vector<int>store1,store2;
    //fenwick_tree fen(n);
    void remove1(int l, int r) {
        auto it1=lower_bound(store1.begin(),store1.end(),l),it2=upper_bound(store1.begin(),store1.end(),r);
        //if(it1==store1.end() || *it1>r) return;
        //--it2;
        store1.erase(it1,it2);
    }
    void remove2(int l, int r) {
        auto it1=lower_bound(store2.begin(),store2.end(),l),it2=upper_bound(store2.begin(),store2.end(),r);
        //if(it1==store2.end() || *it1>r) return;
        //--it2;
        store2.erase(it1,it2);
    }
    void implement() {
        for(int i=1; i<=n; ++i) {
            if(a[i]==1) store1.push_back(i);
            else if(a[i]==2) store2.push_back(i);
        }
        //cout << store1.size() << ' ' << store2.size() << '\n';
        for(int t=1; t<=q; ++t) {
            auto[x,y,w]=query[t];
            if(y<x) swap(x,y);
            if(w==1) {remove1(x,y);remove2(x,y);}
            else if(w==2) {remove2(x,y);}
            if(t==1) {cout << 0 << '\n';}
            else if(t==2) {cout << store1.size() << '\n';}
            else {cout << store1.size()+2*store2.size() << '\n';}
        }
        // remove2(2,4);
        // cout << store2.size();
    }
}
namespace soup3{
    int cnt[maxn];
    long long sum(int t) {

    }
    void implement() {
        for(int i=1; i<=n; ++i) {
            ++cnt[a[i]];
        }
        for(int t=1; t<=q; ++t) {
            auto[x,y,w]=query[t];
            --cnt[a[x]];
            a[x]%=w;
            ++cnt[a[x]];

        }
    }
}
namespace soupfull{
    int par[maxn],heavy[maxn],pos[maxn],head[maxn],d[maxn],cur;
    int dfs(int u, int p) {
        int szm=0,csz,sz=1;
        for(int v:adj[u]) {
            d[v]=d[u]+1;
            par[v]=u;
            csz=dfs(v,u);
            if(csz>szm) {
                heavy[u]=v;
                szm=csz;
            }
            sz+=csz;
        }
        return sz;
    }
    void decompose(int u, int h) {
        head[u]=h;
        pos[u]=++cur;
        if(heavy[u]) decompose(heavy[u],h);
        for(int v:adj[u]) {
            if(v!=par[v] && v!=heavy[u]) decompose(v,v);
        }
    }

    void implement() {
        
    }
}
int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("3294.inp", "r", stdin);
    freopen("3294.out", "w", stdout);
    cin >> n >> q;
    bool cks2=true;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1,u,v; i<n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if(min(u,v)+1!=max(u,v) || a[i]>2) {cks2=false;}
    }
    for(int i=1; i<=q; ++i) cin >> query[i][0] >> query[i][1] >> query[i][2];
    if(cks2)soup2::implement();
    //cout << '\n';
    else soup1::implement();
    //soup2::implement();
    //cout << '\n';
    //soup1::implement();
}
/*
7 3
1 2 1 2 2 1 1
1 2
2 3
3 4
4 5
5 6
6 7
1 3 3
2 4 2
3 5 1
*/
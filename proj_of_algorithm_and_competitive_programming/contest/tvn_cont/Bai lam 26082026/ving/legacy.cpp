#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,q,s;
array<int,5>bundle[maxn];
namespace soupfull{
    vector<pair<int,int>>adj[maxn<<3];
    int idx1[maxn<<4],idx2[maxn<<4],cur;
    long long d[maxn<<4];
    void add_edge(int u, int v, int w) {
        adj[u].push_back({v,w});
        //cout << u << ' ' << v << ' ' << w << '\n';
    }
    void build(int id, int l, int r) {
        if(l==r) {
            idx1[id]=l;
            idx2[id]=l;
            return;
        }
        int mid=(l+r)>>1;
        idx1[id]=++cur;
        idx2[id]=++cur;
        build(id<<1,l,mid);
        build(id<<1|1,mid+1,r);
        add_edge(idx1[id],idx1[id<<1],0);
        add_edge(idx1[id],idx1[id<<1|1],0);
        add_edge(idx2[id<<1],idx2[id],0);
        add_edge(idx2[id<<1|1],idx2[id],0);
    }
    void update(int id, int l, int r, int u, int i, int j, int w, bool type) {
        //cout << l << ' ' << r << ' ' << i << ' ' << j << ' ' << w << ' ' << type << '\n';
        if(l==i && r==j) {
            if(type) {add_edge(idx2[id],u,w);}
            else add_edge(u,idx1[id],w);
            return;
        }
        int mid=(l+r)>>1;
        if(i<=mid) update(id<<1,l,mid,u,i,min(j,mid),w,type);
        if(j>mid) update(id<<1|1,mid+1,r,u,max(mid+1,i),j,w,type);
    }
    void dijkstra(int s) {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        for(int i=1; i<=(n<<4); ++i) d[i]=1e18;
        d[s]=0;
        pq.push({0,s});
        //cout << s << '\n';
        while(!pq.empty()) {
            auto[cd,u]=pq.top();pq.pop();
            //cout << u << '\n';
            if(cd>d[u]) continue;
            for(auto[v,w]:adj[u]) {
                //cout << v << ' ' << w << ' ' << d[v] << '\n';
                if(d[v]>cd+w) {
                    d[v]=cd+w;
                    pq.push({d[v],v});
                }
            }
        }
    }
    void implement() {
        cur=n;
        build(1,1,n);
        for(int i=1; i<=q; ++i) {
            auto[t,u,l,r,w]=bundle[i];
            if(t==1) add_edge(u,l,r);
            else if(t==2) update(1,1,n,u,l,r,w,false);
            else update(1,1,n,u,l,r,w,true);
            //cout << '\n';
        }
        dijkstra(s);
        for(int i=1; i<=n; ++i) cout << (d[i]==1e18?-1:d[i]) << ' ';
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("legacy.inp", "r", stdin);
    freopen("legacy.out", "w", stdout);
    cin >> n >> q >> s;
    for(int i=1; i<=q; ++i) {
        cin >> bundle[i][0] >> bundle[i][1] >> bundle[i][2] >> bundle[i][3];
        if(bundle[i][0]!=1) cin >> bundle[i][4];
    }
    soupfull::implement();
}
/*
4 3 1
3 4 1 3 12
2 2 3 4 10
1 2 4 16

3 5 1
2 3 2 3 17
2 3 2 2 16
2 2 2 3 3
3 3 1 1 12
1 3 3 17

*/

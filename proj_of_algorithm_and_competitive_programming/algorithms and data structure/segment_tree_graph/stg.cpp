#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,m;
struct edge{int u,l,r,w;}e[maxn];
namespace soup1{
    vector<pair<int,int>>adj[maxn];
    long long dist[maxn];
    void dijkstra(int st) {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        for(int i=1; i<=n; ++i) dist[i]=1e18;
        dist[st]=0;
        pq.push({0,st});
        while(!pq.empty()) {
            auto[cd,u]=pq.top();pq.pop();
            if(cd>dist[u]) continue;
            for(auto[v,w]:adj[u]) {
                if(dist[v]>cd+w) {dist[v]=cd+w;pq.push({dist[v],v});}
            }
        }
    }
    void implement() {
        for(int i=1; i<=m; ++i) {
            auto[u,l,r,w]=e[i];
            for(int v=l; v<=r; ++v) {
                adj[u].push_back({v,w});
                //adj[v].push_back({u,w});
            }
        }
        dijkstra(1);
        for(int i=1; i<=n; ++i) cout << (dist[i]==1e18?-1:dist[i]) << (i<n?" ":"");
    }
}
namespace segment_tree_graph{
    long long dist[maxn];
    vector<pair<int,int>>g[maxn<<3];
    int tot_node,idx[maxn<<3];
    void add_edge(int u, int v, int w) {g[u].push_back({v,w});}
    void build(int id, int l, int r) {
        if(l==r) {
            idx[id]=l;
            return;
        }
        idx[id]=++tot_node;
        int mid=(l+r)>>1;
        build(id<<1,l,mid);
        build(id<<1|1,mid+1,r);
        add_edge(idx[id],idx[id<<1],0);
        add_edge(idx[id],idx[id<<1|1],0);
    }
    void add_range(int id, int l, int r, int u, int i, int j, int w) {
        if(l==i && r==j) {add_edge(u,idx[id],w);return;}
        int mid=(l+r)>>1;
        if(i<=mid) add_range(id<<1,l,mid,u,i,min(mid,j),w);
        if(j>mid) add_range(id<<1|1,mid+1,r,u,max(i,mid+1),j,w);
    }
    void dijkstra(int st) {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        for(int i=1; i<=tot_node; ++i) dist[i]=1e18;
        pq.push({0,st});
        dist[st]=0;
        while(!pq.empty()) {
            auto[cd,u]=pq.top();pq.pop();
            if(cd>dist[u]) continue;
            for(auto[v,w]:g[u]) {
                if(dist[v]>cd+w) {dist[v]=cd+w;pq.push({dist[v],v});}
            }
        }
    }
    void implement(int _n) {
        tot_node=_n;
        build(1,1,n);
        for(int i=1; i<=m; ++i) {
            auto[u,l,r,w]=e[i];
            add_range(1,1,n,u,l,r,w);
        }
        dijkstra(1);
        for(int i=1; i<=n; ++i) cout << (dist[i]==1e18?-1:dist[i]) << (i<n?" ":"");
    }
}
int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for(int i=1; i<=m; ++i) cin >> e[i].u >> e[i].l >> e[i].r >> e[i].w;
    //soup1::implement();
    segment_tree_graph::implement(n);
}
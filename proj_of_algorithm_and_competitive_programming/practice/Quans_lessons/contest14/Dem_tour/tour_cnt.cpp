#include <bits/stdc++.h>
using namespace std;
const int maxn=100005,maxm=200005;
int n,m,k,low[maxn],num[maxn],comp[maxn],cnt[maxn],sz[maxn],timer=0,ncomp=0;
vector<pair<int,int>>adj[maxn];
vector<int>g[maxn];
pair<int,int>edge[maxm];
bool bridge[maxm],del[maxn];
map<pair<int,int>,int>mk;
void dfs_init(int u, int p) {
    low[u]=num[u]=++timer;
    for(auto[v,i]:adj[u]) {
        if(v!=p) {
            if(num[v]) low[u]=min(low[u],num[v]);
            else {
                dfs_init(v,u);
                low[u]=min(low[u],low[v]);
                if(low[v]>num[u]) bridge[i]=true;
            }
        }
    }
}
void dfs_comp(int u) {
    comp[u]=ncomp;
    ++cnt[ncomp];
    for(auto[v,i]:adj[u]) {
        if(!comp[v] && !bridge[i]) dfs_comp(v);
    }
}
void dfs_sz(int u, int p) {
    sz[u]=1;
    for(int v:g[u]) {
        if(v!=p && !del[v]) {
            dfs_sz(v,u);
            sz[u]+=sz[v];
        }
    }
}
int centroid(int u, int p, int tot) {
    for(int v:g[u]) {
        if(v!=p && !del[v] && sz[v]>(tot>>1)) return centroid(v,u,tot);
    }
    return u;
}
void collect(int u, int p, int d, vector<pair<int,long long>>& node) {
    node.push_back({d,cnt[u]});
    for(int v:g[u]) {
        if(v!=p && !del[v]) {
            collect(v,u,d+1,node);
        }
    }
}
long long solve(int u) {
    dfs_sz(u,0);
    int root=centroid(u,0,sz[u]);
    long long ans=0;
    del[root]=true;
    vector<pair<int,long long>>all;
    all.push_back({0,cnt[root]});
    vector<vector<pair<int,long long>>>part;
    for(int v:g[root]) {
        if(del[v]) continue;
        vector<pair<int,long long>>tmp;
        collect(v,0,1,tmp);
        all.insert(all.end(),tmp.begin(),tmp.end());
        part.push_back(move(tmp));
    }
    auto query=[](vector<pair<int,long long>>&a)->long long {
        sort(a.begin(),a.end());
        int n=a.size(),l=0,r=n-1;
        vector<long long>pre(a.size()+1,0);
        for(int i=0; i<n; ++i) pre[i+1]=pre[i]+a[i].second;
        long long res=0;
        while(l<r) {
            if(a[l].first+a[r].first>=k) {res+=a[r].second*(pre[r]-pre[l]);--r;}
            else ++l;
        }
        return res;
    };
    ans=query(all);
    for(auto &p:part) ans-=query(p);
    for(int v:g[root]) {
        if(!del[v]) ans+=solve(v);
    }
    return ans;
}
namespace souptrau{
    int d[maxn],up[maxn][20],logn;
    void dfs_lca(int u, int p) {
        for(int v:g[u]) {
            if(v!=p) {
                d[v]=d[u]+1;
                up[v][0]=u;
                dfs_lca(v,u);
            }
        }
    }
    inline int lca(int u, int v) {
        if(d[u]<d[v]) swap(u,v);
        int dif=d[u]-d[v];
        for(;dif; dif&=(dif-1)) {
            int i=__builtin_ctz(dif);
            u=up[u][i];
        }
        if(u==v) return u;
        for(int i=logn; i>=0; --i) {
            if(up[u][i]!=up[v][i]) {u=up[u][i],v=up[v][i];}
        }
        return up[u][0];
    }
    inline int dist(int u, int v) {
        return d[u]+d[v]-(d[lca(u,v)]<<1);
    }
    void implement() {
        int ans=0;
        dfs_lca(1,0);
        logn=31-__builtin_clz(ncomp);
        for(int j=1; j<=logn; ++j) {
            for(int i=1; i<=n; ++i) up[i][j]=up[up[i][j-1]][j-1];
        }
        for(int i=1; i<=n; ++i) {
            for(int j=i+1; j<=n; ++j) {
                int u=comp[i],v=comp[j];
                if(dist(u,v)>=k) {++ans;}
                //cerr << dist(u,v) << ' ';
                //cerr << u << ' ' << v << ' ' << lca(u,v) << '\n';
            }
        }
        cout << ans;
    }
}
int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m >> k;
    for(int i=1; i<=m; ++i) {
        int u,v;cin >> u >> v;
        if(u>v) swap(u,v);
        edge[i]={u,v};
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
        ++mk[{u,v}];
    }
    dfs_init(1,0);
    for(int i=1; i<=n; ++i) {
        if(!comp[i]) {++ncomp;dfs_comp(i);}
    }
    //for(int i=1; i<=n; ++i) cout << comp[i] << ' '; 
    for(int i=1; i<=m; ++i) {
        //cout << bridge[i] << '\n';
        if(bridge[i] && mk[{edge[i].first,edge[i].second}]==1) {
            auto[u,v]=edge[i];
            u=comp[u],v=comp[v];
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    cout << solve(1);
}
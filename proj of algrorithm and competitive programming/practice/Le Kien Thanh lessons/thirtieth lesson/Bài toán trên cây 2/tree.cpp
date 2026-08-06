#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
vector<pair<int,int>>adj[maxn];
int n,m,k,up[maxn][21],d[maxn],dif[maxn],tin[maxn],cnt[maxn],id[maxn],timer,logn;
void add_edge(int v, int u) {
    ++dif[v];
    --dif[u];
}
void dfs(int u, int p) {
    tin[u]=++timer;
    for(auto[v,i]:adj[u]) {
        if(v!=p) {
            d[v]=d[u]+1;
            up[v][0]=u;
            id[v]=i;
            dfs(v,u);
        }
    }
}
void sum(int u, int p) {
    cnt[u]=dif[u];
    for(auto[v,i]:adj[u]) {
        if(v!=p) {
            sum(v,u);
            cnt[u]+=cnt[v];
        }
    }
}
int lca(int u, int v) {
    if(d[u]<d[v]) swap(u,v);
    int len=d[u]-d[v];
    for(len; len; len&=(len-1)) {
        int i=__builtin_ctz(len);
        u=up[u][i];
    }
    if(u==v) return u;
    for(int i=logn; i>=0; --i) {
        if(up[u][i]!=up[v][i]) {
            u=up[u][i];
            v=up[v][i];
        }
    }
    return up[u][0];
}
int main(int argc, char** argv) {
    cin >> n >> m >> k;
    for(int i=1; i<n; ++i) {
        int u,v;cin >> u >> v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }
    logn=31-__builtin_clz(n);
    dfs(1,0);
    for(int j=1; j<=logn; ++j) {
        for(int i=1; i<=n; ++i) {
            up[i][j]=up[up[i][j-1]][j-1];
        }
    }
    for(int i=1; i<=m; ++i) {
        int s;vector<int>node;
        cin >> s;
        for(int i=1,x; i<=s; ++i) {
            cin >> x;
            node.push_back(x);
        }
        sort(node.begin(),node.end(),[&](int a, int b) {return tin[a]<tin[b];});
        for(int i=1; i<s; ++i) {
            node.push_back(lca(node[i-1],node[i]));
        }
        node.erase(unique(node.begin(),node.end()),node.end());
        sort(node.begin(),node.end(),[&](int a, int b) {return tin[a]<tin[b];});
        for(int i=1; i<node.size(); ++i) {
            add_edge(node[i],lca(node[i],node[i-1]));
        }
    }
    sum(1,0);
    vector<int>res;
    for(int i=2; i<=n; ++i) if(cnt[i]>=k) res.push_back(id[i]);
    sort(res.begin(),res.end());
    cout << res.size() << '\n';
    for(int i:res) cout << i << ' ';
}
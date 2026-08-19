#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
typedef long long ll;
const int maxn=100005,maxl=20;
long long n,q,d[maxn],dist[maxn],p[maxn][maxl],logn;
vector<pair<int,int>>adj[maxn];
void dfs(int u, int pa) {
    d[u]=(pa==0?0:d[pa]+1);
    p[u][0]=pa;
    for(auto[v,w]:adj[u]) {
        if(v==pa) continue;
        dist[v]=dist[u]+w;
        dfs(v,u);
    }
}
int lca(int u, int v) {
    if(d[u]<d[v]) swap(u,v);
    for(int i=logn; i>=0; i--) {
        if(d[p[u][i]]>=d[v]) u=p[u][i];
    }
    if(u==v) return u;
    for(int i=logn; i>=0; i--) {
        if(p[u][i]!=p[v][i]) {
            u=p[u][i];
            v=p[v][i];
        }
    }
    return p[u][0];
}
int cal_dist(int u, int v) {
    int l=lca(u,v);
    return d[u]+d[v]-2*d[l]+1+dist[u]+dist[v]-2*dist[l];
}
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("travel")
    cin >> n >> q;
    //cout << n;
    for(int i=1; i<n; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].eb(u,w);
    }
    dfs(1,0);
    for(logn=1; (1<<logn)<=n; logn++);
    logn--;
    for(int j=1; j<=logn; j++) {
        for(int i=1; i<=n; i++) p[i][j]=p[p[i][j-1]][j-1];
    }
    while(q--) {
        int u,v;
        cin >> u >> v;
        cout << cal_dist(u,v) << "\n";
        //cout << lca(u,v) << "\n";
        //cout << u << " " << v << "\n";
        //cout << 1 << "\n";
    }
}
/*
4 2
1 3 1
2 3 2
4 2 3
1 4
2 3


6 3
1 2 2
1 3 4
3 4 4
3 5 3
2 6 1
1 4
2 3
4 5

*/

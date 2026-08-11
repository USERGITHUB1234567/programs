#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
int s,n,q,up[maxn][20],d[maxn],mx[maxn],logn;
vector<int>adj[maxn];
pair<int,int>query[maxn];
void dfs(int u, int p) {
    mx[u]=d[u];
    for(int v:adj[u]) {
        if(v!=p) {
            d[v]=d[u]+1;
            up[v][0]=u;
            dfs(v,u);
            mx[u]=max(mx[u],mx[v]);
        }
    }
}
int lca(int u, int v) {
    if(d[u]<d[v]) swap(u,v);
    int dif=d[u]-d[v];
    for(dif; dif; dif&=(dif-1)) {
        int i=__builtin_ctz(dif);
        u=up[u][i];
    }
    if(u==v) return u;
    for(int i=logn; i>=0; --i) {
        if(up[u][i]!=up[v][i]) u=up[u][i],v=up[v][i];
    }
    return up[u][0];
}
namespace soup{
    void implement() {
        //cout << up[3][2];
        //cout << lca(3,2);
        for(int t=1; t<=q; ++t) {
            auto[u,v]=query[t];
            ++u,++v;
            int l=lca(u,v);
            int ans=0,dist=d[u]+d[v]-(d[l]<<1);
            for(int i=1; i<=2; ++i) {
                swap(u,v);
                int more=mx[v]-d[v],sub=d[u]-d[l];
                //cout << more << ' ' << sub << ' ';
                //int add=(d[v]==mx[v]?d[v]-1)
                if(more>sub) {ans=max(ans,dist);}
                else {
                    ans=max(ans,-d[l]+mx[v]-1);
                }
            }
            ans=min(ans,dist);
            ans=max(ans,1);
            cout << ans << '\n';
        }
        //for(int i=1; i<=n; ++i) cout << mx[i] << ' ';
    }
}
namespace cookedsoup{
    int maxd1[maxn],maxd2[maxn],maxu[maxn],heavy[maxn],c=0;
    void dfs1(int u, int p) {
        for(int v:adj[u]) {
            if(v!=p) {
                dfs1(v,u);
                int val=maxd1[v]+1;
                if(val>maxd1[u]) {
                    maxd2[u]=maxd1[u];
                    maxd1[u]=val;
                    heavy[u]=v;
                }
                else if(val>maxd2[u]) maxd2[u]=val;
            }
        }
    }
    void dfs2(int u, int p, int val) {
        maxu[u]=val;
        int m1=-1,m2=-1,m3=-1;
        auto add_branch=[&](int x) {
            if(x>m1) {m3=m2;m2=m1;m1=x;}
            else if(x>m2) {m3=m2;m2=x;}
            else if(x>m3) {m3=x;}
        };
        if(u!=1) add_branch(val);
        for(int v:adj[u]) {
            if(v!=p) add_branch(maxd1[v]+1);
        }
        if(m3!=-1) c=max(c,m3);
        for(int v:adj[u]) {
            if(v==p) continue;
            int nxt=val+1;
            if(v==heavy[u]) {
                nxt=max(nxt,maxd2[u]+1);
                dfs2(v,u,nxt);
            }else {
                nxt=max(nxt,maxd1[u]+1);
                dfs2(v,u,nxt);
            }
        }
    }
    void implement() {
        //dfs(1,0);
        dfs1(1,0);
        dfs2(1,0,0);
        for(int t=1; t<=q; ++t) {
            auto[u,v]=query[t];
            ++u,++v;
            int l=lca(u,v),dist=d[u]+d[v]-(d[l]<<1);
            cout << min(c,dist) << '\n';
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    //freopen("patrol.inp", "r", stdin);
    //freopen("patrol.out", "w", stdout);
    cin >> s >> n >> q;
    for(int i=1,u,v; i<n; ++i) {
        cin >> u >> v;
        ++u,++v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    logn=32-__builtin_clz(n);
    dfs(1,0);
    for(int j=1; j<=logn; ++j) {
        for(int i=1; i<=n; ++i) {
            up[i][j]=up[up[i][j-1]][j-1];
        }
    }
    for(int i=1; i<=q; ++i) cin >> query[i].first >> query[i].second;
    cookedsoup::implement();
}
/*
1 13 5
0 1
1 2
2 3
0 4
4 5
5 6
0 7
8 9
0 10
10 11
11 12
3 6
3 2
1 10
12 9
0 3
*/
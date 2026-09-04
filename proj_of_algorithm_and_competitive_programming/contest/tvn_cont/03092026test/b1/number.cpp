#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,q,d[maxn];
long long mod;
pair<int,int>query[maxn];
int anc[maxn][20],child[maxn][20];
long long up[maxn][20],down[maxn][20];
vector<pair<int,long long>>adj[maxn];
long long modexp(long long base, int exp, int m) {
    long long res=1%m;
    while(exp) {
        if(exp&1) {res=(res*base)%m;}
        base=(base*base)%m;
        exp>>=1;
    }
    return res;
}
namespace soupfull{
    int logn;
    void dfs_init(int u, int p) {
        for(auto[v,w]:adj[u]) {
            if(v!=p) {
                //cerr << u << ' ' << v << ' ' << w << ' ' << down[2][0] << '\n';
                anc[v][0]=u;
                up[v][0]=w%mod;
                down[v][0]=w%mod;
                //child[u][0]=v;
                d[v]=d[u]+1;
                dfs_init(v,u);
            }
        }
    }
    int lca(int u, int v) {
        if(d[u]<d[v]) swap(u,v);
        int dif=d[u]-d[v];
        for(dif; dif; dif&=(dif-1)) {
            int i=__builtin_ctz(dif);
            u=anc[u][i];
        }
        if(u==v) return u;
        for(int i=logn; i>=0; --i) {
            if(anc[u][i]!=anc[v][i]) u=anc[u][i],v=anc[v][i];
        }
        return anc[u][0];
    }
    long long jump(int u, int v) {
        long long res=0;
        if(d[u]<d[v]) {
            int dif=d[v]-d[u];
            vector<pair<int,long long>>block;
            for(dif; dif; dif&=(dif-1)) {
                int i=__builtin_ctz(dif);
                block.push_back({i,down[v][i]});
                v=anc[v][i];
            }
            for(int i=block.size()-1; i>=0; --i) {
                res=(res*modexp(10,(1<<block[i].first),mod)+block[i].second)%mod;
            }
        }else {
            int dif=d[u]-d[v];
            for(dif; dif; dif&=(dif-1)) {
                int i=__builtin_ctz(dif);
                res=(res*modexp(10,(1<<i),mod))%mod;
                res=(res+up[u][i])%mod;
                u=anc[u][i];
            }
        }
        return res;
    }
    void implement() {
        dfs_init(1,0);
        logn=31-__builtin_clz(n);
        for(int j=1; j<=logn; ++j) {
            for(int i=1; i<=n; ++i) {
                anc[i][j]=anc[anc[i][j-1]][j-1];
                //child[i][j]=child[child[i][j-1]][j-1];
                long long base=modexp(10,(1<<(j-1)),mod);
                long long t1=up[i][j-1],t2=up[anc[i][j-1]][j-1];
                long long z1=down[i][j-1],z2=down[anc[i][j-1]][j-1];
                long long res1=((t1*base)%mod+t2)%mod,res2=((z2*base)%mod+z1)%mod;
                up[i][j]=res1,down[i][j]=res2;
            }
        }
        for(int i=1; i<=q; ++i) {
            auto[u,v]=query[i];
            int l=lca(u,v);
            long long t1=jump(u,l),t2=jump(l,v);
            int dif=d[v]-d[l];
            long long ans=((t1*modexp(10,dif,mod))+t2)%mod;
            cout << ans << '\n';
        }
    }
}
int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("number.inp", "r" ,stdin);
    freopen("number.out", "w", stdout);
    cin >> n >> mod;
    for(int i=1,u,v,w; i<n; ++i) {
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    cin >> q;
    for(int i=1; i<=q; ++i) cin >> query[i].first >> query[i].second;
    soupfull::implement();
}
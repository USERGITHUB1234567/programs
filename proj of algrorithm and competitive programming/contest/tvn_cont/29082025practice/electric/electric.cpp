#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);
#define fi first
#define se second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
const int maxn=100005;
int n,m,q;
vector<pair<int,int>>adj[maxn];
pair<int,int>qu[maxn];
vector<pair<int,int>>tree[maxn];
bool mk[maxn];
struct edge
{
    int u,v,w;
}ed[maxn];
struct disjoint_sets
{
    int p[maxn];
    disjoint_sets()
    {
        for(int i=0; i<maxn; i++) p[i]=i;
    }
    int found(int u)
    {
        if(u==p[u]) return u;
        return p[u]=found(p[u]);
    }
    void unite(int u, int v)
    {
        u=found(u);
        v=found(v);
        if(u!=v) p[v]=u;
    }
}dsu;
bool cmp(edge a, edge b)
{
    return a.w<b.w;
}
void soup1()
{
    sort(ed+1,ed+1+n,cmp);
    for(int k=1; k<=q; k++) {
        long long res=0;
        auto[a,b]=qu[k];
        mk[a]=true;
        mk[b]=true;
        for(int i=1; i<=m; i++) {
            auto[u,v,w]=ed[i];
            if((mk[u] && mk[v]) || (dsu.found(u)==dsu.found(v))) continue;
            dsu.unite(u,v);
            if(mk[u] || mk[v]) {
                mk[u]=true,mk[v]=true;
            }
            res+=w;
        }
        cout << res << "\n";
        for(int i=1; i<=n; i++) {
            dsu.p[i]=i;
            mk[i]=false;
        }
        //mk[a]=false;mk[b]=false;
    }
}
void soupfull()
{
    sort(ed+1,ed+1+n,cmp);
    long long mst=0;
    for(int i=1; i<=m; i++) {
        auto[u,v,w]=ed[i];
        if(dsu.found(u)==dsu.found(v)) continue;
        mst+=w;
        dsu.unite(u,v);
    }
    for(int k=1; k<=q; k++) {

    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("electric")
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        ed[i]={u,v,w};
        adj[u].eb(v,w);
        adj[v].eb(u,w);
    }
    cin >> q;
    for(int i=1; i<=q; ++i) cin >> qu[i].fi >> qu[i].se;
    soup1();

}

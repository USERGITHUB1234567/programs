/**/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define all(x) x.begin(), x.end()
#define sortunique(x) sort(all(x)); x.erase(unique(all(x)), x.end());
#define forw(i,a,b) for(int (i)=(a); (i)<=(b); ++(i))
#define forb(i,a,b) for(int (i)=(a); (i)>=(b); --(i))
#define eb emplace_back
#define fi first
#define se second
#define pb push_back
using namespace std;
using namespace std::chrono;
static const int maxd=1003;
typedef short bignum[maxd];
typedef long long ll;
typedef long double ld;
const int maxn=200005,mod=1000000007,maxb=320;
long long fact[maxn],ifact[maxn];
inline int maxi(int a, int b) {return (a>b?a:b);}
inline int mini(int a, int b) {return (a<b?a:b);}
inline ll maxill(ll a, ll b) {return (a>b?a:b);}
inline ll minill(ll a, ll b) {return (a<b?a:b);}
inline double maxid(double a, double b) {return (a>b?a:b);}
inline double minid(double a, double b) {return (a<b?a:b);}
inline ld maxild(ld a, ld b) {return (a>b?a:b);}
inline ld minild(ld a, ld b) {return (a<b?a:b);}
inline ll modexp(ll b, ll e, ll m) {
    ll res=1%m;
    while(e>0) {
        if(e&1) res=(res*b)%m;
        b=(b*b)%m;
        e>>=1;
    }
    return res;
}
inline ll logarit(ll k, ll n){ll res=0;while(n>0){n/=k;++res;}return res;}
void setUpFactor() {
    fact[0]=1;
    for(int i=1; i<maxn; ++i) fact[i]=fact[i-1]*i%mod;
    int tc=maxn-1;
    ifact[tc]=modexp(fact[tc],mod-2,mod);
    for(int i=tc; i>=1; --i) ifact[i-1]=ifact[i]*i%mod; 
}
inline long long ncr(long long k, long long n) {return (k==n?1:fact[n]*ifact[n-k]%mod*ifact[k]%mod);}
mt19937_64 generator1(steady_clock::now().time_since_epoch().count());
mt19937_64 generator2(high_resolution_clock::now().time_since_epoch().count());
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);}
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);}
auto imp_st=high_resolution_clock::now();
inline void start_timer() {imp_st=high_resolution_clock::now();}
inline void get_execution_time() {
    auto imp_en=high_resolution_clock::now();
    cerr << "Implementation Time: "<< duration_cast<milliseconds>(imp_en-imp_st).count() << " ms\n";
}
int n,m,q,timer=0,ncomp=0,num[maxn],low[maxn],comp[maxn],up[maxn][20],depth[maxn],logn,ans[maxn],dist[maxn];
pair<int,int>edge[maxn];
bool bridge[maxn],vis[maxn],onway[maxn],mark;
vector<pair<int,int>>adj[maxn],tree[maxn];
inline void dfs(int u, int p) {
    num[u]=low[u]=++timer;
    vis[u]=true;
    if(u==n) mark=false;
    for(auto[v,i]:adj[u]) {
        if(v==p) continue;
        if(vis[v]) low[u]=min(low[u],num[v]);
        else {
            onway[i]^=mark;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]==num[v]) bridge[i]=true;
            onway[i]^=mark;
        }
    }
}
inline void dfscomp(int u) {
    comp[u]=ncomp;
    for(auto[v,i]:adj[u]) {
        if(!comp[v] && !bridge[i]) dfscomp(v);
    }
}
pair<int,int>mk[maxn];
inline void dfslca(int u, int p) {
    //cout << u << '\n';
    for(auto[v,i]:tree[u]) {
        if(v==p) continue;
        depth[v]=depth[u]+1;
        up[v][0]=u;
        dfslca(v,u);
    }
}
inline int lca(int u, int v) {
    if(depth[u]<depth[v]) swap(u,v);
    int diff=depth[u]-depth[v];
    for(int i=logn; i>=0; --i) {if((1<<i)&diff) u=up[u][i];}
    if(u==v) return u;
    for(int i=logn; i>=0; --i) {
        if(up[u][i]!=up[v][i]) {
            u=up[u][i],v=up[v][i];
        }
    }
    return up[u][0];
}
inline void bfs_ans(queue<int>&q) {
    while(!q.empty()) {
        int u=q.front();q.pop();
        for(auto[v,i]:adj[u]) {
            if(dist[v]>dist[u]+1) {
                dist[v]=dist[u]+1;
                ans[v]=ans[u];
            }
            else if(dist[v]==dist[u]+1) {
                ans[v]=min(ans[v],ans[u]);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    //file("valley")
    cin >> n >> m;
    for(int i=1,u,v; i<=m; ++i) {
        cin >> u >> v;
        edge[i]={u,v};
        adj[u].pb({v,i});adj[v].pb({u,i});
    }
    mark=true;
    dfs(1,0);
    cin >> q;
    //trace(comp[n],1);
    //cout << mk[comp[8]].fi << ' ' << mk[comp[6]].fi << ' ' << mk[comp[3]].fi << ' ';
    for(int i=1; i<=m; ++i) ans[i]=m+1;
    for(int i=1; i<=n; ++i) dist[i]=m+1;
    queue<int>qu;
    for(int i=1; i<=m; ++i) {
        if(!bridge[i] || onway[i]) continue;
        auto[u,v]=edge[i];
        ans[u]=min(ans[u],i),ans[v]=min(ans[v],i);
        if(dist[u]==m+1) {dist[u]=0;qu.push(u);}
        if(dist[v]==m+1) {dist[v]=0;qu.push(v);}
    }
    for(int i=1; i<=m; ++i) cout << onway[i] << ' ';
    bfs_ans(qu);
    while(q--) {
        int c;cin >> c;
        cout << (ans[c]==m+1?-1:ans[c]) << '\n';
    }
    return 0;
}
/*
5 4
1 2
2 3
3 4
4 5
3
1
2
3

7 6
1 2
1 5
2 3
3 4
5 7
6 7
7
1
2
3
4
5
6
7

3 3
1 2
2 3
3 1
1
1
*/
/**/
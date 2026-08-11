#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define foutput(name) freopen(name, "w", stdout);
#define finput(name) freopen(name,"r", stdin);
#define all(x) x.begin(), x.end()
#define sortunique(x) sort(all(x)); x.erase(unique(all(x)), x.end());
#define forw(i,a,b) for(int (i)=(a); (i)<=(b); ++(i))
#define forb(i,a,b) for(int (i)=(a); (i)>=(b); --(i))
#define eb emplace_back
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
using namespace std::chrono;
static const int maxd=1003;
typedef short bignum[maxd];
typedef long long ll;
typedef long double ld;
const int maxn=100005,mod=1000000007;
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
inline ll log(ll k, ll n){ll res=0;while(n>0){n/=k;++res;}return res;}
void setupfactor() {
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
int n,q,d[maxn],p[maxn][20],logn;
ll di[maxn];
vector<pair<int,int>>adj[maxn];
void dfs(int u,int par) {
    for(auto[v,w]:adj[u]) {
        if(v==par) continue;
        d[v]=d[u]+1;
        di[v]=di[u]+w;
        p[v][0]=u;
        dfs(v,u);
    }
}
inline int lca(int u, int v) {
    if(d[u]<d[v]) swap(u,v);
    for(int i=logn; i>=0; --i) {
        if(d[p[u][i]]>=d[v]) u=p[u][i];
    }
    if(u==v) return u;
    for(int i=logn; i>=0; --i) {
        if(p[u][i]!=p[v][i]) {u=p[u][i],v=p[v][i];}
    }
    return p[u][0];
}
inline long long dist(int x, int y) {return di[x]+di[y]-2*di[lca(x,y)];}
inline int kjump(int u, int k) {
    for (int i=0; i<=logn; ++i) {
        if (k&(1<<i)) u=p[u][i];
    }
    return u;
}
inline int query(int x, int y, int k) {
    int L=lca(x,y);
    int l1=d[x]-d[L]+1;
    if (k<=l1) {
        return kjump(x,k-1);
    } else {
        int k2=k-l1;
        int l2=d[y]-d[L];
        int d=l2-k2;
        return kjump(y,d);
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("qtree")
    cin >> n >> q;
    for(int i=1,u,v,w; i<n; ++i) {
        cin >> u >> v >> w;
        adj[u].eb(v,w);
        adj[v].eb(u,w);
    }
    dfs(1,0);
    logn=log(2,n);
    for(int j=1; j<=logn; ++j) {
        for(int i=1; i<=n; ++i) p[i][j]=p[p[i][j-1]][j-1];
    }
    while(q--) {
        int ty,x,y,k;cin >> ty;
        if(ty==1) {cin >> x >> y;cout << dist(x,y) << ' ';}
        else {cin >> x >> y >> k;cout << query(x,y,k) << ' ';}
    }
    return 0;
}
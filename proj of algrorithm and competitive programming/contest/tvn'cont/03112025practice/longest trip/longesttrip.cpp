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
static const int maxd=1003;
typedef short bignum[maxd];
typedef long long ll;
typedef long double ld;
const int maxn=200005,mod=1000000007;
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
mt19937_64 generator1(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 generator2(chrono::high_resolution_clock::now().time_since_epoch().count());
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);}
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);}
int n,m;
pair<int,long long>ans[maxn];
bool vis[maxn];
vector<pair<int,long long>>adj[maxn];
void dfs(int u) {
    vis[u]=true;
    ans[u].fi=ans[u].se=0;
    for(auto[v,l]:adj[u]) {
        if(!vis[v]) dfs(v);
        if(ans[v].fi+1>ans[u].fi) {
            ans[u].fi=ans[v].fi+1;
            ans[u].se=ans[v].se+l;
        }
        else if(ans[v].fi+1==ans[u].fi) {
            ans[u].se=min(ans[u].se,ans[v].se+l);
        }
    }
}
bool cmp(pair<int,ll>a,pair<int,ll>b) {return a.se<b.se;}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("longesttrip")
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; ++i) {
        int u,v;long long l;
        scanf("%d%d%lld",&u,&v,&l);
        adj[u].pb({v,l});
        //adj[v].pb({u,l});
    }
    for(int i=1; i<=n; ++i) sort(all(adj[i]),cmp);
    for(int i=1; i<=n; ++i) {
        if(!vis[i]) dfs(i);
    }
    for(int i=1; i<=n; ++i) printf("%d %lld\n",ans[i].fi,ans[i].se);
    return 0;
}

/*
4 5
4 3 10
4 2 10
3 1 10
2 1 10
4 1 10

4 5
4 3 4
4 2 2
3 1 5
2 1 10
4 1 1
*/



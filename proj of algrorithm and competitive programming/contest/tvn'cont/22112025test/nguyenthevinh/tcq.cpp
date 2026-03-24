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
mt19937_64 generator1(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 generator2(chrono::high_resolution_clock::now().time_since_epoch().count());
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);}
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);}
int n,q,c[maxn];
vector<int>adj[maxn];
namespace soup1 {
    int sq=320;
    int cnt[320][maxn];
    inline void dfs(int u, int p) {
        cnt[c[u]][u]=1;
        for(int v: adj[u]) {
            if(v==p) continue;
            dfs(v,u);
            for(int i=1; i<=sq; ++i) cnt[i][u]+=cnt[i][v];
        }
    }
    void solve() {
        memset(cnt,0,sizeof(cnt));
        dfs(1,0);
        //cout << cnt[2][1];
        while(q--) {
            int u,k,ans=0;
            cin >> u >> k;
            for(int i=1; i<=sq; ++i) if(cnt[i][u]>=k) ++ans;
            cout << ans << '\n';
        }
    }
}
namespace souptrau {
    int p[maxn],cnt[maxn];
    inline void dfssetup(int u, int pr) {
        for(int v:adj[u]) {
            if(v==pr) continue;
            p[v]=u;
            dfssetup(v,u);
        }
    }
    inline void dfs(int u) {
        ++cnt[c[u]];
        for(int v:adj[u]) {
            if(v==p[u]) continue;
            dfs(v);
        }
    }
    void solve() {
        dfssetup(1,0);
        for(int tc=1; tc<=q; ++tc) {
            int u,k;
            cin >> u >> k;
            for(int i=1; i<=n; ++i) cnt[i]=0;
            dfs(u);
            int kq=0;
            for(int i=1; i<=n; ++i) if(cnt[i]>=k) ++kq;
            cout << kq << '\n';
        }
    }
}
namespace soup2 {
    void solve() {
        
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("tcq")
    cin >> n >> q;
    int ma=*max_element(c+1,c+1+n);
    for(int i=1; i<=n; ++i) cin >> c[i];
    for(int i=1,u,v; i<n; ++i) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    //souptrau::solve();

    if(ma<320) soup1::solve();
    else souptrau::solve();
    return 0;
}
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
const int maxn=100005,mod=1000000007,maxb=320; 
namespace mathematics{ 
    long long fact[maxn],ifact[maxn]; 
    long long __gcd(long long a, long long b) { if(a<b) swap(a,b); while(a%b!=0) {long long c=a%b;a=b,b=c;} return b; } 
    inline ll __logarit(ll k, ll n){ll res=0;while(n>0){n/=k;++res;}return res;} 
    inline ll modexp(ll b, ll e, ll m) { ll res=1%m; while(e>0) { if(e&1) res=(res*b)%m; b=(b*b)%m; e>>=1; } return res; } 
    inline int maxi(int a, int b) {return (a>b?a:b);} 
    inline int mini(int a, int b) {return (a<b?a:b);} 
    inline ll maxill(ll a, ll b) {return (a>b?a:b);} 
    inline ll minill(ll a, ll b) {return (a<b?a:b);} 
    inline double maxid(double a, double b) {return (a>b?a:b);} 
    inline double minid(double a, double b) {return (a<b?a:b);} 
    inline ld maxild(ld a, ld b) {return (a>b?a:b);} 
    inline ld minild(ld a, ld b) {return (a<b?a:b);} 
    void setUpFactor() { fact[0]=1; for(int i=1; i<maxn; ++i) fact[i]=fact[i-1]*i%mod; int tc=maxn-1; ifact[tc]=modexp(fact[tc],mod-2,mod); for(int i=tc; i>=1; --i) ifact[i-1]=ifact[i]*i%mod; } 
    inline long long ncr(long long k, long long n) {return (k==n?1:fact[n]*ifact[n-k]%mod*ifact[k]%mod);} 
} 
using namespace mathematics; 
mt19937_64 generator1(steady_clock::now().time_since_epoch().count()); 
mt19937_64 generator2(high_resolution_clock::now().time_since_epoch().count()); 
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);} 
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);} 
auto imp_st=high_resolution_clock::now(); 
inline void start_timer() {imp_st=high_resolution_clock::now();} 
inline void get_execution_time() { auto imp_en=high_resolution_clock::now(); cerr << "Implementation Time: "<< duration_cast<milliseconds>(imp_en-imp_st).count() << " ms\n"; } 
int n,m,up[maxn][20],logn,d[maxn];
vector<int>adj[maxn];
inline void dfs(int u, int p) {
    for(int v:adj[u]) {
        if(v==p) continue;
        d[v]=d[u]+1;
        up[v][0]=u;
        dfs(v,u);
    }
}
inline int jump(int u, int k) {
    for(int i=0; i<32; ++i) if((1<<i)&k) u=up[u][i];
    return u;
}
inline int lca(int u, int v) {
    if(d[u]<d[v]) swap(u,v);
    for(int i=logn; i>=0; --i) {
        if(d[up[u][i]]>=d[v] && up[u][i]!=0) u=up[u][i];
    }
    if(u==v) return u;
    for(int i=logn; i>=0; --i) {
        if(up[u][i]!=up[v][i]) {u=up[u][i],v=up[v][i];}
    }
    return up[u][0];
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> n;
    for(int i=1,u,v; i<n; ++i) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    logn=log2(n);
    for(int j=1; j<=logn; ++j) for(int i=1; i<=n; ++i) up[i][j]=up[up[i][j-1]][j-1];
    cin >> m;
    for(int i=1; i<=m; ++i) {
        int a,b,l;cin >> a >> b;l=lca(a,b);
        if(l==a) {
            int dif=d[b]-d[a]-1;
            cout << jump(b,dif) << '\n';
        }
        else cout << up[a][0] << '\n';
    }
    //cout << lca(3,4);
    return 0; 
} 
/**/
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
auto imp_st=high_resolution_clock::now();
inline void start_timer() {imp_st=high_resolution_clock::now();}
inline void get_execution_time() {
    auto imp_en=high_resolution_clock::now();
    cerr << "Implementation Time: "<< duration_cast<milliseconds>(imp_en-imp_st).count() << " ms\n";
}
int n;
vector<int>adj[maxn];
pair<int,int>edge[maxn];
namespace soup1 {
    bool check() {
        for(int i=1; i<n; ++i) {
            auto[u,v]=edge[i];
            if(u!=i || v!=i+1) return false;
        }
        return true;
    }
    void solve() {
        setupfactor();
        for(int i=1; i<=n; ++i) {
            cout << ncr(i-1,n-1) << '\n';
        }
    }
}
namespace destructive_brute{
    int cnt=0;
    bool mk[maxn];
    inline void init() {for(int i=0; i<=n; ++i) mk[i]=false;}
    inline void dfs() {

    }
    void solve() {
        for(int i=1; i<n; ++i) {
            auto[u,v]=edge[i];
            adj[u].pb(v);
            adj[v].pb(u);
        }

    }
};
namespace soup2 {
    int ans=0;
    bool used[maxn];
    inline void dfs(int cnt) {
        if(cnt==n) {++ans;return;}
        for(int u=1; u<=n; ++u) {
            if(used[u]) continue;
            for(int v:adj[u]) 
            if(used[v] && !used[u]) {
                used[u]==true;
                dfs(cnt+1);
                used[u]=false;
            }
        }
    }
    inline void solve() {
        for(int k=1; k<=n; ++k) {
            
        }
    }
}
namespace soup4{
    long long sz[maxn];
    vector<int>at_depth[maxn];
    inline void init() {for(int i=0; i<=n; ++i) {at_depth[i].clear();sz[i]=0;}}
    inline void dfs(int u, int p, int d,long long &res) {
        sz[u]=1;
        at_depth[d].pb(u);
        long long sum=0;
        cout << u << ' ';
        for(int v:adj[u]) {
            if(v==p) continue;
            //cout << v << ' ';
            dfs(v,u,d+1,res);
            sz[u]+=sz[v];
        }
        sum=sz[u]-1;
        for(int v:adj[u]) {
            if(v==p) continue;
            res=(res*ncr(sz[v],sum))%mod;
            sum-=sz[v];
        }
    }
    void solve() {
        setupfactor();
        for(int i=1; i<n; ++i) {
            auto[u,v]=edge[i];
            adj[u].pb(v);
            adj[v].pb(u);
        }
        for(int i=1; i<=n; ++i) {
            long long ans=1;
            init();
            dfs(i,0,0,ans);
            //if(i==2) cout << sz[3] << ' ';
            // for(int j=0; j<n; ++j) {
            //     if(at_depth[j].empty()) continue;
            //     long long sum_sz=0;
            //     for(int v:at_depth[j]) sum_sz+=sz[v];
            //     //cout << sum_sz << ' ';
            //     for(int v:at_depth[j]) {
            //         cout << j << ' ' << sz[v] << ' ' << sum_sz << ' ' << ncr(sz[v],sum_sz) << ' ' << ncr(2,4) << '\n';
            //         ans=(ans*ncr(sz[v],sum_sz))%mod;
            //         sum_sz-=sz[v];
            //     }
            // }
            cout << ans << '\n';
        }
    }
}
namespace soup4upgrade{
    int sz[maxn];
    long long f[maxn];
    inline void dfs1(int u, int p) {
        sz[u]=1;
        //cout << u << ' ';
        for(int v:adj[u]) {
            if(v==p) continue;
            dfs1(v,u);
            sz[u]+=sz[v];
            //f[u]=(f[u]*f[v])%mod;
        }
    }
    inline void dfs2(int u, int p) {
        f[u]=1;
        //cout << u << ' ';
        for(int v:adj[u]) {
            if (v==p) continue;
            dfs2(v,u);
            f[u]*=f[v]*ifact[sz[v]]%mod;
            // f[u]=(f[u]*f[v])%mod;
        }
        f[u]*=fact[sz[u]-1]%mod;
    }
    inline void solve() {
        setupfactor();
        for (int i=1; i<n; ++i) {
            auto[u,v]=edge[i];
            adj[u].pb(v);
            adj[v].pb(u);
        }
        for(int k=1; k<=n; ++k) {
            dfs1(k,0);
            dfs2(k,0);
            cout << f[k] << '\n';
        }
    }
};
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    //file("dist")
    cin >> n;
    for(int i=1; i<n; ++i) cin >> edge[i].fi >> edge[i].se;
    if(soup1::check()) soup1::solve();
    else soup4::solve();
    cout << '\n';
    soup4upgrade::solve();
    //soup1::solve();
    //cout << ncr(1,4)*ncr(3,3)*ncr(1,2)*ncr(1,1);
    //cout << ncr(2,4)*ncr(2,2);
    //cout << ncr(2,4);
    return 0;
}
/**/
/*
1
10
45
120
210
252
210
120
45
10
1
*/
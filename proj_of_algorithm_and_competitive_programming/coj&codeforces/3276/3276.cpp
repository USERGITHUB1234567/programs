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
namespace mathematics{ 
    long long fact[maxn],ifact[maxn]; 
    long long __uiagcd(long long a, long long b) { if(a<b) swap(a,b); while(a%b!=0) {long long c=a%b;a=b,b=c;} return b; } 
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
int n,c[maxn];
vector<int>adj[maxn];
namespace soup1{
    map<int,int>mp;
    int par[maxn],ans[maxn];
    unordered_set<int>st[maxn];
    // inline void dfsinit(int u, int p) {
    //     ++mp[c[u]];
    //     par[u]=p;
    //     for(int v:adj[u]) {
    //         if(v==p) continue;
    //         dfsinit(v,u);
    //     }
    // }
    inline void dfs(int u, int p) {
        //cerr << u << ' ';
        for(int v:adj[u]) {
            if(v==p) continue;
            dfs(v,u);
            for(int t:st[v]) st[u].insert(t);
            st[v].clear();
        }
        st[u].insert(c[u]);
        ans[u]=st[u].size();
    }
    void solve() {
        // dfsinit(1,0);
        dfs(1,0);
        for(int i=1; i<=n; ++i) cout << ans[i] << (i<n?" ":"");
    }
}
namespace soupfull{
    const int block=450;
    int st[maxn],en[maxn],t[maxn],timer=0,ans[maxn];
    struct query{
        int l,r,id;
    };
    query queries[maxn];
    //unordered_map<int,int>ump;
    int cnt[maxn],cur=0;
    inline void add(int i) {
        if(cnt[c[t[i]]]==0) ++cur;
        ++cnt[c[t[i]]];
    }
    inline void rem(int i) {
        --cnt[c[t[i]]];
        if(cnt[c[t[i]]]==0) --cur;
    }
    inline void dfs(int u, int p) {
        st[u]=++timer;
        t[timer]=u;
        for(int v:adj[u]) if(v!=p) dfs(v,u);
        en[u]=timer;
    }
    void solve() {
        dfs(1,0);
        vector<int>tmp;
        for(int i=1; i<=n; ++i) {
            tmp.pb(c[i]);
        }
        sortunique(tmp);
        for(int i=1; i<=n; ++i) c[i]=lower_bound(all(tmp),c[i])-tmp.begin();
        for(int i=1; i<=n; ++i) {
            queries[i]={st[i],en[i],i};
        }
        sort(queries+1,queries+1+n,[](query a,query b){
            int ba=a.l/block,bb=b.l/block;
            return (ba==bb?a.r<b.r:ba<bb);
        }); 
        int l=1,r=0;
        for(int i=1; i<=n; ++i) {
            int u=queries[i].l,v=queries[i].r;
            while(r<v) add(++r);
            while(r>v) rem(r--);
            while(l<u) rem(l++);
            while(l>u) add(--l);
            ans[queries[i].id]=cur;
        }
        for(int i=1; i<=n; ++i) cout << ans[i] << (i<n?" ":"");
    }
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> c[i];
    for(int i=1,u,v; i<n; ++i) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    soupfull::solve();
    return 0; 

} 
/**/
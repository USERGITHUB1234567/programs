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
const int maxn=100005,mod=1000000007,maxb=320;
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
auto imp_st=high_resolution_clock::now();
inline void start_timer() {imp_st=high_resolution_clock::now();}
inline void get_execution_time() {
    auto imp_en=high_resolution_clock::now();
    cerr << "Implementation Time: "<< duration_cast<milliseconds>(imp_en-imp_st).count() << " ms\n";
}
struct disjoint_set_union{
    int n;vector<int>p,sz;
    disjoint_set_union(int _n):n(_n),p(_n+1),sz(_n+1,1) {for(int i=1; i<=n; ++i) p[i]=i;}
    inline void reset(){for(int i=1; i<=n; ++i) {p[i]=i;sz[i]=1;}}
    int found(int u) {return (p[u]==u?u:p[u]=found(p[u]));}
    void unite(int u, int v) {
        u=found(u),v=found(v);
        if(u==v) return;
        if(sz[u]<sz[v]) swap(u,v);
        p[v]=u;
        sz[u]+=sz[v];
    }
    int size_query(int u, int v) {
        u=found(u),v=found(v);
        if(u==v) return sz[u];
        return sz[u]+sz[v];
    }
};
struct query{int x,y,z;}queries[maxn];
pair<int,int>edge[maxn];
int n,m,q;
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for(int i=1; i<=m; ++i) cin >> edge[i].fi >> edge[i].se;
    cin >> q;
    for(int i=1; i<=q; ++i) cin >> queries[i].x >> queries[i].y >> queries[i].z;
    vector<int>l(q+1,1),r(q+1,m);
    disjoint_set_union dsu(n);
    while(true) {
        bool stop=true;
        vector<vector<int>>bucket(m+1);
        for(int i=1; i<=q; ++i) {
            if(l[i]<r[i]) {
                stop=false;
                int mid=(l[i]+r[i])>>1;
                bucket[mid].pb(i);
            }
        }
        if(stop) break;
        for(int e=1; e<=m; ++e) {
            dsu.unite(edge[e].fi,edge[e].se);
            for(int i:bucket[e]) {
                auto[x,y,z]=queries[i];
                int s=dsu.size_query(x,y);
                if(s>=z) r[i]=e;
                else l[i]=e+1;
            }
        }
        dsu.reset();
    }
    for(int i=1; i<=q; ++i) cout << l[i] << '\n';
    return 0;
}
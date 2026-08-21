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
#define int long long 
using namespace std;
using namespace std::chrono;
static const int maxd=1003;
typedef short bignum[maxd];
typedef long long ll;
typedef long double ld;
const int maxn=500005,mod=1000000007,maxb=320;
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
int n,m,p[maxn],b[maxn],q,depth[maxn],timer,tin[maxn],tout[maxn];
long long t[maxn];
struct query{int f,x,d;}queries[maxn];
vector<int>adj[maxn],fac[maxn];
inline void dfs(int u) {
    tin[u]=++timer;
    for(int v:adj[u]) {
        depth[v]=depth[u]+1;
        dfs(v);
    }
    tout[u]=timer;
}
struct fenwick_tree{
    vector<ll>ft;
    int num;
    fenwick_tree(int _n):num(_n),ft(_n+1,0){}
    void update(int i, long long v) {
        while(i<=num) {
            ft[i]+=v;
            i+=i&-i;
        }
    }
    long long query(int i) {
        if(i>num) i=num;
        long long res=0;
        while(i>0) {
            res+=ft[i];
            i-=i&-i;
        }
        return res;
    }
    long long range_update(int i, int j, long long v) {
        if(i<1) i=1;
        if(i<=num)update(i,v);
        if(j+1<=num) update(j+1,-v);
    }
};
signed main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for(int i=2; i<=n; ++i) {cin >> p[i];adj[p[i]].pb(i);}
    for(int i=1; i<=n; ++i) {cin >> b[i];fac[b[i]].pb(i);}
    for(int i=1; i<=m; ++i) cin >> t[i];
    cin >> q;
    for(int i=1; i<=q; ++i) {cin >> queries[i].f >> queries[i].x >> queries[i].d;}
    vector<int>l(m+1,1),r(m+1,q+1);
    depth[1]=0;
    dfs(1);
    while(true) {
        bool stop=true;
        vector<vector<int>>bucket(q+2);
        for(int i=1; i<=m; ++i) {
            if(l[i]<r[i]) {
                stop=false;
                bucket[(l[i]+r[i])>>1].pb(i);
            }
        }
        if(stop) break;
        fenwick_tree fen1(n),fen2(n);
        for(int year=1; year<=q; ++year) {
            auto[f,x,d]=queries[year];
            fen1.range_update(tin[f],tout[f],x-depth[f]*d);
            fen2.range_update(tin[f],tout[f],d);
            for(int i:bucket[year]) {
                long long sum=0;
                for(int j:fac[i]) {
                    sum+=fen1.query(tin[j])+fen2.query(tin[j])*depth[j];
                    if(sum>=t[i]) break;
                }
                if(sum>=t[i]) r[i]=year;
                else l[i]=year+1;
            }
        }
    }
    for(int i=1; i<=m; ++i) {
        if(l[i]==q+1) cout << "rekt" << '\n';
        else cout << l[i] << '\n';
    }
    return 0;
}
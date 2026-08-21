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
int n,m,p,s[maxn];
struct edge{int u,v,w;}e[maxn];
vector<pair<int,int>>adj[maxn];
namespace souprua{
    void solve() {for(int i=1; i<=n; ++i) cout << 0;}
}
namespace soup1{
    bool server[maxn];
    int d[maxn];
    inline void dijkstra(int s) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=1; i<=n; ++i) d[i]=INT_MAX;
        d[s]=0;
        pq.push({0,s});
        while(!pq.empty()) {
            auto [cd,u]=pq.top();pq.pop();
            if(cd>d[u]) continue;
            for(auto[v,w]:adj[u]) {
                if(d[v]>d[u]+w) {
                    d[v]=d[u]+w;
                    pq.push({d[v],v});
                }
            }
        }
    }
    int ans[maxn];
    void solve() {
        int fm=(1<<n);
        for(int i=1; i<=n; ++i) ans[i]=INT_MAX;
        for(int mask=1; mask<fm; ++mask) {
            int cnt=__builtin_popcount(mask);
            vector<int>v;
            int res=0;
            for(int i=0; i<n; ++i) {
                cout << ((1<<i)&mask);
                if((1<<i)&mask) {v.pb(i+1);}
            }
            cout << ' ';
            for(int i=1; i<=p; ++i) {
                dijkstra(s[i]);
                int mn=INT_MAX;
                for(int j:v) {
                    mn=min(mn,d[j]);
                }
                res+=mn;
            }
            ans[cnt]=min(ans[cnt],res);
            cout << mask << ' ' << cnt << ' ' << res << '\n';
        }
        for(int i=1; i<=n; ++i) cout << ans[i] << ' ';
    }
}
long long cost[maxn];
class disjoint_set_union{
    private:
        int p[maxn],sz[maxn];
    public:
        int found(int u) {return (p[u]==u?u:p[u]=found(p[u]));}
        inline void unite(int u, int v, int w) {
            u=found(u),v=found(v);
            if(u==v) return;
            long long t1=1ll*w*sz[u]-cost[u],t2=1ll*w*sz[v]-cost[v];
            
        }
}dsu;
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    file("digital")
    cin >> n >> m >> p;
    for(int i=1; i<=p; ++i) cin >> s[i];
    for(int i=1; i<=m; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].w;adj[e[i].u].pb({e[i].v,e[i].w});adj[e[i].v].pb({e[i].u,e[i].w});
    }
    souprua::solve();
    return 0; 

} 
/**/
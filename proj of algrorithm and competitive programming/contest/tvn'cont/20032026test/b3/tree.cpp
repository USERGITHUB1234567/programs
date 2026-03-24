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
int n,q,p[maxn],st[maxn],en[maxn],timer=0;
vector<int>adj[maxn];
int col[maxn];
bool mk[maxn];
struct fenwick_tree{
    int ft[maxn];
    void update(int i, int v) {
        while(i<=n) {ft[i]+=v;i+=i&-i;}
    }
    int query(int i) {
        int res=0;
        while(i>0) {res+=ft[i];i-=i&-i;}
    }
    void range_upd(int i, int j, int v) {
        if(i<1 || j<1) return;
        update(j,v);if(i-1>=1)update(i-1,-v);
    }
    int range_query(int i, int j) {
        return query(j)-query(i-1);
    }
}fen;
inline void dfs(int u) {
    st[u]=++timer;
    for(int v:adj[u]) {
        if(v==p[u]) continue;
        dfs(v);
    }
    en[u]=timer;
}
inline void child_query(int u) {
    int t=fen.range_query(st[u],st[u]);
    if(t==0) {
        fen.range_upd(st[u],st[u],1);
    } 
    else {
        for(int v:adj[u]) {
            if(v==p[u]) continue;
            fen.range_upd(st[v],st[v],1);
        }
    }
}
inline void subtree_query(int u) {
    //cerr << st[u] << ' ' << en[u] << '\n';
    fen.range_upd(st[u],en[u],-1);
}
int main(int argc, char** argv) {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("tree")
    cin >> n >> q;
    for(int i=2; i<=n; ++i) {cin >> p[i];adj[i].pb(p[i]),adj[p[i]].pb(i);}
    dfs(1);
    // for(int i=1; i<=n; ++i) {
    //     cout << st[i] << ' ' << en[i] << '\n';
    // }
    while(q--) {
        int t,v;cin >> t >> v;
        if(t==1) child_query(v);
        else if(t==2) subtree_query(v);
        else {
            if(fen.range_query(st[v],st[v])>=1) cout << "black\n";
            else cout << "white\n";
        }
    }
    return 0;

} 
/**/
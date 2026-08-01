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
const int block_size=300;
struct query{
    int l,r,lca,id;
    bool operator<(query o) {
        int b=l/block_size,bo=o.l/block_size;
        return (b<bo) || (b==bo && r<o.r);
    }
};
vector<int>adj[maxn],compress;
int n,q,up[maxn][20],logn,tin[maxn],tout[maxn],euler[maxn],timer,depth[maxn],w[maxn],cnt[maxn],cur,ans[maxn];
bool vis[maxn];
inline void dfs(int u, int p) {
    tin[u]=++timer;
    euler[timer]=u;
    up[u][0]=p;
    for(int v:adj[u]) {
        if(v==p) continue;
        depth[v]=depth[u]+1;
        dfs(v,u);
    }
    tout[u]=++timer;
    euler[timer]=u;
}
int lca(int u, int v) {
    if(depth[u]<depth[v]) swap(u,v);
    int diff=depth[u]-depth[v];
    for(int i=logn; i>=0; --i) {
        if(diff&(1<<i)) u=up[u][i];
    }
    if(u==v) return u;
    for(int i=logn; i>=0; --i) {
        if(up[u][i]!=up[v][i]) {
            u=up[u][i];
            v=up[v][i];
        }
    }
    return up[u][0];
}
inline void add(int i) {
    ++cnt[w[i]];
    if(cnt[w[i]]==1) ++cur;
}
inline void rem(int i) {
    --cnt[w[i]];
    if(cnt[w[i]]==0) --cur;
}
inline void toggle(int i) {
    int u=euler[i];
    if(vis[u]) {
        rem(u);
        vis[u]=false;
    }
    else {
        add(u);
        vis[u]=true;
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> q;
    for(int i=1; i<=n; ++i) {cin >> w[i];compress.pb(w[i]);}
    sortunique(compress);
    for(int i=1; i<=n; ++i) w[i]=lower_bound(all(compress),w[i])-compress.begin();
    for(int i=1,u,v; i<n; ++i) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    logn=log2(n);
    for(int j=1; j<=logn; ++j) {
        for(int i=1; i<=n; ++i) up[i][j]=up[up[i][j-1]][j-1];
    }
    vector<query>queries;
    for(int i=1,u,v; i<=q; ++i) {
        cin >> u >> v;
        if(tin[u]>tin[v]) swap(u,v);
        int anc=lca(u,v);
        if(anc==u) queries.pb({tin[u],tin[v],0,i});
        else queries.pb({tout[u],tin[v],anc,i});
    }
    int ql=1,qr=0;
    sort(all(queries),[&](query a, query b){return a<b;});
    for(int i=0; i<queries.size(); ++i) {
        auto [l,r,anc,id]=queries[i];
        while(ql<l) toggle(ql++);
        while(ql>l) toggle(--ql);
        while(qr<r) toggle(++qr);
        while(qr>r) toggle(qr--);
        ans[id]=cur;
        if(anc!=0) ans[id]+=(!cnt[w[anc]]);
    }
    for(int i=1; i<=q; ++i) cout << ans[i] << '\n';
    //for(int i=1; i<=n<<1; ++i) cout << euler[i] << " ";
    return 0;
}
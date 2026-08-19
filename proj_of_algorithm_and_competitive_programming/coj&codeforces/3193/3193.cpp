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
mt19937_64 generator1(steady_clock::now().time_since_epoch().count());
mt19937_64 generator2(high_resolution_clock::now().time_since_epoch().count());
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);}
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);}
vector<int>adj[maxn],g[maxn];
int n,k,up[maxn][20],d[maxn],logn,ans=0,f[maxn][2];
pair<int,int>cave[maxn];
bool cat[maxn];
/*
xet 2th dist(a,b) chan le->tim mid point
trong th chan co 1, le co 2
f[u][0] so dinh phu nho nhat cho cay con goc u voi dinh u khong duoc phu
f[u][1] ................................................. duoc phu
*/
namespace soupfull {
    // xac dinh midpoint cua moi con chuot
    // dinh goc cho cay tai mot nut bat ki
    bool vis[maxn];
    inline void dfs(int u, int p) {
        for(int v:adj[u]) {
            if(v==p) continue;
            up[v][0]=u;
            d[v]=d[u]+1;
            dfs(v,u);
        }
    }
    inline int lca(int u, int v) {
        if(d[u]<d[v]) swap(u,v);
        for(int i=logn; i>=0; --i) if(d[up[u][i]]>=d[v]) u=up[u][i];
        if(u==v) return u;
        for(int i=logn; i>=0; --i) {
            if(up[u][i]!=up[v][i]) {u=up[u][i],v=up[v][i];}
        }
        return up[u][0];
    }
    inline int kjump(int u, int k) {
        int lg=log(2,k);
        for(int i=lg; i>=0; --i) {
            if(k&(1<<i)) u=up[u][i];
        }
        return u;
    }
    inline pair<int,int>query(int u, int v) {
        int dist=d[u]+d[v]-2*d[lca(u,v)];
        //cout << dist << ' ';
        if(d[u]<d[v]) swap(u,v);
        int a=kjump(u,dist/2);
        //cout << a << ' ';
        if(!(dist&1)) {return {a,-1};}
        else {return {a,up[a][0]};}
    }
    inline int cal(int u, int p, bool choose) {
        vis[u]=true;
        if(f[u][choose]!=-1) return f[u][choose];
        if(!choose) {
            int sum=0;
            for(int v:g[u]) if(v!=p)sum+=cal(v,u,1);
            f[u][0]=sum;
            return sum;
        }
        else {
            int sum=1;
            for(int v:g[u]) if(v!=p)sum+=min(cal(v,u,0),cal(v,u,1));
            f[u][1]=sum;
            return sum;
        }
    }
    inline void solve() {
        cin >> n >> k;
        memset(f,-1,sizeof(f));
        for(int i=1,u,v; i<n; ++i) {cin >> u >> v;adj[u].pb(v),adj[v].pb(u);}
        dfs(0,-1);
        set<pair<int,int>>edge;
        logn=log(2,n);
        for(int j=1; j<=logn; ++j) for(int i=0; i<n; ++i) up[i][j]=up[up[i][j-1]][j-1];
        // dfs(0,-1)->d,up
        for(int i=1,x,y; i<=k; ++i) {
            //cin >> cave[i].fi >> cave[i].se;
            cin >> x >> y;
            pair<int,int>midp={-1,-1};
            midp=query(x,y);
            if(midp.se==-1) cat[midp.fi]=true;
            else {
                if(midp.fi>midp.se) swap(midp.fi,midp.se);
                edge.insert(midp);
            }
            //cout << midp.fi << ' ' << midp.se << '\n';
        }
        for(int i=0; i<n; ++i) if(cat[i]) ++ans;
        for(auto[x,y]:edge) {if(cat[x] || cat[y])continue;g[x].pb(y),g[y].pb(x);}
        for(int i=0; i<n; ++i) if(!vis[i] && !cat[i]) ans+=min(cal(i,-1,0),cal(i,-1,1));
        cout << ans;
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    auto imp_st=high_resolution_clock::now();
    file("3193")
    soupfull::solve();
    auto imp_en=high_resolution_clock::now();
    cerr << "Implementation Time: "<< duration_cast<milliseconds>(imp_en-imp_st).count() << " ms\n";
    return 0;
}
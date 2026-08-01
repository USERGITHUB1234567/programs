/**/ 
#pragma GCC optimize("O3","Ofast","unroll-loops") 
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
namespace utilities{ 
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
    inline int lomuto_partition(vector<int>&a, int l, int r) {int pivot=a[r],i=l-1;for(int j=l; j<r; ++j) {if(a[j]<=pivot) {++i;swap(a[i],a[j]);}}swap(a[r],a[i+1]);return i+1;} 
    inline int hoare_partition(vector<int>&a, int l, int r) {int pivot=a[l],i=l,j=r;bool partition=true;while(partition) {while(a[i]<pivot) ++i;while(a[j]>pivot) --j;if(i<j) {swap(a[i],a[j]);++i,--j;}else partition=false;}return j;} 
    inline void quicksort_lomuto(vector<int>&a, int l, int r) {if(l>=r) return;int p=lomuto_partition(a,l,r);quicksort_lomuto(a,l,p-1);quicksort_lomuto(a,p+1,r);} 
    inline void quicksort_hoare(vector<int>&a, int l, int r) {if(l>=r) return;int p=hoare_partition(a,l,r);quicksort_hoare(a,l,p);quicksort_hoare(a,p+1,r);} 
} 
//using namespace utilities; 
mt19937_64 generator1(steady_clock::now().time_since_epoch().count()); 
mt19937_64 generator2(high_resolution_clock::now().time_since_epoch().count()); 
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);} 
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);} 
auto imp_st=high_resolution_clock::now(); 
inline void start_timer() {imp_st=high_resolution_clock::now();} 
inline void get_execution_time() { auto imp_en=high_resolution_clock::now(); cerr << "Implementation Time: "<< duration_cast<milliseconds>(imp_en-imp_st).count() << " ms\n"; } 
int n,m,q,low[maxn],num[maxn],ncomp=0,timer=0,comp[maxn],dep[maxn],up[maxn][20],logn;
vector<pair<int,int>>adj[maxn];
vector<int>tree[maxn];
bool bridge[maxn];
pair<int,int>edge[maxn];
inline void dfs(int u, int p) {
    num[u]=low[u]=++timer;
    for(auto[v,i]:adj[u]) {
        if(v==p) continue;
        if(num[v]) low[u]=min(low[u],num[v]);
        else {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>num[u]) bridge[i]=true;
        }
    }
}
inline void dfs1(int u) {
    comp[u]=ncomp;
    for(auto[v,i]:adj[u]) {
        if(!bridge[i] && !comp[v]) dfs1(v);
    }
}
inline void dfslca(int u, int p) {
    for(int v:tree[u]) {
        if(v==p) continue;
        up[v][0]=u;
        dep[v]=dep[u]+1;
        dfslca(v,u);
    }
}
inline int lca(int u, int v) {
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=logn; i>=0; --i) {
        if(dep[up[u][i]]>=dep[v]) u=up[u][i];
    }
    if(u==v) return u;
    for(int i=logn; i>=0; --i) {
        if(up[u][i]!=up[v][i]) u=up[u][i],v=up[v][i];
    }
    return up[u][0];
}
inline int dist(int u, int v) {return dep[u]+dep[v]-(dep[lca(u,v)]<<1);}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> n >> m >> q;
    for(int i=1,u,v; i<=m; ++i) {
        cin >> u >> v;
        adj[u].pb({v,i});
        adj[v].pb({u,i});
        edge[i]={u,v};
    }
    dfs(1,0);
    for(int i=1; i<=n; ++i) {
        if(!comp[i]) {++ncomp;dfs1(i);}
    }
    for(int i=1; i<=m; ++i) {
        if(bridge[i]) {
            auto[u,v]=edge[i];
            u=comp[u],v=comp[v];
            tree[u].pb(v);
            tree[v].pb(u);
        }
    }
    dfslca(1,0);
    logn=log2(n)+1;
    for(int j=1; j<=logn; ++j) {
        for(int i=1; i<=n; ++i) up[i][j]=up[up[i][j-1]][j-1];
    }
    while(q--) {
        int a,b,c,d;cin >> a >> b >> c >> d;
        a=comp[a],b=comp[b],c=comp[c],d=comp[d];
        if(a==b) {cout << dist(c,d) << '\n';continue;}
        int l[4]={lca(a,c),lca(a,d),lca(b,c),lca(b,d)};
        sort(l,l+4,[](int u, int v) {return dep[u]<dep[v];});
        int l1=l[2],l2=l[3],inter=0,ans=dist(c,d);
        if(dep[l1]>=max(dep[lca(a,b)],dep[lca(c,d)])) inter=dist(l1,l2);
        cout << ans-inter << '\n';
    }
    return 0; 

} 
/**/
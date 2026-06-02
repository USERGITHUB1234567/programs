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
const int INF = 1000000000;
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
struct edge{int u,v,w;}ed[maxn];
int n,m,q,up[maxn][20],d[maxn],mn[maxn][20],logn;
vector<pair<int,int>>adj[maxn];
void dfs(int u, int p, int w0) {
    up[u][0]=p;
    mn[u][0]=w0;
    for(auto [v,w]:adj[u]) {
        if(v==p) continue;
        d[v]=d[u]+1;
        dfs(v,u,w);
    }
}
class disjoint_set_union{
    private:
        int p[maxn];
    public:
        disjoint_set_union(int size) {
            for(int i=1; i<=size; ++i) p[i]=i;
        }
        bool check(int u, int v) {return root(u)==root(v);}
        int root(int x) {
            if(p[x]!=x) p[x]=root(p[x]);
            return p[x];
        }
        void unite(int x, int y) {
            x=root(x), y=root(y);
            if(x!=y) p[x]=y;
        }
};
int lca(int u, int v) {
    if(d[u]<d[v]) swap(u,v);
    int res=INF;
    int diff=d[u]-d[v];
    for(int i=0; diff; ++i) {
        if(diff&1) {
            res=min(res,mn[u][i]);
            u=up[u][i];
        }
        diff>>=1;
    }
    if(u==v) return res==INF?0:res;
    for(int i=logn; i>=0; --i) {
        if(up[u][i]!=up[v][i]) {
            res=min({res,mn[u][i],mn[v][i]});
            u=up[u][i]; v=up[v][i];
        }
    }
    res=min({res,mn[u][0],mn[v][0]});
    return res==INF?0:res;
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> n >> m;
    for(int i=1; i<=m; ++i) cin >> ed[i].u >> ed[i].v >> ed[i].w;
    sort(ed+1, ed+m+1, [](const edge &a, const edge &b) {return a.w>b.w;});
    disjoint_set_union dsu(n);
    for(int i=1; i<=m; ++i) {
        int u=ed[i].u, v=ed[i].v, w=ed[i].w;
        if(!dsu.check(u,v)) {
            dsu.unite(u,v);
            adj[u].emplace_back(v,w);
            adj[v].emplace_back(u,w);
        }
    }
    for(int i=1; i<=n; ++i) {
        d[i]=-1;
        for(int j=0; j<20; ++j) {
            up[i][j]=0;
            mn[i][j]=INF;
        }
    }
    d[0]=0;dfs(1,0,INF);
    logn=log2(n)+1;
    for(int j=1; j<=logn; ++j) {
        for(int i=1; i<=n; ++i) {
            up[i][j]=up[up[i][j-1]][j-1];
            mn[i][j]=min(mn[i][j-1],mn[up[i][j-1]][j-1]);
        }
    }
    cin >> q;
    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u,v) << "\n";
    }
    return 0; 

} 
/**/
/*
4 5
1 2 10
2 4 1
1 3 5
3 4 3
1 4 2
3
1 4
1 2
2 3
*/
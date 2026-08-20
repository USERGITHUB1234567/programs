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
int n,m,q,nxt[maxn];
long long w[maxn],c[maxn],ans[maxn];
pair<int,int>edge[maxn];
bool mk[maxn];
multiset<long long>ms;
struct query{char c;int i,k;long long pv;}qu[maxn];
class disjoint_sets_union {
    private:
        int p[maxn];
        
    public:
        long long sz[maxn];
        disjoint_sets_union() {for(int i=1; i<maxn; ++i) p[i]=i;}
        inline int root(int u) {return p[u]==u?u:p[u]=root(p[u]);}
        inline void unite(int u, int v) {
            u=root(u),v=root(v);
            if(u==v) return;
            ms.erase(ms.find(sz[u]));
            ms.erase(ms.find(sz[v]));
            if(sz[u]<sz[v]) swap(u,v);
            p[v]=u;
            sz[u]+=sz[v];
            ms.insert(sz[u]);
        }
        inline void update(int u, int k) {
            u=root(u);
            ms.erase(ms.find(sz[u]));
            sz[u]+=k;
            ms.insert(sz[u]);
        }
}dsu;
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> n >> m >> q;
    for(int i=1; i<=n; ++i) {cin >> w[i];c[i]=w[i];}
    for(int i=1,u,v; i<=m; ++i) {
        cin >> u >> v;
        //if(u>v) swap(u,v);
        edge[i]={u,v};
        mk[i]=true;
        //ump[{u,v}]=true;
    }
    int cur=0,it=-1;
    for(int i=1; i<=q; ++i) {
        //cin >> query[i].fi >> query[i].se.fi >> query[i].se.se;
        cin >> qu[i].c;
        if(qu[i].c=='D') {cin >> qu[i].i;mk[qu[i].i]=false;}
        else {
            cin >> qu[i].i >> qu[i].k;
            qu[i].pv=c[qu[i].i];
            c[qu[i].i]=qu[i].k;
        }
    }
    long long mx=0;
    for(int i=1; i<=n; ++i) {dsu.sz[i]=c[i];ms.insert(c[i]);}
    for(int i=1; i<=m; ++i) {
        if(mk[i]) dsu.unite(edge[i].fi,edge[i].se);
    }
    for(int i=q; i>=1; --i) {
        ans[i]=*ms.rbegin();
        auto[ch,j,k,pv]=qu[i];
        if(ch=='C') {
            //cout << mx << '\n';
            //ans[i]=mx;
            dsu.update(qu[i].i,qu[i].pv-qu[i].k);
        }else {
            //cout << mx << '\n';
            //ans[i]=mx;
            dsu.unite(edge[j].fi,edge[j].se);
        }
        
    }
    for(int i=1; i<=q; ++i) cout << ans[i] << '\n';
    return 0; 

} 
/**/
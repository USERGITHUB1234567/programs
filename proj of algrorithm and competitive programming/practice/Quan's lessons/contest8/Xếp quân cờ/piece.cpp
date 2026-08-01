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
int tc;
class disjoint_set_union{
    private:
        int n;
        vector<int>lab;
    public:
        disjoint_set_union(int _n) {init(_n);}
        inline void init(int _n) {
            n=_n;
            lab.assign(n+1,-1);
        }
        inline int root(int u) {return lab[u]<0?u:lab[u]=root(lab[u]);}
        inline void unite(int u, int v) {
            u=root(u),v=root(v);
            if(u!=v) {
                if(lab[u]>lab[v]) swap(u,v);
                lab[u]+=lab[v];
                lab[v]=u;
            }
        }
};
struct edge{int u,v;};
void solve() {
    int n,m;cin >> n >> m;
    disjoint_set_union dsux(n),dsuy(n);
    vector<edge>xe,ye;
    for(int i=1,u,v; i<=m; ++i) {
        char t;cin >> u >> t >> v;
        switch(t) {
            case('l'):
                dsuy.unite(u,v);
                xe.pb({u,v});
                break;
            case('r'):
                dsuy.unite(u,v);
                xe.pb({v,u});
                break;
            case('d'):
                dsux.unite(u,v);
                ye.pb({u,v});
                break;
            case('u'):
                dsux.unite(u,v);
                ye.pb({v,u});
                break;
        }
    }
    vector<int>adjx[n+1];
    vector<int>inx(n+1,0);
    for(auto e:xe) {
        int ru=dsux.root(e.u),rv=dsux.root(e.v);
        if(ru==rv) {cout << "NO\n";return;}
        adjx[ru].pb(rv);
        ++inx[rv];
    }
    vector<int>adjy[n+1];
    vector<int>iny(n+1,0);
    for(auto e:ye) {
        int ru=dsuy.root(e.u),rv=dsuy.root(e.v);
        if(ru==rv) {cout << "NO\n";return;}
        adjy[ru].pb(rv);
        ++iny[rv];
    }
    queue<int>qx;
    vector<int>valx(n+1,1);
    int cntx=0,rtx=0;
    for(int i=1; i<=n; ++i) {
        if(dsux.root(i)==i) {
            ++rtx;
            if(!inx[i]) qx.push(i);
        }
    }
    while(!qx.empty()) {
        int u=qx.front();
        qx.pop();
        ++cntx;
        for(int v:adjx[u]) {
            valx[v]=max(valx[u]+1,valx[v]);
            --inx[v];
            if(!inx[v]) qx.push(v);
        }
    }
    if(cntx<rtx) {cout << "NO\n";return;}
    queue<int>qy;
    vector<int>valy(n+1,1);
    int cnty=0,rty=0;
    for(int i=1; i<=n; ++i) {
        if(dsuy.root(i)==i) {
            ++rty;
            if(!iny[i]) qy.push(i);
        }
    }
    while(!qy.empty()) {
        int u=qy.front();qy.pop();
        ++cnty;
        for(int v:adjy[u]) {
            valy[v]=max(valy[v],valy[u]+1);
            --iny[v];
            if(!iny[v]) qy.push(v);
        }
    }
    if(cnty<rty) {cout << "NO\n";return;}
    cout << "YES\n";
    for(int i=1; i<=n; ++i) {
        cout << valx[dsux.root(i)] << ' ' << valy[dsuy.root(i)] << '\n';
    }
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> tc;
    while(tc--) {
        solve();
    }
    return 0; 

} 
/**/
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
int n,m,c[22];
struct port{int t,x,d;}p[22];
namespace souprua{
    void solve() {
        for(int i=1; i<=m; ++i) {
            cout << -1 << '\n';
        }
    }
}
namespace souptrau1{
    vector<int>adj[maxn];
    set<int>tin[22];
    void bfs() {
        for(int i=0; i<21; ++i) tin[i].insert(0);
        for(int i=0; i<=n; ++i) {
            vector<int>tmp;
            //cerr << tin[i].size() <<  ' ';
            for(int f:tin[i]) tmp.pb(f);
            for(int v:tin[i]) {
                for(int k=1; k<=n; ++k) {
                    auto[t,x,d]=p[k];
                    if(d!=i) continue;
                    int u;
                    if(t==1) u=v+x;
                    else u=(t<<1)%x;
                    //cerr << i << ' ' << v << ' ' << u << '\n';
                    tmp.pb(u);
                }
            }
            for(int f:tmp) {
                tin[i].insert(f);
                tin[i+1].insert(f);
            }
        }
    }
    int ans[100005];
    void solve() {
        for(int i=1; i<=m; ++i) ans[i]=-1;
        bfs();
        for(int i=0; i<=n; ++i) {
            for(int j:tin[i]) {
                if(ans[j]==-1) ans[j]=i;
                //cout << j << ' ';
            }
            //cout << '\n';
        }
        
        for(int i=1; i<=m; ++i) cout << ans[i] << '\n';
    }
}
namespace souptrau2{

}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    file("hanhlang")
    //for(int i=0; i<=100; ++i) cout << (i<<1)%16 << '\n';
    cin >> n >> m;
    bool cks1=true;
    for(int i=1; i<=n; ++i) {cin >> c[i];if(c[i]!=1)cks1=false;}
    for(int i=1; i<=n; ++i) {cin >> p[i].t >> p[i].x >> p[i].d;}
    if(cks1)souptrau1::solve();
    else souprua::solve();
    return 0; 

} 
/**/
/*
6 7
1 2 3 1 2 2
1 5 1
2 7 2
1 3 2
2 1 2
1 1 3
2 3 6


*/
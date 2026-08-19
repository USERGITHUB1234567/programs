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
const int maxn=1003,mod=1000000007,maxb=320; 
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
namespace solver{
    bool f[2][maxn][115];
    int base=55,mxv=115;
    inline void solve(int& n, int& h, int& w,vector<int>&x, vector<int>&s, vector<int>e) {
        vector<pair<int,int>>barrier(n,{0,h-1});
        for(int i=0; i<w; ++i) {barrier[x[i]]={s[i],e[i]};}
        int ch=(h>>1);
        memset(f,false,sizeof(f));
        f[0][ch][base]=true;
        int lim=sqrt(h);
        for(int i=0; i<n-1; ++i) {
            int cur=i&1,nxt=(cur+1)&1;
            for(int j=0; j<h; ++j) {
                for(int v=0; v<=mxv; ++v) {
                    f[nxt][j][v]=false;
                }
            }
            for(int j=0; j<h; ++j) {
                if(j>barrier[i].se || j<barrier[i].fi) continue;
                for(int v=0; v<=93; ++v) {
                    if(!f[cur][j][v]) continue;
                    int rv=v-base;
                    //cerr << i << ' ' << j << ' ' << v << ' ' << f[i][j][v] << '\n';
                    if(j+rv>=0 && j+rv<h && j+rv>=barrier[i+1].fi && j+rv<=barrier[i+1].se) f[nxt][j+rv][v]=true;
                    if(j+rv+1>=0 && j+rv+1<h && j+rv+1>=barrier[i+1].fi && j+rv+1<=barrier[i+1].se) f[nxt][j+rv+1][v+1]=true;
                    if(j+rv-1>=0 && j+rv-1<h && j+rv-1>=barrier[i+1].fi && j+rv-1<=barrier[i+1].se) f[nxt][j+rv-1][v-1]=true;
                }
            }
        }
        bool ck=false,l=(n-1)&1;
        for(int i=0; i<h; ++i) {
            for(int v=0; v<=93; ++v) if(f[l][i][v]) {ck=true;break;}
            if(ck) break;
        }
        cout << (ck?"YES":"NO") << '\n';
    }
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> tc;
    while(tc--) {
        int n,h,w;cin >> n >> h >> w;
        vector<int>x,s,e;
        x.reserve(w),s.reserve(w),e.reserve(w);
        for(int i=1,v; i<=w; ++i) {cin >> v;x.pb(v);}
        for(int i=1,v; i<=w; ++i) {cin >> v;s.pb(v);}
        for(int i=1,v; i<=w; ++i) {cin >> v,e.pb(v);}
        solver::solve(n,h,w,x,s,e);
    }
    return 0; 

} 
/**/
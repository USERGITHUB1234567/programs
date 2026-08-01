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
const int maxn=2003,mod=1000000007,maxb=320; 

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

mt19937_64 generator1(steady_clock::now().time_since_epoch().count()); 
mt19937_64 generator2(high_resolution_clock::now().time_since_epoch().count()); 
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);} 
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);} 

int n,x,y;
vector<pair<int,int>>jelly;
const int inf=INT_MAX>>1;

namespace soupfull{
    int pre[maxn][10004],suf[maxn][10004];
    
    void solve() {
        // Tie-breaker: If B costs are equal, prioritize higher A cost to dump cheaper A items into suffix
        sort(all(jelly),[](const pair<int,int>& a, const pair<int,int>& b){
            if (a.se != b.se) return a.se < b.se;
            return a.fi > b.fi;
        });
        
        for(int i=0; i<=n; ++i) 
            for(int j=0; j<=x; ++j) 
                pre[i][j]=inf;
        
        for(int i=0; i<=x; ++i) pre[0][i]=0;
        
        for(int i=1; i<=n; ++i) {
            auto[a,b]=jelly[i-1];
            for(int j=0; j<=x; ++j) {
                // Buy from store B
                if (pre[i-1][j] != inf) {
                    pre[i][j]=min(pre[i][j], pre[i-1][j]+b);
                }
                // Buy from store A (Fix: Unbounded Knapsack -> 0-1 Knapsack)
                if(j>=a && pre[i-1][j-a] != inf) {
                    pre[i][j]=min(pre[i][j], pre[i-1][j-a]);
                }
            }
            for(int j=1; j<=x; ++j) {
                pre[i][j]=min(pre[i][j],pre[i][j-1]);
            }
        }
        
        // Fix: Suffix should be calculated using Store A's budget and items (bounds changed to x and used 'a')
        for(int i=0; i<=n; ++i) 
            for(int j=0; j<=x; ++j) 
                suf[i][j]=0;
                
        for(int i=n-1; i>=0; --i) {
            auto[a,b]=jelly[i];
            for(int j=0; j<=x; ++j) {
                suf[i][j] = suf[i+1][j];
                // Fix: 0-1 Knapsack using 'a' instead of 'b'
                if(j>=a) {
                    suf[i][j]=max(suf[i][j], suf[i+1][j-a]+1);
                }
            }
        }
        
        int ans=0;
        for(int i=0; i<=n; ++i) {
            for(int j=0; j<=x; ++j) {
                if(y>=pre[i][j]) {
                    // Fix: Passing Store A's remaining budget `x - j` to `suf`
                    ans=max(ans, i + suf[i][x-j]);
                }
            }
        }
        cout << ans << "\n";
    }
}

int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    if (!(cin >> n >> x >> y)) return 0;
    
    jelly.reserve(n);
    for(int i=1,u,v; i<=n; ++i) {
        cin >> u >> v;
        jelly.pb({u,v});
    }
    soupfull::solve();
    
    return 0; 
} 
/**/
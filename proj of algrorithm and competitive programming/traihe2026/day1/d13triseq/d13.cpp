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
#define int long long
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
int n,t;
vector<int>a;
vector<vector<int>>ans;

namespace soup1{
    inline void backtrack(int g, vector<int>&cur, int mn1=1e9, int mn2=1e9, int mx=-1e9) {
        if(g>n) {
            ans.pb(cur);
            return;
        }
        for(int i=1; i<=n; ++i) {
            int nmn1=mn1,nmn2=mn2,nmx=mx;
            if(i<=nmn1) {nmn2=nmn1;nmn1=i; }
            else if(i<nmn2) {nmn2=i;}
            if(i>nmx) {nmx=i;}
            if(nmn2!=1e9 && nmn1+nmn2<=nmx) continue;
            cur[g-1]=i;
            backtrack(g+1, cur, nmn1, nmn2, nmx);
        }
    }
    void solve() {
        vector<int>b(n);
        backtrack(1,b);
        cout << ans.size() << '\n';
        //sort(all(ans));
        for(int i:ans[t-1]) cout << i << ' ';
        cout << '\n';
        cout << lower_bound(all(ans),a)-ans.begin()+1;
    }
}
namespace soupfull{
    int ans[20];
    long long f[20][20][20][20];
    void upd(int &mn1, int &mn2, int&mx, int x) {
        if(x<mn1) {mn2=mn1;mn1=x;}
        else if(x<mn2) {mn2=x;}
        mx=max(mx,x);
    }
    long long process(int id, int mn1, int mn2, int mx) {
        if(id==n+1) return mn1+mn2>mx;
        if(f[id][mn1][mn2][mx]!=-1) return f[id][mn1][mn2][mx];
        long long res=0;
        for(int x=1; x<=n; ++x) {
            int nmn1=mn1,nmn2=mn2,nmx=mx;
            upd(nmn1,nmn2,nmx,x);
            res+=process(id+1,nmn1,nmn2,nmx);
        }
        return f[id][mn1][mn2][mx]=res;
    }
    void solve() {
        memset(f,-1,sizeof(f));
        int mn1=n+1,mn2=n+1,mx=0;
        for(int i=1; i<=n; ++i) {
            for(int x=1; x<=n; ++x) {
                int nmn1=mn1,nmn2=mn2,nmx=mx;
                upd(nmn1,nmn2,nmx,x);
                long long k=process(i+1,nmn1,nmn2,nmx);
                if(t>k) t-=k;
                else {ans[i]=x;mn1=nmn1,mn2=nmn2,mx=nmx;break;}
            }
        }
        long long rnk=1;
        mn1=n+1,mn2=n+1,mx=0;
        //memset(f,-1,sizeof(f));
        for(int i=1; i<=n; ++i) {
            for(int x=1; x<a[i]; ++x) {
                int nmn1=mn1,nmn2=mn2,nmx=mx;
                upd(nmn1,nmn2,nmx,x);
                rnk+=process(i+1,nmn1,nmn2,nmx);
            }
            upd(mn1,mn2,mx,a[i]);
        }
        //memset(f,-1,sizeof(f));
        cout << process(1,n+1,n+1,0) << '\n';
        for(int i=1; i<=n; ++i) cout << ans[i] << ' ';
        cout << '\n' << rnk;
    }
}
signed main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> n >> t;
    a.resize(n+1);
    for(int i=1; i<=n; ++i) cin >> a[i];
    soupfull::solve();
    //get_execution_time();
    return 0; 
} 
/**/
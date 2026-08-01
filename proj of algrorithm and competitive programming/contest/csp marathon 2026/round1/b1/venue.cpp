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
const int maxn=1000006,mod=1000000007,maxb=320; 
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
int n,m,a[maxn];
namespace soup1{
    inline int dist(int x, int i) {
        int j=a[i];
        if(x>j) swap(x,j);
        return min(j-x,m-j+x);
    }
    int f(int x) {
        int res=0;
        for(int i=1; i<=n; ++i) {
            res=max(res,dist(x,i));
        }
        return res;
    }
    void solve() {
        int mn=INT_MAX,res;
        for(int i=1; i<=m; ++i) {
            //cout << f(i) << ' ';
            if(f(i)<mn) {
                mn=f(i);
                res=i;
            }
        }
        //cout << '\n';
        cout << mn << ' ' << res;
        //cout << '\n' << f(34);
    }
}
namespace soupfull{
    inline int clocwise_dist(int i, int j) {
        int x=a[i],y=a[j];
        if(x<=y) return y-x;
        else return m-x+y;
    }
    inline int getans(int i, int j, int d) {
        int x=a[i],y=a[j];
        swap(x,y);
        int res;
        if(x<y) res=x+d;
        else res=x+d;
        if(res>m) res-=m;
        return res;
    }
    void solve() {
        sort(a+1,a+1+n);
        int ans=INT_MAX,p;
        for(int i=1; i<=n; ++i) {
            int j=(i+1<=n?i+1:1);
            int d=clocwise_dist(i,j)-1,rd=(m-d)>>1;
            //cout << d << ' ' << rd << '\n';
            //ans=min(ans,rd);
            if(rd<ans) {
                ans=rd;
                p=getans(i,j,rd);
            }
        }
        cout << ans << ' ' << p;
    }
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    file("venue")
    cin >> n >> m;for(int i=1; i<=n; ++i) cin >> a[i];
    if(n<=1000 && m<=1000)soup1::solve();
    //cout << '\n';
    else soupfull::solve();
    return 0; 

} 
/**/
/*
4 18
12 3 9 5

8 13
11 8 3 13 6 10 12 7

10 27
1 8 19 23 17 26 4 9 24 5

12 39
4 8 2 7 5 12 35 28 9 14 27 28
*/
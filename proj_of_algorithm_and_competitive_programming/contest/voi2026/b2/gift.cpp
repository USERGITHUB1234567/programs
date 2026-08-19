/**/ 
#pragma GCC optimize("O3","Ofast") 
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
int n,q;
struct gift{long long w,s;}g[maxn];
struct query{int type,m,k,t;}queries[maxn];
class segmentree{

};
namespace soup1{
    long long pre_s[maxn],pre_w[maxn];
    void solve() {
        sort(g+1,g+1+n,[&](gift a,gift b){return a.w<b.w;});
        for(int i=1; i<=n; ++i) {
            pre_s[i]=pre_s[i-1]+g[i].s;
            pre_w[i]=pre_w[i-1]+g[i].w;
        }
        for(int tc=1; tc<=q; ++tc) {
            auto[type,m,k,t]=queries[tc];
            if(type==2) {
                if(m<pre_w[1]) cout << 0 << '\n';
                else {
                    int l=1,r=n;
                    while(l<r) {
                        int mid=(l+r+1)>>1;
                        //cerr << mid;
                        if(pre_w[mid]>m) r=mid-1;
                        else l=mid;
                    }
                    //long long sum=pre_s[l];
                    cout << l/k << '\n';
                }
            } else {
                if(n<t*k || pre_w[t*k]>m) cout << 0 << '\n';
                else cout << 1 << '\n';
            }
        }
    }
}
namespace soup2and3{
    inline bool check(long long m, long long k, long long t) {
        long long need=t*k,take=0,sum=0;
        for(int i=1; i<=n; ++i) {
            long long t1=min(g[i].s,t),t2=min(t1,need-take);
            take+=t2;
            sum+=g[i].w*t2;
            //cerr << sum << ' ' << m << ' ' << k << ' ' << t << '\n';
            if(sum>m) return false;
            if(take==need) return true;
        }
        return take>=need;
    }
    inline long long f(long long m, long long k) {
        long long l=0,r=1e9;
        while(l<r) {
            int mid=(l+r+1)>>1;
            //cerr << mid;
            if(check(m,k,mid)) l=mid;
            else r=mid-1; 
        }
        return l;
    }
    void solve() {
        sort(g+1,g+1+n,[&](gift a,gift b){return a.w<b.w;});
        for(int tc=1; tc<=q; ++tc) {
            auto[type,m,k,t]=queries[tc];
            if(type==1) cout << check(m,k,t) << '\n';
            else cout << f(m,k) << '\n';
        }
    }
}
struct fenwick_tree{
    vector<long long>bit;
    int n;
    fenwick_tree(int _n):n(_n) {bit.resize(n+1);}
    inline void update(int i, long long v) {
        while(i<=n) {
            bit[i]+=v;
            i+=i&-i;
        }
    }
    inline long long sum(int i) {
        long long res=0;
        while(i) {
            res+=bit[i];
            i-=i&-i;
        }
        return res;
    }
};
namespace soupfull{
    inline int findSmallestWeight() {
        
    }
    inline bool check() {

    }
    void solve() {
        fenwick_tree smallCnt(n),smallSum(n),bigCnt(n),bigSum(n);

    }
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    file("gift")
    bool cks1=true;
    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> g[i].w;
    for(int i=1; i<=n; ++i) {cin >> g[i].s;if(g[i].s!=1)cks1=false;}
    for(int i=1; i<=q; ++i) {
        cin >> queries[i].type;
        if(queries[i].type==2) cin >> queries[i].m >> queries[i].k;
        else cin >> queries[i].m >> queries[i].k >> queries[i].t;
    }
    
    if(cks1)soup1::solve();
    else soup2and3::solve();
    return 0; 

} 
/*
5 3
8 3 4 10 8
5 8 2 9 10
1 19 3 2
2 19 3
2 9 1
*/
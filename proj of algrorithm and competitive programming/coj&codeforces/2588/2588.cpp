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
namespace mathematics{ 
    long long fact[maxn],ifact[maxn]; 
    long long __gcd(long long a, long long b) { if(a<b) swap(a,b); while(a%b!=0) {long long c=a%b;a=b,b=c;} return b; } 
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
} 
using namespace mathematics; 
mt19937_64 generator1(steady_clock::now().time_since_epoch().count()); 
mt19937_64 generator2(high_resolution_clock::now().time_since_epoch().count()); 
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);} 
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);} 
auto imp_st=high_resolution_clock::now(); 
inline void start_timer() {imp_st=high_resolution_clock::now();} 
inline void get_execution_time() { auto imp_en=high_resolution_clock::now(); cerr << "Implementation Time: "<< duration_cast<milliseconds>(imp_en-imp_st).count() << " ms\n"; } 
int n,l,r;
long long a[maxn],k;
struct mark{long long m; int l,r;}mk[maxn];
inline void add(int i, set<long long,greater<long long>>&st) {st.insert(a[i]);}
inline void rem(int i, set<long long,greater<long long>>&st) {st.erase(a[i]);}
inline long long f(set<long long,greater<long long>>&st) {
    int cnt=0;
    long long ans=0;
    for(auto x:st) {
        ++cnt;
        if(cnt>k) ans+=x;
    }
    return ans;
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];
    r=-1,l=-1;
    int cnt=0;
    vector<long long>sum;
    for(int i=n; i>=1; --i) {
        if(r==-1 && a[i]>=0) r=i;
        if(a[i]<0) continue;
        sum.pb(a[i]);
        if(a[i]>=0 && a[i-1]<0) {
            ll s=0;
            sort(all(sum));
            if(sum.size()<k) mk[i].m=LLONG_MIN>>1;
            else {for(int j=0; j<k; ++j) s+=sum[j];mk[i].m=-s;}
            mk[i].l=i,mk[i].r=r;
            r=-1;
            sum.clear();
        }
    }
    if(a[1]>=0) {
        ll s=0;
        sort(all(sum));
        if(sum.size()<k) mk[1].m=LLONG_MIN>>1;
        else {for(int i=0; i<k; ++i) s+=sum[i];mk[1].m=-s;}
        if(r==-1) r=1;
        mk[1].l=1,mk[1].r=r;
        l=-1;
        sum.clear();
        
    }
    r=0,l=0;
    set<long long,greater<long long>>cur;
    for(r=0; r<=k; ++r) {if(r!=0) add(r,cur);}
    long long ans=f(cur);
    long long now=ans;
    for(int i=1; i<=n; ++i) {
        cout << mk[i].m << ' ' << mk[i].l << ' ' << mk[i].r << '\n';
    }
    while(true) {
        int i=r+1;
        now=f(cur);
        ans=max(ans,now);
        cout << r << ' ' << ans << '\n';
        if(now<0 && -mk[i].m<abs(now)) {
            while(r<mk[i].r) add(++r,cur);
            while(l<mk[i].l && r-l-1>=k) rem(l++,cur);
        }else {
            add(++r,cur);
        }
        if(r==n) break;
    }
    cout << ans;
    return 0; 

} 
/**/
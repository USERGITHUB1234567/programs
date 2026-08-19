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
const int maxn=100005,mod=1000000007,maxb=320; 
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
long long n,k1,k2;
namespace soup1{
    void solve() {
        long long ans=0,res=0,kq=0;
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=n; ++j) {
                //if(i==j) continue;
                long long t=i*j;
                if(!(t%6)) {
                    //if(i%6==0 || j%6==0) ++ res;
                    //else {++kq;cout << i << ' ' << j << '\n';}
                    ans=(ans+1)%2026;
                }
            }
        }
        //cout << res << ' ' << ans;
        //k1=ans;
        cout << ans;
    }
}
namespace soupfull{
    void solve() {
        //long long ans=((n-1)*2-1)%2026;
        long long d6=n/6,t6=n*2-1,ans=d6*t6-((d6-1)*d6)/2;
        if(n<6) ans=0;
        //long long ans=n*2-1;
        long long d3=n/3-d6,d2=n/2-d6;
        if(n<3) d3=0;
        if(n<2) d2=0;
        //cout << ans << ' ';
        ans=(ans+d3*d2*2)%2026;
        long long t=d6-1;
        t=(t*(t+1))/2;
        t%=2026;
        ans-=t;
        if(ans<0) ans+=2026;
        //cout << d3 << ' ' << d2 << '\n';
        //k2=ans;
        cout << ans;
    }
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> n;
    // soup1::solve();
    // cout << '\n' << '\n';
    soupfull::solve();
    // for(int i=1; i<=1000; ++i) {
    //     n=i;
    //     soup1::solve();
    //     //cout << '\n';
    //     soupfull::solve();
    //     if(k1!=k2) cout << "wa\n";
    //     else cout << "ac\n";
    //     //cout << "\n\n";
    // }
    return 0; 

} 
/**/
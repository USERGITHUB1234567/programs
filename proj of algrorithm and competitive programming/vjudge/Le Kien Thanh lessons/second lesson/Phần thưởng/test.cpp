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
const int maxn=302,mod=1000000007,maxb=320; 
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
int n,k,a[maxn];
namespace souprua{
    void solve() {
        sort(a+1,a+1+n);
        long long ans=0;
        int i=0;
        while(k--) {
            ans+=a[n-i]-a[i+1];
            ++i;
        }
        cout << ans;
    }
}
namespace soupfull {
    const ll NEG=-4e18;
    static ll f[305][305][155];
    inline ll getf(int l, int r, int t) {
        if (l > r) return (t == 0 ? 0LL : NEG);
        return f[l][r][t];
    }
    void solve() {
        // initialize
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                for (int t = 0; t <= k; ++t)
                    f[i][j][t] = NEG;

        // base: any non-empty interval with 0 pairs -> 0
        for (int l = 1; l <= n; ++l)
            for (int r = l; r <= n; ++r)
                f[l][r][0] = 0;

        for (int len = 1; len <= n; ++len) {
            for (int l = 1; l + len - 1 <= n; ++l) {
                int r = l + len - 1;
                int maxT = min(k, len / 2);
                for (int t = 1; t <= maxT; ++t) {
                    ll &cur = f[l][r][t];
                    // remove one from left or right (no reward)
                    cur = max(cur, getf(l+1, r, t));
                    cur = max(cur, getf(l, r-1, t));

                    // choose two from front (l, l+1)
                    if (l + 1 <= r) {
                        ll base = getf(l+2, r, t-1);
                        if (base != NEG) cur = max(cur, base + llabs((ll)a[l] - (ll)a[l+1]));
                    }

                    // choose two from back (r-1, r)
                    if (r - 1 >= l) {
                        ll base = getf(l, r-2, t-1);
                        if (base != NEG) cur = max(cur, base + llabs((ll)a[r] - (ll)a[r-1]));
                    }

                    // choose one from front and one from back (l, r)
                    if (l <= r) {
                        ll base = getf(l+1, r-1, t-1);
                        if (base != NEG) cur = max(cur, base + llabs((ll)a[l] - (ll)a[r]));
                    }
                }
            }
        }

        ll ans = getf(1, n, k);
        if (ans < 0) ans = 0;
        cout << ans << '\n';
    }
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];
    soupfull::solve();
    return 0; 

} 
/**/
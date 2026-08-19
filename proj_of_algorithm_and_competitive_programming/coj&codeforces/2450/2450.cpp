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
#define mp make_pair
using namespace std;
static const int maxd = 1003;
typedef short bignum[maxd];
typedef long long ll;
typedef long double ld;
const int maxn = 100005, mod=1000000007;
inline int maxi(int a, int b) {return (a>b?a:b);}
inline int mini(int a, int b) {return (a<b?a:b);}
inline ll maxill(ll a, ll b) {return (a>b?a:b);}
inline ll minill(ll a, ll b) {return (a<b?a:b);}
inline double maxid(double a, double b) {return (a>b?a:b);}
inline double minid(double a, double b) {return (a<b?a:b);}
inline ld maxild(ld a, ld b) {return (a>b?a:b);}
inline ld minild(ld a, ld b) {return (a<b?a:b);}
inline ll modexp(ll b, ll e, ll m) {
    ll res=1%m;
    while(e>0) {
        if(e&1) res=(res*b)%m;
        b=(b*b)%m;
        e>>=1;
    }
    return res;
}
long long n,k,a[maxn];
long long fact[maxn],ifact[maxn];
long long ncr(long long k, long long n) {return (k==n?1:fact[n]*ifact[n-k]%mod*ifact[k]%mod);}
namespace soupfull {
    void precompute() {
        fact[0]=1;
        for(int i=1; i<maxn; ++i) fact[i]=fact[i-1]*i%mod;
        int tc=maxn-1;
        ifact[tc]=modexp(fact[tc],mod-2,mod);
        for(int i=tc; i>=1; --i) ifact[i-1]=ifact[i]*i%mod; 
    }
    void solve() {
        precompute();
        long long res=1,cur=n;
        for(int i=i; i<=k; ++i) {
            res=(res*ncr(a[i],cur))%mod;
            cur-=a[i];
        }
        cout << res;
    }
}
void implement() {
    soupfull::solve();
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k;
    for(int i=1; i<=k; ++i) cin >> a[i];
    implement();
    return 0;
}
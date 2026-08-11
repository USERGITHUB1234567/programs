#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define foutput(name) freopen(name, "w", stdout);
#define finput(name) freopen(name,"r", stdin);
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
static const int maxd=1003;
typedef short bignum[maxd];
typedef long long ll;
typedef long double ld;
const int maxn=1000006,mod=1000000007;
long long fact[maxn],ifact[maxn];
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
inline ll log(ll k, ll n){ll res=0;while(n>0){n/=k;++res;}return res;}
void setupfactor() {
    fact[0]=1;
    for(int i=1; i<maxn; ++i) fact[i]=fact[i-1]*i%mod;
    int tc=maxn-1;
    ifact[tc]=modexp(fact[tc],mod-2,mod);
    for(int i=tc; i>=1; --i) ifact[i-1]=ifact[i]*i%mod; 
}
inline long long ncr(long long k, long long n) {return (k==n?1:fact[n]*ifact[n-k]%mod*ifact[k]%mod);}
mt19937_64 generator1(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 generator2(chrono::high_resolution_clock::now().time_since_epoch().count());
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);}
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);}
int n,a[maxn];
inline long long gcd(ll a, ll b) {
    if(a<b) swap(a,b);
    while(b) {
        ll r=a%b;
        a=b;
        b=r;
    }
    return a;
}
namespace soup1{
    void solve() {
        long long kq=0;
        for(int i=1; i<=n; ++i) {
            for(int j=i+1; j<=n; ++j) {
                if(gcd(a[i],a[j])==min(a[i],a[j])) {
                    ++kq;
                    //cout << i << ' ' << j << '\n';
                }
            }
        }
        cout << kq;
    }
}
namespace soup2 {
    vector<int>div[maxn];
    int cnt[maxn];
    inline void snt() {
        for(int i=1; i<maxn; ++i) {
            for(int j=i; j<maxn; j+=i) div[j].pb(i);
        }
    }
    void solve() {
        snt();
        //for(int i=1; i<=n; ++i) ++cnt[a[i]];
        sort(a+1,a+1+n);
        ll kq=0;
        for(int i=1; i<=n; ++i) {
            for(int j:div[a[i]]) kq+=cnt[j];
            ++cnt[a[i]];
        }
        cout << kq;
        /* int m=0;
        for(int i=1; i<=1000000; ++i) {
            m+=(int)div[i].size();
        }
        cout << m; */
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("pairs")
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    /* soup1::solve();
    cout << '\n';
    soup2::solve(); */
    /* soup1::solve();
    cout << '\n';
    soup2::solve(); */
    if(n<=2000) {
        soup1::solve();
        return 0;
    }
    soup2::solve();
    return 0;
}
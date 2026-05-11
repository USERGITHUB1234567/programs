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
const int maxn=300005,mod=1000000000+22071997;
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
int n,q;
long long l[maxn],r[maxn];
namespace souptrau {
    void solve() {
        while(q--) {
            char t;
            cin >> t;
            if(t=='L') {
                int u,v,c;
                cin >> u >> v >> c;
                for(int i=u; u<=v; ++i) l[i]=c;
            }
            else if(t=='R') {
                int u,v,c;
                cin >> u >> v >> c;
                for(int i=u; i<=v; ++i) r[i]=c;
            }
            else {
                int u,v;
                cin >> u >> v;
                long long c0=0,c1=0;
                long long mx=max(*max_element(l+1,l+1+n),*max_element(r+1,r+1+n));
                for(int x=0; x<=mx; ++x) {
                    for(int y=0; y<=mx; ++y) {
                        for(int i=u; i<=v; ++i) {
                            for(int j=i+1; j<=v; ++j) {
                                if(l[i]<=x && x<=r[i] && l[j]<=y && y<=r[j]) {
                                    long long xorr=x^y;
                                    if(__builtin_popcount(xorr)&1) c1=(c1+1)%mod;
                                    else c0=(c0+1)%mod;
                                }
                            }
                        }
                    }
                }
                cout << c0 << ' ' << c1 << "\n";
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("xorpair")
    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> l[i] >> r[i];
    souptrau::solve();
    return 0;
}
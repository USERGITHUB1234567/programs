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
const int maxn=502,mod=1000000007;
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
int n,m;
long long a,b,c[maxn][maxn],pre[maxn][maxn],kq=LLONG_MAX;
namespace soup1 {
    inline long long query(int i, int j,int u, int v) {return pre[u][v]-pre[u][j-1]-pre[i-1][v]+pre[i-1][j-1];}
    void solve() {
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=m; ++j) {
                for(int k=i; k<=n; ++k) {
                    for(int t=j; t<=m; ++t) {
                        long long s=query(i,j,k,t);
                        kq=min((abs(s-a)+abs(s-b)),kq);
                        //printf("%lld\n",abs(s-a)+abs(s-b));
                    }
                }
            }
        }
        cout << kq;
    }
}
namespace soup2 {
    void solve() {
        
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    scanf("%d%d%lld%lld",&n,&m,&a,&b);
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            scanf("%lld",&c[i][j]);
            pre[i][j]=pre[i][j-1]+pre[i-1][j]+c[i][j]-pre[i-1][j-1];
        }
    }
    soup1::solve();
    return 0;
}
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
long long n,x,a[maxn],pre[maxn],kq=0,mi=0,ma=0;
namespace soup1 {
    long long kq=0;
    void solve() {
        for(int i=1; i<=n; ++i) {
            for(int j=i; j<=n; ++j) {
                for(int k=i; k<=j; ++k) a[k]*=x;
                long long s=0;
                for(int t=1; t<=n; ++t) {
                    for(int q=t; q<=n; ++q) {
                        s=0;
                        for(int p=t; p<=q; ++p) {
                            s+=a[p];
                        }
                        kq=max(kq,s);
                    }
                }
                for(int t=1; t<=n; ++t) {
                    for(int q=t; q<=n; ++q) {
                        s=0;
                        for(int p=t; p<=q; ++p) {
                            s+=a[p];
                        }
                        kq=max(kq,s);
                    }
                }
                for(int k=i; k<=j; ++k) a[k]/=x;
            }
        }
        printf("%lld",kq);
    }
}
namespace soup2 {
    void solve() {
        for(int i=1; i<=n; ++i) {
            for(int j=i; j<=n; ++j) {
                long long sum1=0,sum2=0;
                for(int k=1; k<=n; ++k) {
                    sum1=max(sum1+a[k],0LL);
                    kq=max(kq,sum1);
                    if(k>=i && k<=j) a[k]*=x;
                }
                for(int k=1; k<=n; ++k) {
                    sum2=max(sum2+a[k],0LL);
                    kq=max(kq,sum2);
                    if(k>=i && k<=j) a[k]/=x;
                }
            }
        }
        printf("%lld",kq);
    }
}
long long f1[maxn],f2[maxn],f3[maxn];
namespace soupfull {
    void solve() {
        long long kq=0;
        for(int i = 1; i <= n; i++) {
            f1[i] = f2[i] = f3[i] = 0;
        }
        for(int i=2; i<=n; ++i) {
            f1[i]=max(f1[i-1]+a[i],a[i]);
            f2[i]=max({a[i]*x,f2[i-1]+a[i]*x,f1[i-1]+a[i]*x});
            f3[i]=max(f2[i],f3[i-1]+a[i]);
        }
        for(int i = 1; i <= n; i++) kq = max({kq, f1[i], f2[i], f3[i]});
        printf("%lld",kq);
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("flower")
    scanf("%lld%lld",&n,&x);
    for(int i=1; i<=n; ++i) {scanf("%lld",&a[i]);pre[i]=pre[i-1]+a[i];}
    //if(n<=500) soup2::solve();
    /* if(x>=0) {
        for(int i=1; i<=n; ++i) {
            ma=max(ma,(ll)pre[i]);mi=min(mi,(ll)pre[i]);
            kq=max({kq,(ll)(pre[i]-ma)*x,(ll)(pre[i]-mi)*x,pre[i]-mi});
        }
    }
    printf("%d",kq); */
    soupfull::solve();
    return 0;
}
/*
5 2 
-1 2 4 -3 4

5 -3 
-1 2 4 -3 4 
*/
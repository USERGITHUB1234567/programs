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
int n;
long long a[maxn],b[maxn],res=LLONG_MAX;
void soup1() {
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            res=min(res,abs(a[i]+b[j]));
        }
    }
    cout << res;
}
void soupfull() {
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    for(int i=1; i<=n; ++i) {
        int pos=lower_bound(b+1,b+1+n,-a[i])-b;
        res=min(res,(ll)abs(a[i]+b[pos]));
        if(pos>1) res=min(res,(ll)abs(a[i]+b[pos-1]));
    }
    cout << res;
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) cin >> b[i];
    if(n<=1000) {
        soup1();
        return 0;
    }
    soupfull();
    return 0;
}
/*
15
-10 -5 1 3 6 7 8 9 11 13 15 17 19 20 25
5 6 7 8 9 10 11 12 13 14 15 16 17 18 19

20
-10 -5 1 3 6 7 8 9 11 13 15 17 19 20 25 30 35 40 45 50
5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24

10
-3 1 4 -2 2 -1 6 -5 3 7
3 4 -1 5 -4 6 -3 7 -2 8
*/
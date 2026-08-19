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
const int maxn=100005,mod=1000000007;
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
int n,q;
namespace soup1 {
    pair<long long,bool>a[maxn];
    inline void add(int l, int r, long long k) {for(int i=l; i<=r; ++i) a[i].fi+=k;}
    inline void take(int l, int r, long long k) {for(int i=l; i<=r; ++i) a[i].fi=max(a[i].fi-k,0LL);}
    inline void toggle(int l, int r) {for(int i=l; i<=r; ++i) a[i].se^=1;}
    inline void sweep(int l, int r, bool s) {for(int i=l; i<=r; ++i) a[i].se=s;}
    inline long long get(int l, int r) {
        long long res=0;
        for(int i=l; i<=r; ++i) {
            res=(res+(a[i].fi*a[i].se*modexp(2,i,mod)))%mod;
        }
        return res;
    }
    void solve() {
        for(int i=1; i<maxn; ++i) a[i].fi=a[i].se=0;
        while(q--) {
            string st;
            cin >> st;
            int l,r;
            long long k;
            bool s;
            //cout << st << '\n';
            if(st=="ADD") {cin >> l >> r >> k;add(l,r,k);}
            else if(st=="TAKE") {cin >> l >> r >> k;take(l,r,k);}
            else if(st=="TOGGLE") {cin >> l >> r;toggle(l,r);}
            else if(st=="SWEEP") {cin >> l >> r >> l;sweep(l,r,k);}
            else if(st=="GET") {
                cin >> l >> r;printf("%lld\n",get(l,r));
            }
        }
    }
};
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    //file("mdlkts")
    scanf("%d%d",&n,&q);
    soup1::solve();
    return 0;
}
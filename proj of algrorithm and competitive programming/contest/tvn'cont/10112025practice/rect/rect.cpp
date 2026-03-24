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
const int maxn=300005,maxm=100005,mod=1000000007;
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
pair<ll,ll>p1[maxn],p2[maxn];
int n,m;
inline int find1(ll x, ll y1, ll y2) {
    auto l=lower_bound(p1+1,p1+1+n,mp(x,y1)),r=upper_bound(p1+1,p1+1+n,mp(x,y2));
    return (int)(r-l);
}
inline int find2(ll y, ll x1, ll x2) {
    auto l=lower_bound(p2+1,p2+1+n,mp(y,x1)),r=upper_bound(p2+1,p2+1+n,mp(y,x2));
    return (int)(r-l);
}
bool corner(ll x, ll y) {return binary_search(p1+1,p1+1+n,mp(x,y));}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) {
        ll x,y;
        scanf("%lld%lld",&x,&y);
        p1[i]=mp(x,y);
        p2[i]=mp(y,x);
    }
    scanf("%d",&m);
    sort(p1+1,p1+1+n);
    sort(p2+1,p2+1+n);
    for(int i=1; i<=m; ++i) {
        ll x1,y1,x2,y2;
        scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
        ll res=0;
        res+=find1(x1,y1,y2);
        res+=find1(x2,y1,y2);
        res+=find2(y1,x1,x2);
        res+=find2(y2,x1,x2);
        res-=corner(x1,y1)+corner(x1,y2)+corner(x2,y1)+corner(x2,y2);
        printf("%lld\n",res);
    }
    return 0;
}
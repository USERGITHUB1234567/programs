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
namespace soup1 {
    void solve() {
        long long kq=0;
        for(int i=1; i<=n; ++i) {
            for(int j=i,ma=0,mi=INT_MAX; j<=n; ++j) {
                ma=max(ma,a[j]);mi=min(mi,a[j]);
                kq+=ma-mi;
            }
        }
        printf("%d",kq);
    }
}
namespace soupfull {
    int cnt[maxn],maxl[maxn],maxr[maxn],minl[maxn],minr[maxn];
    stack<pair<int,int>>st1,st2;
    void solve() {
        long long kq=0;
        for(int i=1; i<=n; ++i) {
            while(!st1.empty() && st1.top().fi<a[i]) st1.pop();
            if(st1.empty()) maxl[i]=1;
            else maxl[i]=st1.top().se+1;
            st1.push(mp(a[i],i));
            while(!st2.empty() && st2.top().fi>a[i]) st2.pop();
            if(st2.empty()) minl[i]=1;
            else minl[i]=st2.top().se+1;
            st2.push(mp(a[i],i));
        }
        while(!st1.empty()) st1.pop();
        while(!st2.empty()) st2.pop();
        for(int i=n; i>=1; --i) {
            while(!st1.empty() && st1.top().fi<a[i]) st1.pop();
            if(st1.empty()) maxr[i]=n;
            else maxr[i]=st1.top().se-1;
            st1.push(mp(a[i],i));
            while(!st2.empty() && st2.top().fi>a[i]) st2.pop();
            if(st2.empty()) minr[i]=n;  
            else minr[i]=st2.top().se-1;
            st2.push(mp(a[i],i));
        }
        for(int i=1; i<=n; ++i) {
            kq+=1LL*a[i]*(i-maxl[i]+1)*(maxr[i]-i+1);
            kq-=1LL*a[i]*(i-minl[i]+1)*(minr[i]-i+1);
        }
        printf("%lld",kq);
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("tsd")
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    soupfull::solve();
    return 0;
}
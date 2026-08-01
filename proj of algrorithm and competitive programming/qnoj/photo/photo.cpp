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
int n,k;
ll h[maxn],pre[maxn];
int gcd(int a, int b) {
    if(a<b) swap(a,b);
    while(b!=0) {
        int c=a%b;
        a=b;
        b=c;
    }
    return a;
}
struct segtree {
    int st[maxn<<2];
    void build(int id, int l, int r) {
        if(l==r) {
            st[id]=h[l];
            return;
        }
        int m=(l+r)>>1;
        build(id<<1,l,m);
        build(id<<1|1,m+1,r);
        st[id]=gcd(st[id<<1],st[id<<1|1]);
    }
    int query(int id, int l, int r, int i, int j) {
        if(l>j || r<i) return 0;
        if(l>=i && r<=j) return st[id];
        int m=(l+r)>>1;
        return gcd(query(id<<1,l,m,i,j),query(id<<1|1,m+1,r,i,j));
    }
}seg;
namespace souplo {
    void solve() {
        seg.build(1,1,n);
        long long kq=0;
        for(int i=1; i<=n; ++i) {
            for(int j=i+k-1; j<=n; ++j) {
                kq=max(kq,seg.query(1,1,n,i,j)*(pre[j]-pre[i-1]));
            }
        }
        /* for(int i=1; i<=n; ++i) {
            for(int j=i; j<=n; ++j) cout << i << ' ' << j << ' ' << seg.query(1,1,n,i,j) << '\n';
        } */
        cout << kq;
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    //file("photo")
    cin >> n >> k;
    for(int i=1; i<=n; ++i) {cin >> h[i];pre[i]=pre[i-1]+h[i];}
    souplo::solve();
    return 0;
}
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
long long c[maxn],k,m;
namespace soup1 {
    inline long long add(long long &k, long long &c) {return (c<=k?c:k-c+k);}
    void solve() {
        long long kq=0;
        while(q--) {
            cin >> k >> m;
            kq=0;
            int l=1,r=n;
            while(m--) {
                if(add(k,c[l])<=add(k,c[r])) {
                    kq+=add(k,c[l]);
                    ++l;
                }
                else {
                    kq+=add(k,c[r]);
                    --r;
                }
            }
            cout << kq << '\n';
        }
    }
}
namespace soupfull {
    long long pre[maxn],suf[maxn];
    inline long long query(int x, long long k) {
        pre[x]+2*k*(m-x)-suf[m-x];
    }
    void solve() {
        for(int i=1; i<=n; ++i) pre[i]=pre[i-1]+c[i];
        for(int i=n; i>=1; --i) suf[i]=suf[i+1]+c[i];
        while(q--) {
            cin >> k >> m;
            int h=lower_bound(c+1,c+1+n,k)-c-1;
            int l=1,r=mini(m,h);
            while(l<r) {
                int mid=(l+r)>>1;
                long long v1=query(mid,k),v2=query(mid+1,k);
                if(v1>v2) l=mid;
                else r=mid;
            }
            cout << query(l,k) << "\n";
            //cout << 
        }
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> c[i];
    sort(c+1,c+1+n);
    soupfull::solve();
    return 0;
}
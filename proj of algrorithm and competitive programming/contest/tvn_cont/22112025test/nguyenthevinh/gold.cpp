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
int n,w,t,p;
long long f[2003][2003];
pair<ll,ll>gold[2003];
bool cmp(pair<ll,ll>a, pair<ll,ll>b) {return a.fi<b.fi;}
namespace soup1and2 {
    void solve() {
        int fm=(1<<n),kq=0;
        for(int mask=0; mask<fm; ++mask) {
            int cnt=0,weight=0,val=0;
            for(int j=0; j<n; ++j) {
                if(mask&(1<<j)) {
                    if(gold[j+1].se>t) ++cnt;
                    weight+=gold[j+1].se;
                    val+=gold[j+1].fi;
                }
            }
            if(cnt>1 || weight>w) continue;
            kq=max(kq,val);
        }
        cout << kq;
    }
}
namespace soupfull {
    void solve() {
        sort(gold+1,gold+1+n);
        for(int i=1; i<=n; ++i) if(gold[i].se<t) p=i;
        //cout << n << ' ' << w << ' ' << t;
        for(int i=1; i<=w; ++i) {
            for(int j=1; j<=n; ++j) {
                if(j<=p) {
                    if(i>gold[j].se) {
                        f[i][j]=max(f[i][j-1],f[i-gold[j].se][j-1]+gold[j].fi);
                    }
                    else f[i][j]=f[i][j-1];
                }
                else f[i][j]=max(f[i][p],f[i-gold[j].se][p]+gold[j].fi);
                //cout << f[i][j] << '\n';
            }
        }
        cout << f[w][n];
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("gold")
    cin >> n >> w >> t;
    for(int i=1; i<=n; ++i) cin >> gold[i].fi;
    for(int i=1; i<=n; ++i) cin >> gold[i].se;
    if(n<=20) soup1and2::solve();
    else soupfull::solve();
    return 0;
}
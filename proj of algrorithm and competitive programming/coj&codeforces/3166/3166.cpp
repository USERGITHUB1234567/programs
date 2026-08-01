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
#if defined(_WIN32) || defined(_WIN64)
  #define GETCHAR() _getchar_nolock() // MSVC
#else
  #define GETCHAR() getchar_unlocked() // GCC/Clang
#endif

inline bool readInt(int &out) {
    int c = GETCHAR();
    if (c == EOF) return false;
    while (c != '-' && (c < '0' || c > '9')) {
        c = GETCHAR();
        if (c == EOF) return false;
    }
    int sign = 1;
    if (c == '-') { sign = -1; c = GETCHAR(); }
    long long val = 0;
    for (; c >= '0' && c <= '9'; c = GETCHAR())
        val = val * 10 + (c - '0');
    out = (int)(val * sign);
    return true;
}
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
pair<ll,ll>p[maxn];
long long ans[maxn],kq=0;
namespace soup1 {
    void dfs(int u) {
        for(int t=1; t<=p[u].se; ++t) {

        }
    }
}
namespace soup3 {
    ll f[maxn],s[maxn];
    void solve() {
        s[n+1]=0;
        for(int i=1; i<=n; ++i) {
            f[i]=(1+s[i+1]-s[i+min(p[i].se,(ll)n-i)+1]+mod)%mod;
            s[i]=(s[i+1]+f[i])%mod;
        }
        cout << f[1];
    }
}
namespace souplo {
    void solve() {
        ans[1]=1;
        for(int i=1; i<=n; ++i) {
            if(!p[i].fi) continue;
            for(int j=i+p[i].fi,x=1; j<=n && x<=p[i].se; j+=p[i].fi) {
                ans[j]=(ans[j]+ans[i])%mod;
                //cout << ans[j] << " " << i << " " << j << "\n";
                ++x;
            }
        }
        for(int i=1; i<=n; ++i) {
            kq=(kq+ans[i])%mod;
            //cout << ans[i] << " ";
        }
        cout << kq;
    }
}
namespace soupfull {
    const int block=320;
    long long f[maxn],s[block+1][maxn+block];
    void solve() {
        memset(s,0,sizeof(s));
        for(int i=n; i>=1; --i) {
            if(!p[i].fi) {
                f[i]=1;
            }
            else 
                if(p[i].fi>block) {
                    f[i]=1;
                    for(int t=1; t<=p[i].se; ++t) {
                        int j=i+t*p[i].fi;
                        if(j>n) break;
                        f[i]=(f[i]+f[j])%mod;
                    }
                } else {
                    f[i]=(1+s[p[i].fi][i+p[i].fi]-s[p[i].fi][i+(min(p[i].se,(ll)(n-i)/(ll)p[i].fi)+1)*p[i].fi]+mod)%mod;
                }
            for(int j=1; j<=block; ++j) {
                s[j][i]=(s[j][i+j]+f[i])%mod;
            }
        }
        cout << f[1];
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("3166")
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> p[i].fi >> p[i].se;
    bool ck=true;
    for(int i=1; i<=n; ++i) {
        if(p[i].fi!=1) {
            ck=false;
            break;
        }
    }
    //if(ck) soup3::solve();
    //else souplo::solve();
    ///soup3::solve();
    soupfull::solve();
    return 0;
    
}
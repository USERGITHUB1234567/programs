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
#define int long long
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
long long n,m,w,h,a[maxn],b[maxn];
namespace souplo {
    long long grid[1003][1003],pre[1003][1003];
    long long query(int i, int j, int u, int v) {
        return pre[u][v]-pre[i-1][v]-pre[u][j-1]+pre[i-1][j-1];
    }
    void solvelo() {
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=m; ++j) {
                grid[i][j]=a[i]+b[j];
                pre[i][j]=pre[i-1][j]+pre[i][j-1]+grid[i][j]-pre[i-1][j-1];
                //cout << pre[i][j] << " " ;
            }
            //cout << "\n";
        }
        long long res=0;
        for(int i=1; i<=n-w+1; ++i) {
            for(int j=1; j<=m-h+1; ++j) {
                res=max(res,query(i,j,i+w-1,j+h-1));
                //cout << query(i,j,i+w-1,j+h-1) << "\n";
            }
        }
        //cout << query(1,2,3,4);
        cout << res;
    }
}
namespace soupfull {
    long long prea[maxn],preb[maxn];
    void solve() {
        for(int i=1; i<=n; ++i) prea[i]=prea[i-1]+a[i];
        for(int i=1; i<=m; ++i) preb[i]=preb[i-1]+b[i];
        long long m1=-1e18,m2=-1e18;
        for(int i=1; i<=n-w+1; ++i) {
            m1=max(m1,h*(prea[i+w-1]-prea[i-1]));
            //cout << i << " " << i+w-2 << "\n";
        }
        for(int i=1; i<=m-h+1; ++i) {
            m2=max(m2,w*(preb[i+h-1]-preb[i-1]));
        }
        cout << m1+m2;
    }
}
using namespace souplo;
using namespace soupfull;
signed main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m >> w >> h;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=m; ++i) cin >> b[i];
    // << "\n";
    solve();
    //cout << "\n";
    //solvelo();
    return 0;
}
/*
3 4 2 2  
1 -1 2  
1 1 1 1
*/
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
using namespace std::chrono;
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
mt19937_64 generator1(steady_clock::now().time_since_epoch().count());
mt19937_64 generator2(high_resolution_clock::now().time_since_epoch().count());
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);}
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);}
int n;
long long a[maxn],p;
namespace soup2 {
    long long pre[maxn];
    void solve() {
        for(int i=1; i<=n; ++i) pre[i]=pre[i-1]+a[i];
        int kq=0;
        for(int i=1; i<=n; ++i) {
            for(int j=i; j<=n; ++j) {
                //cout << (pre[j]-pre[i-1])/(j-i+1) << '\n';
                if((pre[j]-pre[i-1])/(j-i+1)>=p) ++kq;
            }
        }
        cout << kq;
    }
}
namespace soupfull {
    ll b[maxn],preb[maxn];
    unordered_map<ll,int>ump;
    int cnt=0;
    struct fenwick_tree {
        ll ft[maxn];
        long long sum(int i) {
            ll res=0;
            while(i>0) res+=ft[i],i-=i&-i;
            return res;
        }
        void upd(int i, ll v) {
            while(i<maxn) ft[i]+=v,i+=i&-i;
        }
    }ft;
    void solve() {
        vector<ll>com;
        com.pb(0);
        ll ans=0;
        for(int i=1; i<=n; ++i) {b[i]=a[i]-p,preb[i]=preb[i-1]+b[i];com.pb(preb[i]);}
        sortunique(com)
        for(ll v:com) ump[v]=++cnt;
        ft.upd(1,0);
        int cntneg=0;
        for(int i=1; i<=n; ++i) {
            //cout << preb[i] << ' ';
            ans+=ft.sum(ump[preb[i]]);
            if(preb[i]>=0) ++ans;
            ft.upd(ump[preb[i]],1);
            //cout << ump[preb[i]] << ' ';
            
            //cout << ump[preb[i]] << ' ';
        }
        cout << ans;
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("paveseq")
    auto st=steady_clock::now();
    cin >> n;for(int i=1; i<=n; ++i) cin >> a[i];
    cin >> p;
    if(n<=10000) soup2::solve();
    //cout << '\n';
    //soupfull::solve();
    else soupfull::solve();
    auto en=steady_clock::now();
    cerr << "\nTime elapsed: " << duration_cast<milliseconds>(en-st).count() << " ms\n";
    return 0;
}
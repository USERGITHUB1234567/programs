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
const int maxn=10004,maxm=300005,mod=1000000007;
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
int n,m;
long long p,r[maxn],y[maxn],t[maxm],g[maxm],v[maxm],kq=0;
namespace soup1 {
    long long sum=0,pre[maxn];
    bool win[maxm];
    void solve() {
        int fm=1<<n;
        pre[0]=1;
        for(int i=1; i<=m; ++i) {
            pre[i]=pre[i-1]*v[i];
        }
        for(int i=1; i<=m; ++i) {
            bool ckr=false,cky=false;
            for(int mask=0; mask<fm; ++mask) {
                long long cur=0;
                for(int j=0; j<n; ++j) {
                    if(mask&(1<<j)) cur+=r[j+1];
                }
                if(cur==t[i]) {
                    ckr=true;
                    break;
                }
            }
            for(int mask=0; mask<fm; ++mask) {
                long long cur=0;
                for(int j=0; j<n; ++j) {
                    if(mask&(1<<j)) cur+=y[j+1];
                }
                if(cur==g[i]) {
                    cky=true;
                    break;
                }
            }
            if(ckr && cky) win[i]=true;
        }
        int cur=0;
        vector<pair<int,int>>ans;
        for(int i=1; i<=m; ++i) {
            //cout << win[i] << " ";
            if(!win[i]) {
                if(cur==0) continue;
                ans.pb({cur,i-1});
                cur=0;
            }
            else {
                if(cur==0) cur=i;
            }
        }
        if(cur) ans.eb(cur,m);
        //for(int i=1; i<=m; ++i) cout << pre[i] << " ";
        for(auto[l,r]:ans) {
            //cout << l << " " << r << "\n";
            for(int i=l; i<=r; ++i) {
                for(int j=i; j<=r; ++j) {
                    long long cur=1;
                    for(int k=i; k<=j; ++k) cur=cur*(v[k])%p;
                    sum=(sum+cur)%p;
                }
            }
        }
        sum%=p;
        cout << sum;
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("gravel")
    cin >> n >> m >> p;
    for(int i=1; i<=n; ++i) cin >> r[i];
    for(int i=1; i<=n; ++i) cin >> y[i];
    for(int i=1; i<=m; ++i) cin >> t[i];
    for(int i=1; i<=m; ++i) cin >> g[i];
    for(int i=1; i<=m; ++i) cin >> v[i];
    soup1::solve();
    return 0;
}
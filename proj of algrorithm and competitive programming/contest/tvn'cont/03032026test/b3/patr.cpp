/**/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define all(x) x.begin(), x.end()
#define sortunique(x) sort(all(x)); x.erase(unique(all(x)), x.end());
#define forw(i,a,b) for(int (i)=(a); (i)<=(b); ++(i))
#define forb(i,a,b) for(int (i)=(a); (i)>=(b); --(i))
#define eb emplace_back
#define fi first
#define se second
#define pb push_back
using namespace std;
using namespace std::chrono;
static const int maxd=1003;
typedef short bignum[maxd];
typedef long long ll;
typedef long double ld;
const int maxn=200005,mod=1000000007,maxb=320;
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
inline ll logarit(ll k, ll n){ll res=0;while(n>0){n/=k;++res;}return res;}
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
auto imp_st=high_resolution_clock::now();
inline void start_timer() {imp_st=high_resolution_clock::now();}
inline void get_execution_time() {
    auto imp_en=high_resolution_clock::now();
    cerr << "Implementation Time: "<< duration_cast<milliseconds>(imp_en-imp_st).count() << " ms\n";
}
int n,t;
long long a[maxn];
namespace soup1lo{
    long long ans=0,mx=0,k;
    void solve() {
        for(int i=1; i<=n; ++i) {
            long long sum=0;
            if(a[i]<=mx) continue;
            k=mx;
            for(int j=i; j<=n; ++j) {
                if(a[j]>k) {
                    sum+=a[j]-k;
                    j+=t;
                }
            }
            mx=max(mx,a[i]);
            ans=max(ans,sum);
        }
        cout << ans;
    }
}
namespace soup2{
    bool check() {
        for(int i=1; i<=n; ++i) {
            if(a[i]!=i) return false;
        }
        return true;
    }
    void solve() {
        long long ans=0,mn=LLONG_MAX;
        int cnt=0;
        for(int i=1; i<=n; i+=t+1) ans+=a[i];
        cout << ans;
    }
}
namespace soup3 {
    bool check() {return t==1;}
    void solve() {
        long long s1=0,s2=0;
        for(int i=1; i<=n; i+=2) s1+=a[i];
        int st,mx=a[1];
        for(int i=2; i<=n; ++i) {
            if(a[i]>mx && !(i&1)) {st=i;break;}
            mx=max(mx,(int)a[i]);
        }
        for(int i=st; i<=n; i+=2) if(a[i]>mx) {s2+=a[i]-mx;}
        cout << max(s1,s2);
    }
}
namespace soup_destructive_brute{
    long long ans=0;
    bool check(int m) {
        return m*n<=1000000;
    }
    void solve() {
        long long m=*max_element(a+1,a+1+n);
        for(int i=1; i<=m; ++i) {
            long long sum=0;
            for(int j=1; j<=n; ++j) {
                if(a[j]>i) {
                    sum+=a[j]-i;
                    j+=t;
                }
            }
            ans=max(ans,sum);
        }
        cout << ans;
    }
};
namespace soup_brute_upgrade1{
    long long ans=0;
    int sz;
    void solve() {
        //long long m=*max_element(a+1,a+1+n);
        vector<long long>v;
        for(int i=1; i<=n; ++i) v.pb(a[i]);
        sortunique(v);
        sz=v.size();
        for(long long i:v) {
            long long sum=0;
            for(int j=1; j<=n; ++j) {
                if(a[j]>i) {
                    sum+=a[j]-i;
                    j+=t;
                }
            }
            ans=max(ans,sum);
        }
        cout << ans;
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("patr")
    cin >> n >> t;
    for(int i=1; i<=n; ++i) cin >> a[i];
    
    if(soup_destructive_brute::check(*max_element(a+1,a+1+n)))soup_destructive_brute::solve();
    else if(soup3::check()) soup3::solve();
    else if(soup2::check())soup2::solve();
    else soup_brute_upgrade1::solve();
    return 0;
}
/*
7 2
1 2 6 3 1 9 2

10 3
5 3 7 1 8 10 2 8 1 11
*/
/**/
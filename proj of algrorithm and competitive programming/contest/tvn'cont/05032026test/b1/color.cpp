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
const int maxn=100005,mod=4e18,maxb=320;
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
int n;string s;
namespace soup1{
    long long com[1003][1003];
    bool check() {for(int i=1; i<n; ++i) {if(s[i]!=s[i-1])return false;}return true;}
    void pre_process() {
        for(int i=0; i<1003; ++i) com[0][i]=com[i][i]=1;
        for(int i=1; i<1003; ++i) {
            for(int j=1; j<1003; ++j) com[i][j]=com[i-1][j-1]+com[i][j-1];
        }
    }
    void solve() {
        setupfactor();
        pre_process();
        //cout << com[4][8];
        cout << com[n][n<<1];
    }
}
namespace soup2{
    void solve() {
        n<<=1;
        int fm=1<<n;
        int ans=0;
        for(int mask=0; mask<fm; ++mask) {
            string t1="",t2="";
            for(int i=0; i<n; ++i) {
                if((1<<i)&mask) t1+=s[i];
                else t2=s[i]+t2;
            }
            if(t1==t2) ++ans;
        }
        cout << ans;
    }
}
namespace soup3{
    inline bool check() {

    }
    inline void solve() {
        string t=s;
        reverse(all(t));
        int fm=1<<n;
        long long ans=0;
        for(int mask=0; mask<fm; ++mask) {
            string t1="",t2="";
            for(int i=0; i<n; ++i) {
                if((1<<i)&mask) t1+=s[i];
                else t2=s[i]+t2;
            }
        }
        cout << ans;
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("color")
    cin >> n >> s;
    if(soup1::check()) soup1::solve();
    else soup2::solve();
    // soup1::solve();
    // soup2::solve();
    return 0;
}
/**/
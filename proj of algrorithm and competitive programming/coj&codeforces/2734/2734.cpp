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
using namespace std;
using namespace std::chrono;
static const int maxd=1003;
typedef short bignum[maxd];
typedef long long ll;
typedef long double ld;
const int maxn=100005,mod=1000000007,maxb=320;
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
int n,nega=1;
struct point {long double x,y;}p[maxn];
struct vect {long double x,y;};
//inline long double dot_product(vect a, vect b) {return a.x*b.x+a.y*b.y;}
inline long double dist(point a, point b) {
    long double t1=fabsl(a.x-b.x),t2=fabsl(a.y-b.y);
    return sqrt(t1*t1+t2*t2);
}
//inline long double vect_length(vect v) {return hypot(v.x*v.x,v.y*v.y);}
inline long double f(long double x) {
    point t={x,0};
    long double ans=0;
    for(int i=1; i<=n; ++i) {
        long double r=((p[i].x-x)*(p[i].x-x)+p[i].y*p[i].y)/(2*p[i].y);
        ans=max(ans,r);
    }
    return ans;
    //return ans/2;
    // vect t={0,1*nega};
    // for(int i=1; i<=n; ++i) {
    //     vect v={p[i].x-x,p[i].y};
    //     long double s=dot_product(t,v),lt=vect_length(t),lv=vect_length(v),;
    // }
}
long double ternary_search(long double l, long double r) {
    for(int i=1; i<=130; ++i) {
        long double m1=l+(r-l)/3,m2=r-(r-l)/3;
        if(f(m1)<f(m2)) r=m2;
        else l=m1;
    }
    //cout << l << ' ';
    return f((l+r)/2);
    
}
bool check() {
    bool pos=false,neg=false;
    for(int i=1; i<=n; ++i) {if(p[i].y>0) pos=true; else if(p[i].y<0) {neg=true;p[i].y*=-1;}}
    return pos&neg;
}
// namespace binary_search {

//     void solve() {

//     }
// }
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;for(int i=1; i<=n; ++i) cin >> p[i].x >> p[i].y;
    if(check()) {
        cout << -1;
        return 0;
    }
    cout << fixed << setprecision(3) << ternary_search(-1e7,1e7);
    return 0;
}
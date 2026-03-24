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
int t;
long double xa,ya,xb,yb,xc,yc,xd,yd;
struct point{long double x,y;};
struct vect{long double i,j;};
inline long double dist(point a, point b) {
    long double t1=fabsl(a.x-b.x),t2=fabsl(a.y-b.y);
    return t1*t1+t2*t2;
}
inline long double f(long double t) {
    vect a={xb-xa,yb-ya},b={xd-xc,yd-yc},at={a.i*t,a.j*t},bt={b.i*t,b.j*t};
    point pa={xa+at.i,ya+at.j},p_b={xc+bt.i,yc+bt.j};
    //cout << pa.x << ' ' << pa.y << ' ' << p_b.x << ' ' << p_b.y << ' ';
    return dist(pa,p_b);
}
inline long double ternary_search(long double l, long double r) {
    long double ans=min(f(0),f(1));
    for(int i=1; i<=60; ++i) {
        long double m1=l+(r-l)/3,m2=r-(r-l)/3;
        if(f(m1)<f(m2)) r=m2;
        else l=m1;
    }
    ans=min(ans,f(l));
    return sqrt(ans);
}
inline void soup() {

}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> t;
    cout << fixed << setprecision(6);
    while(t--) {
        cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;
        cout << ternary_search(0,1) << '\n';

        //cout << f(1) << '\n';
    }
    return 0;
}
/**/
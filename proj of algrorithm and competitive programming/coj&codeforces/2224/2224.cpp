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
long double X1,Y1,X2,Y2,v1,v2;
const long double eps=1e-12;
struct point {long double x,y;};
struct vect {long double x,y;};
inline long double dist(point a, point b) {
    long double t1=fabsl(a.x-b.x),t2=fabsl(a.y-b.y);
    return sqrt(t1*t1+t2*t2);
}
inline long double f(long double x) {
    point p={x,0},p1={X1,Y1},p2={X2,Y2};
    long double d1=dist(p1,p),d2=dist(p,p2);
    return (d1/v1)+(d2/v2);
}
long double search(long double l, long double r) {
    for(int i=1; i<=1000; ++i) {
        long double m1=l+(r-l)/3,m2=r-(r-l)/3;
        if(f(m1)<f(m2)) r=m2;
        else l=m1;
    }
    return f((l+r)/2);
}
pair<long double,long double>intersect(vect u) {
    if (fabsl(u.y)<eps) {return {X1,0.0L};}
    long double y=-Y1,t=y/u.y,x=t*u.x+X1;
    return {x,(long double)0};
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> t;
    cout << fixed << setprecision(5);
    while(t--) {
        cin >> X1 >> Y1 >> X2 >> Y2 >> v1 >> v2;
        // vect u={X2-X1,Y2-Y1};
        // auto[x,y]=intersect(u);
        // point p1={X1,Y1},p2={x,y},p3={X2,Y2};
        // long double d1=dist(p1,p2),d2=dist(p2,p3);
        // cout << fixed << setprecision(5) << (d1/v1)+(d2/v2) << '\n';
        long double l=min(X1,X2)-10,r=max(X1,X2)+10;
        cout << search(l,r) << '\n';
    }
    return 0;
}
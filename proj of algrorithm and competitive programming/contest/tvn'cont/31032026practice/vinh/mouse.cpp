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
namespace mathematics{ 
    long long fact[maxn],ifact[maxn]; 
    long long __gcd(long long a, long long b) { if(a<b) swap(a,b); while(a%b!=0) {long long c=a%b;a=b,b=c;} return b; } 
    inline ll __logarit(ll k, ll n){ll res=0;while(n>0){n/=k;++res;}return res;} 
    inline ll modexp(ll b, ll e, ll m) { ll res=1%m; while(e>0) { if(e&1) res=(res*b)%m; b=(b*b)%m; e>>=1; } return res; } 
    inline int maxi(int a, int b) {return (a>b?a:b);} 
    inline int mini(int a, int b) {return (a<b?a:b);} 
    inline ll maxill(ll a, ll b) {return (a>b?a:b);} 
    inline ll minill(ll a, ll b) {return (a<b?a:b);} 
    inline double maxid(double a, double b) {return (a>b?a:b);} 
    inline double minid(double a, double b) {return (a<b?a:b);} 
    inline ld maxild(ld a, ld b) {return (a>b?a:b);} 
    inline ld minild(ld a, ld b) {return (a<b?a:b);} 
    void setUpFactor() { fact[0]=1; for(int i=1; i<maxn; ++i) fact[i]=fact[i-1]*i%mod; int tc=maxn-1; ifact[tc]=modexp(fact[tc],mod-2,mod); for(int i=tc; i>=1; --i) ifact[i-1]=ifact[i]*i%mod; } 
    inline long long ncr(long long k, long long n) {return (k==n?1:fact[n]*ifact[n-k]%mod*ifact[k]%mod);} 
} 
using namespace mathematics; 
mt19937_64 generator1(steady_clock::now().time_since_epoch().count()); 
mt19937_64 generator2(high_resolution_clock::now().time_since_epoch().count()); 
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);} 
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);} 
auto imp_st=high_resolution_clock::now(); 
inline void start_timer() {imp_st=high_resolution_clock::now();} 
inline void get_execution_time() { auto imp_en=high_resolution_clock::now(); cerr << "Implementation Time: "<< duration_cast<milliseconds>(imp_en-imp_st).count() << " ms\n"; } 
struct point{long double x,y;}p[maxn];
struct vect{long double x,y;}vec[maxn];
inline long double cross_product (vect a, vect b) {return a.x*b.y-a.y*b.x;}
inline int side(point a, point b, point c) {
    vect ab={b.x-a.x,b.y-a.y},ac={c.x-a.x,c.y-a.y};
    long double s=cross_product(ab,ac);
    if(s==0) return 0;
    else if(s>0) return 1;
    return -1; 
}
inline long double area(vector<point>&po) {
    long double ans=0;
    for(int i=0; i<po.size(); ++i) {
        int j=(i+1)%po.size();
        ans+=po[i].x*po[j].y-po[i].y*po[j].x;
    }
    return fabsl(ans)/2;  
}
int n;
namespace soup1{
    bool inside_brute_version(vector<point>po, point t) {
        for(int i=0; i<po.size(); ++i) {
            int j=(i+1)%po.size();
            if(side(po[i],po[j],t)!=-1) return false;
        }
        return true;

    }
    void solve() {
        vector<point>m;
        for(int i=1; i<=n; ++i) m.pb(p[i]);
        long double a=area(m),t=0;
        for(int i=1; i<=n; ++i) {
            for(int j=i+1; j<=n; ++j) {
                for(int k=j+1; k<=n; ++k) {
                    vector<point>po={p[i],p[j],p[k]};
                    t+=area(po);
                }
            }
        }
        cout << fixed << setprecision(15) << t/a;
    }
}
namespace soupfull {
    void solve() {
        vector<point>m;
        for(int i=1; i<=n; ++i) m.pb(p[i]);
        long double a=area(m);
        
    }
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    file("mouse")
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> p[i].x >> p[i].y;
    soup1::solve();
    return 0; 

} 
/**/
/*
4
0 0
1 0
1 1
0 1

5
0 0
1 0
2 1
1 2
0 2
*/
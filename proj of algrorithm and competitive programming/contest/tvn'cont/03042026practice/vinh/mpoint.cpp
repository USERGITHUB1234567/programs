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
const int maxn=300005,mod=1000000007,maxb=320; 
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
int n;
namespace soup1{
    void solve() {
        cout << (long long)(abs(p[1].x-p[2].x)+abs(p[1].y-p[2].y)+1)/2;
    }
}
namespace soup2and3{
    inline long long distance(point x, point y) {}
    inline bool check(long long m) {
        
    }
    void solve() {
        long long l=0,r=1e18;
        
    }
}
namespace soupfull{
    const long double pi=M_PI,eps=1e-12;
    inline point spin(point a, long double angl) {
        point res;
        res.x=a.x*cosl(angl)-a.y*sinl(angl);
        res.y=a.x*sinl(angl)+a.y*cosl(angl);
        return res;
    }
    struct rect{point a,b;};
    inline bool check(long long m) {
        vector<rect>r;
        for(int i=1; i<=n; ++i){
            point p1={p[i].x-m,p[i].y},p2={p[i].x+m,p[i].y};
            p1=spin(p1,pi/4),p2=spin(p2,pi/4);
            if(p1.x<p2.x) r.pb({p1,p2});
            else r.pb({p2,p1});
        }
        point u={-4e18,-4e18},v={4e18,4e18};
        for(int i=0; i<r.size(); ++i) {
            auto[a,b]=r[i];
            u={max(u.x,a.x),max(u.y,a.y)},v={min(v.x,b.x),min(v.y,b.y)};
        }
        //cout << u.x << ' ' << u.y << '\n' << v.x << ' ' << v.y << '\n';
        //return u.x<=v.x && u.y<=v.y;
        return v.x-u.x>=eps && v.y-u.y>=eps;
    }
    void solve() {
        
        // point t={0,1};
        // t=spin(t,pi/2);
        // cout << t.x << ' ' << t.y;
        // for(int i=1; i<=n; ++i) {t[i]=spin(p[i],pi/4);}
        long long l=0,r=1e18;
        while(l<r) {
            long long mid=(l+r)>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        cout << l;
        //cout << check(3);
    }
}
namespace cookedsoup{
    //struct pointll{long long x,y;}pll[maxn];
    inline long long dist(point a, point b) {return (long long)(abs(a.x-b.x)+abs(a.y-b.y));}
    void solve() {
        long double xt,yt;
        for(int i=1; i<=n; ++i) {xt+=p[i].x,yt+=p[i].y;}
        xt/=n,yt/=n;
        long long ans=0,r1=0,r2=0,r3=0,r4=0;
        long long xu=ceill(xt),xd=floorl(xt),yu=ceill(yt),yd=floorl(yt);
        point p1={(ld)xu,(ld)yu},p2={(ld)xu,(ld)yd},p3={(ld)xd,(ld)yu},p4={(ld)xd,(ld)yd};
        for(int i=1; i<=n; ++i) {r1=max(r1,dist(p[i],p1));}
        for(int i=1; i<=n; ++i) {r2=max(r2,dist(p[i],p2));}
        for(int i=1; i<=n; ++i) {r3=max(r3,dist(p[i],p3));}
        for(int i=1; i<=n; ++i) {r4=max(r4,dist(p[i],p4));}
        cout << min({r1,r2,r3,r4});
        //cout << r1.x << ' ' << r1.y << '\n' << r2.x << ' ' << r2.y << '\n' << r3.x << ' ' << r3.y << '\n' << r4.x << ' ' << r4.y;
        //cout << r1 << ' ' << r2 << ' ' << r3 << ' ' << r4;
        //cout << p4.x << ' ' << p4.y;
    }
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    file("mpoint")
    long long lim=0;
    cin >> n;for(int i=1; i<=n; ++i) {cin >> p[i].x >> p[i].y;lim=max({(ld)lim,p[i].x,p[i].y});}
    // soup1::solve();
    // cout << '\n';
    // soupfull::solve();
    if(n==2) soup1::solve();
    else if(lim<=1000) soupfull::solve();
    else cookedsoup::solve();
    // soup1::solve();
    // cout << '\n';
    // cookedsoup::solve();
    // soup1::solve();
    // cout << '\n';
    // soupfull::solve();
    return 0; 

} 
/**/
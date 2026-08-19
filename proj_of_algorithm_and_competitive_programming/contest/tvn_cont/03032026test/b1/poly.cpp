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
const int inf=1000000009;
struct point{long double x,y;};
struct vect{long double x,y;};
int n,m,q;
vector<point>p;
vector<vect>v;
namespace soup1 {
    point pu={-inf,-inf},pv={inf,inf};
    inline void preprocess() {
        for(int i=1; i<=m; ++i) {
            auto[xt,yt]=v[i-1];
            point p1={p[0].x+xt,p[0].y+yt},p2={p[1].x+xt,p[1].y+yt},p3={p[2].x+xt,p[2].y+yt},p4={p[3].x+xt,p[3].y+yt};
            vector<point>tmp;
            tmp.pb(p1),tmp.pb(p2),tmp.pb(p3),tmp.pb(p4);
            sort(all(tmp),[](point a, point b){return a.x<b.x || (a.x==b.x && a.y<b.y);});
            pu={max(pu.x,tmp[0].x),max(pu.y,tmp[0].y)};
            pv={min(pv.x,tmp[3].x),min(pv.y,tmp[3].y)};
        }
    }
    bool inside(point a) {return (a.x>=pu.x && a.y>=pu.y && a.x<=pv.x && a.y<=pv.y);}
    void solve() {
        preprocess();
        cin >> q;
        //cout << pu.x << ' ' << pu.y << ' ' << pv.x << ' ' << pv.y << '\n';
        while(q--) {
            point t;cin >> t.x >> t.y;
            if(inside(t)) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
namespace soup2 {
    const long double eps = 1e-12L;
    long double crpd(const vect &a, const vect &b) {return a.x * b.y - a.y * b.x;}
    int side(const point &a, const point &b, const point &c) {
        vect ab{b.x-a.x,b.y-a.y};
        vect ac{c.x-a.x,c.y-a.y};
        long double s=crpd(ab,ac);
        if (fabsl(s)<eps) return 0;
        return (s>0?1:-1);
    }
    inline bool inside(const vector<point> &poly, const point &pt) {
        int sz=(int)poly.size();
        for (int i=0; i<sz; ++i) {
            int j=(i+1)%sz;
            if (side(poly[i],poly[j],pt)==-1) return false;
        }
        return true;
    }
    inline bool check(const point &spe) {
        for (int i=0; i<m; ++i) {
            vector<point> poly;
            long double tx=v[i].x,ty=v[i].y;
            poly.reserve(p.size());
            for (const auto &pt:p) poly.emplace_back(point{pt.x+tx,pt.y+ty});
            if (!inside(poly,spe)) return false;
        }
        return true;
    }
    void solve() {
        cin >> q;
        while (q--) {
            point t; cin >> t.x >> t.y;
            if (check(t)) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
namespace soup3 {
    void solve() {
        
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("poly")
    cin >> n;
    for(int i=1,x,y; i<=n; ++i) {
        cin >> x >> y;
        p.pb({(ld)x,(ld)y});
    }
    cin >> m;
    for(int i=1,x,y; i<=m; ++i) {
        cin >> x >> y;
        v.pb({(ld)x,(ld)y});
    }
    //soup2::solve();
    //soup1::solve();
    //for(auto[x,y]:v) cout << x << ' ' << y << '\n';
    return 0;
}
/*
5
-2 -3
0 -2
1 0
0 2
-2 1
2
0 1
1 0
6
0 0
1 0
0 1
1 1
-1 -1
-1 -2
*/
/**/
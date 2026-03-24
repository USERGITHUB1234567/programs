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
const int maxn=102,mod=1000000007;
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
struct vect {ld x,y;};
struct road {ld x,y,u,v;}ro[maxn];
struct point{ld x,y;};
long double crpd(vect a, vect b) {
    return a.x*b.y-a.y*b.x;
}
long double dprd(vect a, vect b) {
    return a.x*b.x+a.y*b.y;
}
long double dpts(point a, road b) {
    vect ab={b.u-b.x,b.v-b.y},au={a.x-b.x,a.y-b.y};
    long double len=fabsl(sqrt(ab.x*ab.x+ab.y*ab.y));
    return fabsl(crpd(ab,au))/len;
}
long double dptp(point &a, point &b) {
    return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
long double dist(road &s, road &t) {
    //vect ab=
    point as={s.x,s.y},at={s.u,s.v},bs={t.x,t.y},bt={t.u,t.v};
    return min({dpts(as,t),dpts(bs,t),dpts(at,s),dpts(as,t)});
}
long double length(road &a) {
    return (a.u-a.x)*(a.u-a.x)+(a.v-a.y)*(a.v-a.y);
}
bool check(road &a, road &b ,road &c) {
    return (dist(a,b)<=length(c) || dist(b,c)<=length(a) || dist(a,c)<=length(c));
}
int n;
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    int kq=0;
    for(int i=1; i<=n; ++i) cin >> ro[i].x >> ro[i].y >> ro[i].u >> ro[i].v;
    for(int i=1; i<=n; ++i) {
        for(int j=i+1; j<=n; ++j) {
            for(int k=j+1; k<=n; ++k) {
                if(check(ro[i],ro[j],ro[k])) ++kq;
                //++kq;
            }
        }
    }
    cout << kq;
    return 0;
}
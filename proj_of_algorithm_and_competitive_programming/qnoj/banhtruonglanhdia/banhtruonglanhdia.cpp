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
const int maxn=1003,mod=1000000007;
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
inline ll log(ll k, ll n){ll res=0;while(n>0){n/=k;++res;}return res;}
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
int n,m,uni=0,chau=0,sukuna=0,a[maxn][maxn];
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    //file("banhtruonglanhdia")
    cin >> n >> m;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            cin >> a[i][j];
        }
        //cout << '\n';
    }
    for(int i=1,u,v,uc,vc,us,vs; i<=n; ++i) {
        u=-1;v=-1;uc=-1;vc=-1;us=-1;vs=-1;
        for(int j=1; j<=m; ++j) {
            if(a[i][j]==1 || a[i][j]==3) {
                uc=j;
                break;
            }
        }
        for(int j=m; j>=1; --j) {
            if(a[i][j]==1 || a[i][j]==3) {
                vc=j;
                break;
            }
        }
        for(int j=1; j<=m; ++j) {
            if(a[i][j]==2 || a[i][j]==3) {
                us=j;
                break;
            }
        }
        for(int j=m; j>=1; --j) {
            if(a[i][j]==2 || a[i][j]==3) {
                vs=j;
                break;
            }
        }
        for(int j=1; j<=m; ++j) {
            if(a[i][j]!=0) {
                u=j;
                break;
            }
        }
        for(int j=m; j>=1; --j) {
            if(a[i][j]!=0) {
                v=j;
                break;
            }
        }
        //cout << u << ' ' << v << ' ' << uc << ' ' << vc << ' ' << us << ' ' << vs << '\n';
        if(u==-1 && v==-1) uni+=0;
        else uni+=abs(u-v)+1;
        if(uc==-1 && vc==-1) chau+=0;
        else chau+=abs(uc-vc)+1;
        if(us==-1 && vs==-1) sukuna+=0;
        else sukuna+=abs(us-vs)+1;
    }
    cout << chau+sukuna-uni;
    return 0;
}
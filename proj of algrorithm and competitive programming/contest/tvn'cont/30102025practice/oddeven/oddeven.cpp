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
const int maxn=5003,mod=1000000007;
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
int n,m,a[maxn],b[maxn],cur=0;
namespace souprua {
    void solve() {
        int i=1,j=1;
        if(a[1]==0 && b[1]==0) cur=0;
        else cur=-1;
        while(i<=n || j<=m) {
            if((i>=n || (a[i]&1)==(cur&1)) && j<=m) {
                if((b[j]&1)==(cur&1)) {
                    b[j]=cur+2;
                    cur+=2;
                    ++j;
                }else {
                    b[j]=++cur;
                    ++j;
                }
                //printf("a");
            }
            else {
                if((a[i]&1)==(cur&1)) {
                    a[i]=cur+2;
                    cur+=2;
                    ++i;
                }else {
                    a[i]=++cur;
                    ++i;
                }
                //printf("b");
            }
            //printf("%d ",cur);
        }
        printf("%d",cur);
    }
}
namespace soup1 {
    void solve() {
        int kq=0;
        if(b[1]==1) kq=1;
        else kq=2;
        for(int i=2; i<=m; ++i) {
            if(b[i]==b[i-1]) kq+=2;
            else ++kq;
        }
        printf("%d",kq);
    }
}
namespace soupfull {
    int fa[maxn][maxn],fb[maxn][maxn];
    void solve() {
        fa[0][0]=fb[0][0]=0;
        for(int i=1; i<=m; ++i) {
            fa[0][i]=INT_MAX;
            fb[0][i]=fb[0][i-1]+(b[i]==b[i-1]?2:1);
        }
        for(int i=1; i<=n; ++i) {
            fa[i][0]=fa[i-1][0]+(a[i]==a[i-1]?2:1);
            fb[i][0]=INT_MAX;
        }
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=m; ++j) {
                fa[i][j]=min(fa[i-1][j]+(a[i]==a[i-1]?2:1),fb[i-1][j]+(a[i]==b[j]?2:1));
                fb[i][j]=min(fb[i][j-1]+(b[j]==b[j-1]?2:1),fa[i][j-1]+(b[j]==a[i]?2:1));
            }
        }
        printf("%d",min(fa[n][m],fb[n][m]));
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("oddeven")
    scanf("%d",&n);for(int i=1; i<=n; ++i) {scanf("%d",&a[i]);}
    scanf("%d",&m);for(int i=1; i<=m; ++i) {scanf("%d",&b[i]);}
    soupfull::solve();
    return 0;
}
/*
0
4 1 0 1 1

4 0 1 0 1
4 1 0 0 1

5 0 1 0 0 1
4 0 0 0 1
*/
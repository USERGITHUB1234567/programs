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
namespace mathematics{ 
    long long fact[maxn],ifact[maxn]; 
    long long __uiagcd(long long a, long long b) { if(a<b) swap(a,b); while(a%b!=0) {long long c=a%b;a=b,b=c;} return b; } 
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
int t;
pair<long long,long long>query[maxn];
namespace soupfullnotproven{
    void solve() {
        for(int i=1; i<=t; ++i) {
            auto[n,m]=query[i];
            long long ans=modexp(m,n,mod);
            m=m%mod;
            long long n2=-1;
            if(n<2) n2=0;
            n=n%mod;
            //if(n<2) n=0;
            if(n2==-1)n2=(n+mod-2)%mod;
            //if(n<2) n2=0;
            long long h=(m*(n2));
            ans=(ans+mod-h)%mod;
            cout << ans << '\n';
        }
    }
}
namespace soup1{
    int a[10],n,m,ans=0;
    bool check() {
        if(t>1) return false;
        for(int i=1; i<=t; ++i) {
            auto[n,m]=query[i];
            if(n>8 || m>8) return false;
        }
        return true;
    }
    void backtrack(int i) {
        if(i==n+1) {
            int cnt=0;
            bool ck=true;
            for(int j=1; j<=n; ++j) {
                //cout << a[i] 
                //cout << a[j] << ' ';
                if(a[j]==a[j-1]) ++cnt;
                else cnt=0;
                if(cnt>=2) {ck=false;break;}
            }
            // cout << ck;
            // cout << '\n';
            ans+=ck;
            return;
        }
        for(int j=1; j<=m; ++j) {
            a[i]=j;
            backtrack(i+1);
        }
    }
    void solve() {
        n=query[1].fi,m=query[1].se;
        backtrack(1);
        cout << ans;
    }
}
namespace soup2{
    long long f[maxn],h[maxn];
    void solve() {
        for(int q=1; q<=t; ++q) {
            auto[n,m]=query[q];
            f[0]=1;
            f[1]=m;
            f[2]=(f[1]*f[1]);
            long long t=0;
            for(int i=3; i<=n; ++i) {
                f[i]=(f[i-1]+f[i-2])*(m-1);
            }
            cout << f[n];
        }
    }
}
struct matrix{
    ll a[2][2];
    matrix() {memset(a,0,sizeof(a));}
};
inline matrix mul(matrix a, matrix b) {
    matrix c;
    for(int i=0; i<2; ++i) {
        for(int j=0; j<2; ++j) {
            for(int k=0; k<2; ++k) {
                c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%mod;
            }
        }
    }
    return c;
}
inline matrix powmod(matrix b, long long e, long long m) {
    matrix res;
    res.a[0][0]=1,res.a[1][1]=1;
    while(e) {
        if(e&1) {res=mul(res,b);}
        b=mul(b,b);
        e>>=1;
    }
    return res;
}
namespace soupfull {
    void solve() {
        for(int q=1; q<=t; ++q) {
            auto[n,m]=query[q];
            matrix mat;
            m%=mod;
            mat.a[0][1]=1;
            mat.a[1][0]=m-1;
            mat.a[1][1]=m-1;
            if(n==1) {cout << m%mod << '\n';continue;}
            if(n==2) {
                cout << (m*m)%mod << '\n';
                continue;
            }
            mat=powmod(mat,n-2,mod);
            long long ans=(m*mat.a[1][0])%mod+(((m*m)%mod)*mat.a[1][1])%mod;
            cout << ans%mod << '\n';
        }
    }
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> t;
    for(int i=1; i<=t; ++i) cin >> query[i].fi >> query[i].se;
    //soupfullnotproven::solve();
    // soup1::solve();
    // cout << '\n';
    // soupfullnotproven::solve();
    // cout << '\n';
    // soup2::solve();
    // if(soup1::check) soup1::solve();
    // else soupfullnotproven::solve();
    // soup1::solve();
    // cout << '\n';
    // soup2::solve();
    // cout << '\n';
    soupfull::solve();
    return 0; 

} 
/**/
/*
2
2 2
3 4
*/
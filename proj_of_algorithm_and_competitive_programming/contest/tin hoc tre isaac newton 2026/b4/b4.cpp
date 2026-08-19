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
const int maxn=120005,mod=1000000007,maxb=320; 
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
int n;
pair<int,int>p[maxn];
vector<int>col[maxn>>2],ans;
long long t=0,res=LLONG_MAX;
namespace soup1{
    inline void dfs(int i,vector<int>v) {
        if(i==n+1) {
            long long sum=0;
            for(int j:v) {
                sum+=p[j].fi;
            }
            ll h=t-sum;
            if(abs(sum-h)<res) {
                ans=v;
                res=abs(sum-h);
            }
            return;
        }
        for(int j=0; j<4; ++j) {
            for(int k=j+1; k<4; ++k) {
                v.push_back(col[i][j]);v.pb(col[i][k]);
                dfs(i+1,v);
                v.pop_back();v.pop_back();
            }
        }
    }
    void solve() {
        dfs(1,{});
        for(int i:ans) cout << i << ' ';
    }
}
namespace soupfull{
    int dif[maxn];
    vector<pair<int,int>>mas[maxn];
    void solve() {
        for(int i=1; i<=(n<<2); ++i) {
            auto[u,v]=p[i];
            mas[v].pb({u,i});
        }
        for(int i=1; i<=n; ++i) sort(all(mas[i]));
        for(int i=1; i<=n; ++i) {
            long long t1=mas[i][0].fi+mas[i][3].fi,t2=mas[i][1].fi+mas[i][2].fi;
            if(t1<t2) {
                swap(mas[i][1],mas[i][4]);
            }
            else swap(mas[i][0],mas[i][2]);
            dif[i]=abs(t1-t2);
        }
        long long d=0;
        for(int i=1; i<=n; ++i) {
            if(d>0) {
                d-=dif[i];
                ans.pb(mas[i][2].se);ans.pb(mas[i][3].se);
            }
            else {
                d+=dif[i];
                ans.pb(mas[i][0].se);ans.pb(mas[i][1].se);
            }
        }
        //for(int i=1; i<=n; ++i) cout << mas[i].size() << '\n';
        for(int i:ans) cout << i << ' ';
    }
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> n;
    for(int i=1; i<=(n<<2); ++i) {cin >> p[i].fi >> p[i].se;col[p[i].se].pb(i);t+=p[i].fi;}
    if(n<=30)soup1::solve();
    else soupfull::solve();
    //soupfull::solve();
    return 0; 

} 
/**/
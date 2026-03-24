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
long long n,k,a[maxn],s[maxn];
namespace soup1{
    inline bool check() {return n<=100 && k<=100;}
    int vis[maxn];
    long long add[maxn],in[maxn];
    inline void dfs(int u) {
        if(vis[u]==in[u] && in[u]!=0) return;
        //cerr << u << ' ' << s[u] << '\n';
        ++vis[u];
        add[s[u]]+=a[u];
        add[u]-=a[u];
        if(s[u]==u || in[u]==0) return;
        dfs(s[u]);
    }
    void solve() {
        for(int i=1; i<=n; ++i) ++in[s[i]];
        for(int i=1; i<=k; ++i) {
            for(int j=1; j<=n; ++j) {vis[j]=0;add[j]=a[j];}
            for(int j=1; j<=n; ++j) {
                if(vis[j]<=in[j]) dfs(j);
            }
            for(int j=1; j<=n; ++j) a[j]=add[j];
        }
        vector<int>ans;
        int mx=0;
        for(int i=1; i<=n; ++i) {
            if(a[i]>mx) {mx=a[i];ans.clear();ans.pb(i);}
            else if(a[i]==mx) {ans.pb(i);}
        }
        for(int i=1; i<=n; ++i) cout << a[i] << ' ';
        //cout << '\n';
        cout << mx << '\n';
        for(int i:ans) cout << i << '\n';
    }
}
namespace soup2{
    int ncomp=0;
    vector<int>comp[maxn];
    bool vis[maxn];
    inline void dfs(int u) {
        if(vis[u]) return;
        vis[u]=true;
        comp[ncomp].pb(u);
        if(s[u]==u) return;
        dfs(s[u]);
    }
    void solve() {
        for(int i=1; i<=n; ++i) {if(!vis[i]) {++ncomp;dfs(i);}}
        vector<pair<int,int>>ans;
        for(int c=1; c<=ncomp; ++c) {
            int mx=0;
            vector<int>pos;
            for(int j=0; j<comp[c].size(); ++j) {
                if(a[comp[c][j]]>mx) {
                    mx=a[comp[c][j]];
                    pos.clear();
                    pos.pb(j);
                }
                else if(a[comp[c][j]]==mx) pos.pb(j);
                //cerr << comp[c][j] << ' ' << a[comp[c][j]] << ' ' << j << '\n';
            }
            for(int i:pos) {
                ans.pb({mx,comp[c][(i+k)%comp[c].size()]});
            }
        }
        vector<int>res;
        int mx=0;
        for(auto[u,v]:ans) mx=max(mx,u);
        for(auto[u,v]:ans) {if(u==mx)res.pb(v);}
        cout << mx << '\n';
        sort(all(res));
        for(int i:res) cout << i << '\n';
    }
}
int main(int argc, char** argv) {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("ball")
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) {cin >> s[i];}
    if(soup1::check) soup1::solve();
    //cout << '\n';
    else soup2::solve();
    return 0;

} 
/**/
/*
8 1
654 774 995 682 883 801 203 324 
2 6 4 1 5 8 8 7
*/
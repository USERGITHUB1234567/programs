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
pair<long long,long long>st,en,p[maxn];
int k;
namespace soup3{
    int f[maxn];
    long long d;
    inline long long dist(pair<long long,long long>a, pair<long long,long long>b) {return max(abs(a.fi-b.fi),abs(a.se-b.se));}
    inline bool check(vector<pair<long long,long long>>v) {
        // v.insert(v.begin(),st);
        // v.pb(en);
        long long c=0,d=dist(v[0],v[v.size()-1]);
        for(int i=1; i<v.size(); ++i) {
            c+=dist(v[i-1],v[i]);
        }
        //cout << c << ' ' << d << '\n';
        return c<=d;
    }
    void solve() {
        d=dist(st,en);
        sort(p+1,p+1+k,[](pair<long long,long long>a, pair<long long,long long>b){return dist(a,st)<dist(b,st);});
        //cout << d << ' ' << dist(st,p[2]) << ' ' << dist(p[2],p[3]) << ' ' << dist(p[3],en) << '\n';
        long long ans=0;
        for(int i=1; i<=k; ++i) {
            if(!check({st,p[i],en})) continue;
            f[i]=1;ans=max(ans,(ll)f[i]);
            for(int j=i-1; j>=1; --j) {
                if(check({st,p[j],p[i]})) {f[i]=max(f[i],f[j]+1);}
                ans=max(ans,(ll)f[i]);
            }
        }
        cout << ans;
        //cout << *max_element(f+1,f+1+k);
    }
}
namespace soupfull{
    inline long long dist(pair<long long,long long>a, pair<long long,long long>b) {return max(abs(a.fi-b.fi),abs(a.se-b.se));}
    inline bool check(vector<pair<long long,long long>>v) {
        // v.insert(v.begin(),st);
        // v.pb(en);
        long long c=0,d=dist(v[0],v[v.size()-1]);
        for(int i=1; i<v.size(); ++i) {
            c+=dist(v[i-1],v[i]);
        }
        //cout << c << ' ' << d << '\n';
        return c<=d;
    }
    void solve() {
        vector<pair<long long,long long>>v;
        for(int i=1; i<=k; ++i) {
            
        }
    }
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> st.fi >> st.se >> en.fi >> en.se >> k;
    for(int i=1; i<=k; ++i) cin >> p[i].fi >> p[i].se;
    soup3::solve();
    return 0; 

} 
/**/
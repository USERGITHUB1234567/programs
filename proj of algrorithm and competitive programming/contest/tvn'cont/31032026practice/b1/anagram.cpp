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
const int maxn=2003,mod=1000000007,maxb=320; 
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
int n,k;
string s[maxn];
namespace soup1{
    void solve() {
        int fm=1<<n;
        int cnt=0;
        for(int mask=0; mask<fm; ++mask) {
            int d=0;
            vector<int>v;
            for(int i=0; i<n; ++i) {
                if((1<<i)&mask) v.pb(i+1);
            }
            if(v.size()<2) continue;
            for(int i=0; i<v.size(); ++i) {
                for(int j=i+1; j<v.size(); ++j) {
                    if(s[v[i]]==s[v[j]]) ++d;
                }
            }
            if(d==k) ++cnt;
            //cnt+=t1;
        }
        cout << cnt;
    }
}
namespace soup2{
    void solve() {
        unordered_map<string,int>ump;
        for(string t:s) ++ump[t];
        vector<int>val;
        for(auto x:ump) val.pb(x.second);
        if(k==1) {
            
        }
    }
}
namespace soupfull{
    long long ans=0;
    bool valid(long double x) {
        long long t=x;
        return x-t==0;
    }
    inline long long subtract(long long s1,long long s2) {
        s1-=s2;
        if(s1<0) s1+=mod;
        return s1;
    }
    inline long double quadratic_equation_solve(long double a, long double b, long double c) {
        long long delta=b*b-4*a*c;
        if(delta<0) return LLONG_MAX;
        if(delta==0) return -b/(2*a);
        else {
            long double x1=-((b+sqrt(delta))/(2*a)),x2=-((b-sqrt(delta))/(2*a));
            if(x1>=0) return x1;
            else return x2;
            //return x2;
        }
    }
    void solve() {
        //cout << quadratic_equation_solve(1,1,-2);
        setUpFactor();
        // for(int i=1; i<=n; ++i) {
        //     long double x=quadratic_equation_solve()
        // }
    }
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    file("anagram")
    cin >> n >> k;
    for(int i=1; i<=n; ++i) {cin >> s[i];sort(all(s[i]));}
    soup1::solve();
    cout << '\n';
    soupfull::solve();
    return 0; 

} 
/**/

/*
3 1
ovo
ono
voo

5 2
trava
vatra
vrata
leo
ole
*/
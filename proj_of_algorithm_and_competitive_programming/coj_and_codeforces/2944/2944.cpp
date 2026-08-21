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
using namespace std::chrono;
static const int maxd=1003;
typedef short bignum[maxd];
typedef long long ll;
typedef long double ld;
const int maxn=100005,mod=1000000007;
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
mt19937_64 generator1(steady_clock::now().time_since_epoch().count());
mt19937_64 generator2(high_resolution_clock::now().time_since_epoch().count());
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);}
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);}

auto imp_st=high_resolution_clock::now();
inline void get_execution_time() {
    auto imp_en=high_resolution_clock::now();
    cerr << "Implementation Time: "<< duration_cast<milliseconds>(imp_en-imp_st).count() << " ms\n";
}
int n,a[maxn];
int prf[maxn];
inline void factorize(int x) {
    for(int i=2; i*i<=x; ++i) {
        while(!(x%i)) {
            ++prf[i];
            x/=i;
            //cerr << i << '\n';
        }
    }
    if(x>1) ++prf[x];
}
inline vector<pair<int,int>>factorize_pri(int x) {
    vector<pair<int,int>>ans;
    for(int i=2; i*i<=x; ++i) {
        int cnt=0;
        while(!(x%i)) {
            ++cnt;
            x/=i;
        }
        if(cnt) ans.pb({i,cnt});
    }
    if(x>1) ans.eb(x,1);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    imp_st=high_resolution_clock::now();
    file("2944")
    scanf("%d",&n);for(int i=1; i<=n; ++i) {scanf("%d",&a[i]);factorize(a[i]);}
    //for(int j=1; j<=5; ++j) printf("%d ",prf[j]);
    //printf("\n");
    unordered_map<int,bool>cnt;
    for(int i=1; i<=n; ++i) {
        bool ck=false;vector<pair<int,int>>f=factorize_pri(a[i]);
        for(auto[p,c]:f) {
            prf[p]-=c;
            if(!prf[p]) {
                //printf("%d\n",p);ck=true;break;
                cnt.erase(p);
            }else {
                cnt[p]=true;
            }
            //for(int j=1; j<=5; ++j) printf("%d ",prf[j]);
            //printf("%\n");
        }
        if(cnt.empty()) {printf("%d",i);return 0;}
    }
    return 0;
}
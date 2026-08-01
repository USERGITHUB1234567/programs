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
const int maxn=300005,mod=1000000007,maxb=320; 
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
int n,a[maxn];
vector<int>val;
class fenwick_tree{
    private:
        int ft[maxn],m;
    public:
        fenwick_tree(int _m=maxn):m(_m) {memset(ft,0,sizeof(ft));}
        inline void add(int i, int v) {while(i<=m) {ft[i]+=v;i+=i&-i;}}
        inline int sum(int i) {int res=0;while(i>0) {res+=ft[i];i-=i&-i;}return res;}
};
fenwick_tree fen[2];
// inline int lowerL(int v) {return fen[0].sum(v-1);}
// inline int lowerR(int v) {return fen[1].sum(v-1);}
// inline int equalL(int v) {return fen[0].sum(v)-fen[0].sum(v-1);}
// inline int equalR(int v) {return fen[1].sum(v)-fen[1].sum(v-1);}
// inline int higherL(int v) {return fen[0].sum(n)-fen[0].sum(v);}
// inline int higherR(int v) {return fen[1].sum(n)-fen[1].sum(v);}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> n;
    for(int i=1; i<=n; ++i) {cin >> a[i];val.pb(a[i]);}
    sortunique(val);
    for(int i=1; i<=n; ++i) {
        a[i]=lower_bound(all(val),a[i])-val.begin()+1;
    }
    fen[0]=fenwick_tree(val.size()+3);
    fen[1]=fenwick_tree(val.size()+3);
    for(int i=1; i<=n; ++i) {fen[1].add(a[i],1);}
    //cout << fen[1].sum(1) << '\n';
    long long ans=0;
    for(int j=1; j<=n; ++j) {
        // fen[1].add(a[i],-1);
        // fen[0].add(a[i],1);
        // long long Ll=lowerL(a[i]),Lr=lowerR(a[i]),El=equalL(a[i])-1,Er=equalR(a[i]),Hl=higherL(a[i]),Hr=higherR(a[i]);
        // //cout << Ll << ' ' << Lr << ' ' << El << ' ' << Er << ' ' << Hl << ' ' << Hr << '\n';
        // ans+=Ll*Lr+Ll*Er+Er*Lr+El*Er+El*Hr+Hl*Er+Hl*Hr;
        fen[1].add(a[j], -1);
        int lowerL = fen[0].sum(a[j] - 1);
        int equalL = fen[0].sum(a[j]) - lowerL;
        int left_total = j - 1;
        int lowerR = fen[1].sum(a[j] - 1);
        int equalR = fen[1].sum(a[j]) - lowerR;
        int right_total = n - j;
        ll left_le = (ll)lowerL + equalL;
        ll left_ge = (ll)left_total - lowerL;
        ll right_le = (ll)lowerR + equalR;
        ll right_ge = (ll)right_total - lowerR;   
        ans += left_le * right_le + left_ge * right_ge - (ll)equalL * equalR;
        fen[0].add(a[j], 1);
        // fen[1].add(a[j],-1);
        // long long lle=lowerL(a[j])+equalL(a[j]),lge=higherL(a[j])+equalL(a[j]),rle=lowerR(a[j])+equalR(a[j]),rge=higherR(a[j])+equalR(a[j]);
        // ans+=lle*rle+lge*rge-equalL(a[j])*equalR(a[j]);
        // fen[0].add(a[j],1);
    }
    cout << ans;
    return 0; 

} 
/**/
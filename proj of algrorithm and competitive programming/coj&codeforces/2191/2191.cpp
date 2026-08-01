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
const int maxn=100005,mod=1000000007,maxb=320;
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
inline void start_timer() {imp_st=high_resolution_clock::now();}
inline void get_execution_time() {
    auto imp_en=high_resolution_clock::now();
    cerr << "Implementation Time: "<< duration_cast<milliseconds>(imp_en-imp_st).count() << " ms\n";
}
int n,q;
struct sqrt_decomposition{
    int n,block_size;
    vector<long long>a;
    vector<vector<long long>>block;
    sqrt_decomposition(vector<long long>&_a) {
        a=_a;
        n=a.size();
        block_size=sqrt(n);
        block.resize((n+block_size-1)/block_size);
        for(int i=0; i<n; ++i) {block[i/block_size].pb(a[i]);}
        for(auto &v:block) {sort(all(v));}
    }
    void update(int i, long long v) {
        int b=i/block_size;
        auto it1=lower_bound(all(block[b]),a[i]);
        block[b].erase(it1);
        auto it2=lower_bound(all(block[b]),v);
        block[b].insert(it2,v);
        a[i]=v;
    }
    long long query(int l, int r, long long x) {
        long long ans=0;
        int bl=l/block_size,br=r/block_size;
        if(bl==br) {
            for(int i=l; i<=r; ++i) if(a[i]>=x) ++ans;
            return ans;
        }
        int end_left=(bl+1)*block_size-1;
        for(int i=l; i<=end_left; ++i) if(a[i]>=x) ++ans;
        for(int i=bl+1; i<br; ++i) {
            int f=lower_bound(all(block[i]),x)-block[i].begin();
            ans+=(ll)block_size-f;
        }
        int start_right=br*block_size;
        for(int i=start_right; i<=r; ++i) if(a[i]>=x) ++ans;
        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;vector<long long>a(n);for(int i=0; i<n; ++i) cin >> a[i];
    sqrt_decomposition sd(a);
    cin >> q;
    for(int i=1; i<=q; ++i) {
        int t,l,r,x;
        cin >> t;
        if(t==0) {
            cin >> l >> r >> x;
            --l,--r;
            cout << sd.query(l,r,x) << '\n';
        }
        else {
            cin >> l >> x;
            --l;
            sd.update(l,x);
        }
    }
    return 0;
}
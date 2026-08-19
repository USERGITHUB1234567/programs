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
const int maxn=300005,mod=1000000007,maxb=320;
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
struct shooting_star{int l,r;long long a;}fst[maxn];
int n,m,o[maxn],k,a[maxn];
long long p[maxn];
vector<vector<int>>pos;
struct fenwick_tree{
    int num;
    vector<ll>ft;
    fenwick_tree(int num=0):num(num),ft(num+2,0){}
    inline void reset() {for(int i=1; i<=m+1; ++i) ft[i]=0;}
    inline void upd(int i, long long v) {
        while(i<=m+1) {
            ft[i]+=v;
            i+=i&-i;
        }
    }
    inline void range_update(int i, int j, long long v) {
        //if(j>i) return;
        upd(i,v);upd(j+1,-v);
    }
    inline long long sum(int i) {
        long long s=0;
        while(i>0) {
            s+=ft[i];
            i-=i&-i;
        }
        return s;
    }
};
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for(int i=1; i<=m; ++i) cin >> o[i];
    for(int i=1; i<=n; ++i) cin >> p[i];
    cin >> k;
    for(int i=1; i<=k; ++i) cin >> fst[i].l >> fst[i].r >> fst[i].a;
    pos.resize(n+1);
    for(int i=1; i<=m; ++i) pos[o[i]].pb(i);
    vector<int>l(n+1,1),r(n+1,k+1);
    for(int i=1; i<=n; ++i) if(p[i]<=0) {l[i]=0,r[i]=0;}
    fenwick_tree fen(m+2);
    while(true) {
        bool stop=true;
        vector<vector<int>>bucket(k+2);
        for(int i=1; i<=n; ++i) {
            if(l[i]<r[i]) {
                stop=false;
                int mid=(l[i]+r[i])>>1;
                bucket[mid].pb(i);
            }
        }
        if(stop) break;
        fen.reset();
        for(int ops=1; ops<=k; ++ops) {
            if(fst[ops].l<=fst[ops].r) fen.range_update(fst[ops].l,fst[ops].r,fst[ops].a);
            else {
                fen.range_update(fst[ops].l,m,fst[ops].a);
                fen.range_update(1,fst[ops].r,fst[ops].a);
            }
            if(bucket[ops].empty()) continue;
            for(int i:bucket[ops]) {
                long long s=0;
                for(int vt:pos[i]) {
                    s+=fen.sum(vt);
                    //cout << vt << '\n';
                    //cerr << fen.sum(vt) << '\n';
                    if(s>=p[i]) break;
                    //cout << s << '\n';
                }
                if(s>=p[i]) r[i]=ops;
                else l[i]=ops+1;
            }
        }
    }
    for(int i=1; i<=n; ++i) {
        if(l[i]==k+1) cout << "NO\n";
        else cout << l[i] << '\n';
    }
    return 0;
}
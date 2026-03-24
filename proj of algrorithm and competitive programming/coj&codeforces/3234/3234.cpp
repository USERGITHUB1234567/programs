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
void implement() {

}
auto imp_st=high_resolution_clock::now();
inline void start_timer() {imp_st=high_resolution_clock::now();}
inline void get_execution_time() {
    auto imp_en=high_resolution_clock::now();
    cerr << "Implementation Time: "<< duration_cast<milliseconds>(imp_en-imp_st).count() << " ms\n";
}
long long n,m,k,a[maxn],bs,ans[maxn],cur,cnt[3000006],pre[maxn];
struct query{
    int l,r,id;
    bool operator <(query o) {
        int b=l/bs,bo=o.l/bs;
        return (b<bo)||(b==bo && r<o.r);
    }
};
vector<query>queries;
void add(int i) {
    int t1=pre[i],t2=k^pre[i];
    if(i==-1) return;
    ++cnt[t1];
    cur+=cnt[t2];
}
void rem(int i) {
    int t1=pre[i],t2=k^pre[i];
    if(i==-1) return;
    --cnt[t1];
    cur-=cnt[t2];
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m >> k;
    for(int i=1; i<=n; ++i) {cin >> a[i];pre[i]=pre[i-1]^a[i];}
    for(int i,l,r; i<=m; ++i) {
        cin >> l >> r;
        queries.pb({l-1,r,i});
    }
    bs=sqrt(n);
    cnt[0]=1;
    sort(all(queries),[](query a,query b){return a<b;});
    int ql=1,qr=0;
    for(auto[l,r,id]:queries) {
        //cerr << id << '\n';
        while(ql<l) rem(ql++);
        while(ql>l) add(--ql);
        while(qr<r) add(++qr);
        while(qr>r) rem(qr--);
        ans[id]=cur;
    }
    for(int i=1; i<=m; ++i) cout << ans[i] << '\n';
    return 0;
}
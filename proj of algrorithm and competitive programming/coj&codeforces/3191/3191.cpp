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
const int maxn=200005,mod=1000000007;
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
long long a[maxn],n;
/* namespace soup1 {
    void solve() {
        long long s1=0,s2=0;
        for(int i=1; i<=n; i+=2) s1+=a[i];
        for(int i=2; i<=n; i+=2) s2+=a[i];
        cout << max(s1,s2);
    }
} */
/* struct segment_tree {
    pair<long long,int>st[4*maxn];
    inline pair<long long,int>merged(pair<long long,int>&a,pair<long long,int>&b) {
        if(a>=b) return a;
        return b;
    }
    void upd(int id, int l, int r, int i, pair<long long,int>v) {
        if(l>i || r<i) return;
        if(l==r) {st[id]=v;return;}
        int m=(l+r)>>1;
        if(i<=m) upd(id<<1,l,m,i,v);
        else upd(id<<1|1,m+1,r,i,v);
    }
    pair<long long,int> query(int id, int l, int r, int i, int j) {
        if(l>j || r<i) return 0;
        if(l>=i && r<=j) return st[id];
        int m=(l+r)>>1;
        return maxill(query(id<<1,l,m,i,j),query(id<<1|1,m+1,r,i,j));
    }
}seg; */
/*
f[i][0] max tai i khong lay a[i]
f[i][1] max tai i lay a[i]
*/
namespace soupfull {
    long long f[maxn][2];
    int cnt[maxn];
    void solve() {
        f[1][1]=a[1],f[1][0]=0;
        for(int i=2; i<=n; ++i) {
            //f[i][1]=1;

        }
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    auto imp_st=high_resolution_clock::now();
    file("3191")
    cin >> n;for(int i=1; i<=n; ++i) cin >> a[i];
    //soup1::solve();
    auto imp_en=high_resolution_clock::now();
    cerr << "Implementation Time: "<< duration_cast<milliseconds>(imp_en-imp_st).count() << " ms\n";
    return 0;
}
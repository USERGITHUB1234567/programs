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
#define int long long
using namespace std;
static const int maxd=1003;
typedef short bignum[maxd];
typedef long long ll;
typedef long double ld;
const int maxn=300005,mod=1000000007;
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
mt19937_64 generator1(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 generator2(chrono::high_resolution_clock::now().time_since_epoch().count());
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);}
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);}
int n;
long long k,a[maxn],pre[maxn],ans[maxn];
pair<ll,int>f[maxn];
struct segtree {
    pair<ll,ll> st[4*maxn];
    void build(int id, int l, int r, bool type) {
        if(l==r) {
            if(!type) st[id].fi=st[id].se=a[l];
            else st[id].se=f[l].fi;
            return;
        }
        int m=(l+r)>>1;
        build(id<<1,l,m,type);
        build(id<<1|1,m+1,r,type);
        st[id].fi=min(st[id<<1].fi,st[id<<1|1].fi);
        st[id].se=max(st[id<<1].se,st[id<<1|1].se);
    }
    long long querymin(int id, int l, int r, int i, int j) {
        if(l>j || r<i) return LLONG_MAX;
        if(l>=i && r<=j) return st[id].fi;
        int m=(l+r)>>1;
        return min(querymin(id<<1,l,m,i,j),querymin(id<<1|1,m+1,r,i,j));
    }
    long long querymax(int id, int l, int r, int i, int j) {
        if(l>j || r<i) return LLONG_MIN;
        if(l>=i && r<=j) return st[id].se;
        int m=(l+r)>>1;
        return max(querymax(id<<1,l,m,i,j),querymax(id<<1|1,m+1,r,i,j));
    }
}seg;
signed main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("pt")
    scanf("%d%lld",&n,&k);
    for(int i=1; i<=n; ++i) {scanf("%lld",&a[i]);pre[i]=pre[i-1]+a[i];}
    int l=1,r=1;
    seg.build(1,1,n,false);
    while(r<=n) {
        while(l<r && seg.querymax(1,1,n,l,r)-seg.querymin(1,1,n,l,r)>k) ++l;
        f[r]={pre[r]-pre[l-1],l};
        ++r;
    }
    seg.build(1,1,n,true);
    long long kq=0;
    for(int i=1; i<=n; ++i) {
        int j=f[i].se;
        if(j>1) {
            long long val=seg.querymax(1,1,n,1,j-1);
            if(val+pre[i]-pre[j-1]>kq) kq=val+pre[i]-pre[j-1];
        } else {
            kq=max(kq,f[i].fi);
        }
    }
    //cout << f[3].fi << " " << f[3].se << "\n";
    /* for(int i=1; i<=n; ++i) {
        cout << f[i].fi << " " << f[i].se << "\n";
    } */
    printf("%lld",kq);
    return 0;
}
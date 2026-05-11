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
mt19937_64 generator1(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 generator2(chrono::high_resolution_clock::now().time_since_epoch().count());
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);}
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);}
int n,q,l,r,id1,id2;
long long a[maxn];
struct segtree {
    struct node {ll mx1,mx2,mn1,mn2; };
    node st[maxn<<2];
    node merge(const node &L, const node &R) {
        node res;
        if (L.mx1>R.mx1) {
            res.mx1=L.mx1;
            res.mx2=max(L.mx2,R.mx1);
        } else {
            res.mx1=R.mx1;
            res.mx2=max(L.mx1,R.mx2);
        }
        if (L.mn1<R.mn1) {
            res.mn1=L.mn1;
            res.mn2=min(L.mn2,R.mn1);
        } else {
            res.mn1=R.mn1;
            res.mn2=min(L.mn1,R.mn2);
        }
        return res;
    }
    void build(int id,int l,int r) {
        if (l==r) {
            ll v=a[l];
            st[id]={v,LLONG_MIN,v,LLONG_MAX};
            return;
        }
        int m=(l+r)>>1;
        build(id<<1,l,m);
        build(id<<1|1,m+1,r);
        st[id]=merge(st[id<<1],st[id<<1|1]);
    }
    node query(int id, int l, int r, int ql, int qr) {
        if (r<ql || l>qr) return {LLONG_MIN, LLONG_MIN, LLONG_MAX, LLONG_MAX};
        if (l>=ql && r<=qr) return st[id];
        int m=(l+r)>>1;
        node L=query(id<<1,l,m,ql,qr);
        node R=query(id<<1|1,m+1,r,ql,qr);
        return merge(L,R);
    }
} seg;
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    //file("mahoa")
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    cin >> q;
    seg.build(1,1,n);
    while(q--) {
        cin >> l >> r;
        /* id1=seg.query(1,1,n,l,r).i1;
        id2=seg.query(1,1,n,l,r).i2;
        ll mx1=seg.query(1,1,n,l,r).mx,mi1=seg.query(1,1,n,l,r).mi;
        seg.upd(1,1,n,id1,LLONG_MIN);seg.upd(1,1,n,id2,LLONG_MAX);
        ll mx2=seg.query(1,1,n,l,r).mx,mi2=seg.query(1,1,n,l,r).mi;
        seg.upd(1,1,n,id1,mx1);seg.upd(1,1,n,id2,mi1);
        cout << maxill((mx1*mx2),(mi1*mi2)) << '\n'; */
        auto nd=seg.query(1,1,n,l,r);
        ll ans1=nd.mx1*nd.mx2,ans2=nd.mn1*nd.mn2;
        cout << max(ans1,ans2) << "\n";
    }
    return 0;
}
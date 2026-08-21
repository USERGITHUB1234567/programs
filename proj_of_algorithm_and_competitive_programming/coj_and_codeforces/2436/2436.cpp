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
const int maxn=50004,mod=1000000007;
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
int a[maxn],n,comp[maxn],f[6][maxn];
vector<int>val;
struct segtree {
    int st[maxn<<2];
    void init() {memset(st,0,sizeof(st));}
    void build(int id, int l, int r) {
        if(l==r) {
            st[id]=a[l];
            return;
        }
        int m=(l+r)>>1;
        build(id<<1,l,m);
        build(id<<1|1,m+1,r);
        st[id]=maxi(st[id<<1],st[id<<1|1]);
    }
    void upd(int id, int l, int r, int i, int v) {
        if(r<i || l>i) return;
        if(l==r) {
            st[id]=v;
            return;
        }
        int m=(l+r)>>1;
        if(i<=m) upd(id<<1,l,m,i,v);
        else upd(id<<1|1,m+1,r,i,v);
        st[id]=maxi(st[id<<1],st[id<<1|1]);
    }
    int query(int id, int l, int r, int i, int j) {
        if(l>j || r<i) return 0;
        if(l>=i && r<=j) return st[id];
        int m=(l+r)>>1;
        return maxi(query(id<<1,l,m,i,j),query(id<<1|1,m+1,r,i,j));
    }
}seg[6];
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> a[i];
        val.pb(a[i]);
    }
    sortunique(val);
    for(int i=1; i<=n; ++i) {
        a[i]=(lower_bound(all(val),a[i])-val.begin())+1;
    }
    for(int i=0; i<=4; ++i) seg[i].init();
    /*for(int i=1; i<=4; ++i) {
        for(int j=1; j<=n; ++j) {
            //f[i][j]=maxi(seg[i-1].query(1,1,n,i,j),seg[i].query(1,1,n,i,j));

        }
    }*/
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=4; ++j) {
            if(j&1) {
                int t=seg[j].query(1,1,n,1,a[i]-1);
                if(t) f[j][i]=maxi(f[j][i],1+t);
                t=seg[j-1].query(1,1,n,1,a[i]-1);
                if(t) {
                    f[j][i]=maxi(f[j][i],1+t);
                    seg[j].upd(1,1,n,a[i],f[j][i]);
                }
            }
            else {
                int t=seg[j].query(1,1,n,a[i]+1,n);
                if(t) f[j][i]=maxi(f[j][i],1+t);
                t=seg[j-1].query(1,1,n,a[i]+1,n);
                if(t) {
                    f[j][i]=maxi(f[j][i],1+t);
                    seg[j].upd(1,1,n,a[i],f[j][i]);
                }
            }
            
        }
        seg[0].upd(1,1,n,a[i],1);
    }
    int ans=0;
    for(int i=1; i<=n; ++i) ans=max(ans,f[4][i]);
    cout << ans;
    return 0;
}
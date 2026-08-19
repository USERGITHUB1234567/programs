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
int t;
long long qu[maxn];
namespace soup2 {
    int divn[1000006];
    void snt() {
        memset(divn, 0, sizeof(divn));
        divn[1]=1;
        for(int i=2; i<1000006/2; ++i) {
            ++divn[i];
            for(int j=i; j<1000006; j+=i) ++divn[j];
        }
    }
    struct segtree {
        pair<int,int> st[1000006<<2];
        pair<int,int>mergest(pair<int,int>a, pair<int,int>b) {
            if(a.fi>b.fi) return {a.fi,a.se};
            if(a.fi==b.fi && a.se>b.se) return {b.fi,b.se};
            return {b.fi,b.se};
        }
        void build(int id, int l, int r) {
            if(l==r) {
                st[id]={divn[l],l};
                return;
            }
            int m=(l+r)>>1;
            build(id<<1,l,m);
            build(id<<1|1,m+1,r);
            st[id]=mergest(st[id<<1],st[id<<1|1]);
        }
        pair<int,int>query(int id, int l, int r,int i, int j) {
            if(l>j || r<i) return {0,INT_MAX};
            if(l>=i && r<=j) return st[id];
            int m=(l+r)>>1;
            return mergest(query(id<<1,l,m,i,j),query(id<<1|1,m+1,r,i,j));
        }
    }seg;
    void solve() {
        snt();
        //cout << divn[5040];
        seg.build(1,1,1000005);
        for(int i=1; i<=t; ++i) {
            pair<int,int>ans=seg.query(1,1,1000005,1,qu[i]);
            cout << ans.se << " " << ans.fi << "\n";
        }
    }
}
namespace soupfull {
    const int maxar=10000007;
    bool nt[maxar];
    long long cur=1,pre=1;
    void snt() {
        nt[0]=nt[1]=false;
        for(int i=2; i*i<maxar; ++i) {
            if(nt[i]) {
                int j=i*i;
                while(j<maxar) {
                    nt[j]=false;
                    j+=i;
                }
            }
        }
    }
    void solve() {
        vector<long long>pr;
        for(int i=1; i<maxar; ++i) {
            if(nt[i]) pr.pb(i);
        }
        for(int i=1; i<=t; ++i) {
            long long n=qu[i];
            
        }
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("bai1")
    cin >> t;
    for(int i=1; i<=t; ++i) cin >> qu[i];
    soup2::solve();
    return 0;
}
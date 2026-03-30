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
const int maxn=100005,mod=1000000007,maxb=320; 
namespace mathematics{ 
    long long fact[maxn],ifact[maxn]; 
    long long __gcd(long long a, long long b) { if(a<b) swap(a,b); while(a%b!=0) {long long c=a%b;a=b,b=c;} return b; } 
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
int n,m,q;
pair<int,int>edge[maxn],queries[maxn<<1],range[maxn];
struct disjoint_set_union{
    int p[maxn];
    disjoint_set_union() {for(int i=1; i<=n; ++i) p[i]=i;}
    int found(int u) {return (p[u]==u?u:p[u]=found(p[u]));}
    void unite(int u, int v) {
        u=found(u),v=found(v);
        if(u==v) return;
        p[v]=u;
    }
};
namespace soup{
    void solve() {
        while(true) {
            //cerr << 1;
            bool stop=true;
            vector<int>bucket[m+1];
            for(int i=1; i<=q; ++i) {
                if(range[i].fi!=range[i].se) {
                    stop=false;
                    int mid=(range[i].fi+range[i].se)>>1;
                    bucket[mid].pb(i);
                }
            }
            if(stop) break;
            disjoint_set_union dsu;
            for(int e=1; e<=m; ++e) {
                auto[u,v]=edge[e];
                dsu.unite(u,v);
                for(int i:bucket[e]) {
                    auto[l,r]=queries[i];
                    bool ck=true;
                    int t=dsu.found(l);
                    for(int j=l+1; j<=r; ++j) {
                        int p=dsu.found(j);
                        if(p!=t) {ck=false;break;}
                    }
                    if(ck) range[i].se=e;
                    else range[i].fi=e+1;
                }
            }
        }
        for(int i=1; i<=q; ++i) {
            cout << range[i].fi << '\n';
        }
    }
}
struct segmentree{
    int st[maxn<<2];
    void build(int id, int l, int r) {

    }
    void update(int id, int l, int r, int i, int v) {
        if(l==r) {
            st[id]=v;
            return;
        }
        int mid=(l+r)>>1;
        if(i<=mid) update(id<<1,l,mid,i,v);
        else update(id<<1|1,mid+1,r,i,v);
        st[id]=max(st[id<<1],st[id<<1|1]);
    }
    int query(int id, int l, int r, int i, int j) {
        if(l>j ||r<i) return 0;
        if(l>=i && r<=j) return st[id];
        int mid=(l+r)>>1;
        return max(query(id<<1,l,mid,i,j),query(id<<1|1,mid+1,r,i,j));
    }
}seg;
namespace soupfull {
    int f[maxn],p[maxn],sz[maxn];
    vector<int>comp[maxn];
    int findp(int u) {return (p[u]==u?u:p[u]=findp(p[u]));}
    inline void unite(int u, int v, int e) {
        u=findp(u),v=findp(v);
        if(u==v) return;
        if(sz[u]<sz[v]) swap(u,v);
        cout << u << ' ' << v << '\n';
        for(int x:comp[v]) {
            if(x>1 && findp(x-1)==u) {
                f[x-1]=min(f[x-1],e);
            }
            if(x<n && findp(x+1)==u) {
                f[x]=min(f[x],e);
            }
        }
        for(int x:comp[v]) comp[u].push_back(x);
        p[v]=u;
        sz[u]+=sz[v];
        comp[v].clear();
    }
    inline bool query(int i, int mid) {
        auto[l,r]=queries[i];
        return seg.query(1,1,n,l,r-1)<=mid;
    }
    void solve() {
        for(int i=1; i<=n; ++i) {p[i]=i;if(i<n) f[i]=INT_MAX;comp[i].pb(i);}
        f[n]=0;
        for(int i=1; i<=m; ++i) {
            auto[u,v]=edge[i];
            unite(u,v,i);
        }
        for(int i=1; i<=n; ++i) seg.update(1,1,n,i,f[i]);
        //for(int i=1; i<=n; ++i) cout << f[i] << ' ';
        while(true) {
            //cerr << 'a';
            bool stop=true;
            vector<int>bucket[m+1];
            for(int i=1; i<=q; ++i) {
                if(range[i].fi!=range[i].se) {
                    stop=false;
                    int mid=(range[i].fi+range[i].se)>>1;
                    bucket[mid].pb(i);
                }
            }
            if(stop) break;
            for(int e=1; e<=m; ++e) {
                for(int i:bucket[e]) {
                    if(query(i,e)) range[i].se=e;
                    else range[i].fi=e+1;
                }
            }
        }
        for(int i=1; i<=q; ++i) cout << range[i].fi << '\n';
    }
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    //file("vertices")
    cin >> n >> m >> q;
    for(int i=1; i<=m; ++i) cin >> edge[i].fi >> edge[i].se;
    for(int i=1; i<=q; ++i) {
        cin >> queries[i].fi >> queries[i].se;
        if(queries[i].fi==queries[i].se) range[i].fi=0,range[i].se=0;
        else range[i].fi=0,range[i].se=m;
    }
    // soup::solve();
    // cout << '\n' ;
    soupfull::solve();
    return 0; 

} 
/**/
/*

5 5 5
1 2
1 3
2 4
3 4
3 5
1 4
3 4
2 2
2 5
3 5

*/
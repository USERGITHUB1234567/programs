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
const int maxn=400005,mod=1000000007,maxb=320; 
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
int n,head[maxn],heavy[maxn],p[maxn],pos[maxn],d[maxn],cur=0;
int up[maxn][20],logn,cnt[maxn];
vector<int>adj[maxn];
struct segment_tree{
    long long st[maxn<<2],laz[maxn];
    void down(int id, int l, int r) {
        if(id<<1>(maxn<<2) || !laz[id]) return;
        long long t=laz[id];
        int mid=(l+r)>>1;
        st[id<<1]+=(mid-l+1)*t;
        st[id<<1|1]+=(r-mid)*t;
        laz[id<<1]+=t;
        laz[id<<1|1]+=t;
        laz[id]=0;
    }
    void update(int id, int l, int r, int i, int j, long long v) {
        down(id,l,r);
        if(l>j || r<i) return;
        if(l>=i && r<=j) {
            st[id]+=(r-l+1)*v;
            laz[id]+=v;
            return;
        }
        int mid=(l+r)>>1;
        if(i<=mid) update(id<<1,l,mid,i,j,v);
        if(j>mid) update(id<<1|1,mid+1,r,i,j,v);
    }
    long long query(int id, int l, int r, int i) {
        down(id,l,r);
        if(l>i || r<i) return 0;
        if(l==r) return st[id];
        int mid=(l+r)>>1;
        if(i<=mid) return query(id<<1,l,mid,i);
        else return query(id<<1|1,mid+1,r,i);
    }
}seg;
void hldupdate(int a, int b) {
    for(;head[a]!=head[b];b=p[head[b]]) {
        if(d[head[a]]>d[head[b]]) swap(a,b);
        seg.update(1,1,n,pos[head[b]],pos[b],1);
    }
    if(d[a]>d[b]) swap(a,b);
    seg.update(1,1,n,pos[a],pos[b],1);
}
int dfs(int u) {
    int sz=1,szm=0;
    for(int v:adj[u]) {
        if(p[u]==v) continue;
        p[v]=u;
        up[v][0]=u;
        d[v]=d[u]+1;
        int csz=dfs(v);
        sz+=csz;
        if(csz>szm) {
            heavy[u]=v;
            szm=csz;
        }
    }
    return sz;
}
inline void decompose(int u, int h) {
    head[u]=h;
    pos[u]=++cur;
    if(heavy[u]) decompose(heavy[u],h);
    for(int v:adj[u]) {
        if(v!=heavy[u] && v!=p[u]) decompose(v,v);
    }
}

int lca(int u, int v) {
    if(d[u]<d[v]) swap(u,v);
    int dif=d[u]-d[v];
    for(int i=logn; i>=0; --i) {
        if((1<<i)&dif) u=up[u][i];
    }
    if(u==v) return u;
    for(int i=logn; i>=0; --i) {
        if(up[u][i]!=up[v][i]) {u=up[u][i],v=up[v][i];}
    }
    return up[u][0];
}
void dfsans(int u) {
    for(int v:adj[u]) {
        if(v==p[u]) continue;
        dfsans(v);
        cnt[u]+=cnt[v];
    }
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> n;
    for(int i=1,u,v; i<n; ++i) {cin >> u >> v;adj[u].pb(v);adj[v].pb(u);}
    dfs(1);
    decompose(1,1);
    // for(int i=1; i<n; ++i) {
    //     hldupdate(i,i+1);
    // }
    // for(int i=1; i<=n; ++i) {
    //     cout << seg.query(1,1,n,pos[i]) << '\n';
    // }
    logn=log2(n)+1;
    for(int j=1; j<=logn; ++j) {
        for(int i=1; i<=n; ++i) up[i][j]=up[up[i][j-1]][j-1];
    }
    for(int i=1; i<n; ++i) {
        int l=lca(i,i+1);
        ++cnt[i],++cnt[i+1];
        --cnt[l];
        if(up[l][0]) --cnt[up[l][0]];
    }
    dfsans(1);
    for(int i=1; i<=n; ++i) cout << cnt[i] << '\n';
    return 0; 

} 
/**/

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
int n,up[maxn][20],d[maxn],st[maxn],en[maxn],timer=0;
vector<int>adj[maxn];
namespace soup2{
    void solve() {
        long long ans=0;
        for(int i=1; i<=n; ++i) {
            ans+=(n+i-1)/(i+1);
        }
        cout << ans;
    }
}
namespace soup1{
    bool mk[maxn];
    int mxd[maxn],d[maxn];
    int k;
    inline void dfsinit(int u, int p) {
        for(int v:adj[u]) {
            if(v==p) continue;
            d[v]=d[u]+1;
            dfsinit(v,u);
        }
    }
    inline void dfs(int u, int p) {
        mxd[u]=d[u];
        for(int v:adj[u]) {
            if(v==p) continue;
            dfs(v,u);
            mxd[u]=max(mxd[u],mxd[v]);
        }
        if(-d[u]+mxd[u]>=k) {
            //if(u==2) cout << 'a';
            mk[u]=true;
            mxd[u]=d[u]-1;
        }
    }
    void solve() {
        long long ans=0;
        dfsinit(1,0);
        for(int i=1; i<=n; ++i) {
            k=i;
            for(int j=1; j<=n; ++j) {mk[j]=false;}
            dfs(1,0);
            mk[1]=true;
            for(int j=1; j<=n; ++j) ans+=mk[j];
            //cout << ans << '\n';
        }
        cout << ans;
    }
}
int a[maxn];
class segtree{
    private:
        pair<int,int> st[maxn<<2];
        int laz[maxn<<2];
        vector<pair<int,pair<int,int>>>rollback;
    public:
        inline bool check() {return !st[1].fi;}
        void down(int id) {
            if((id<<1)>=(maxn<<2) || !laz[id]) return;
            int t=laz[id];
            rollback.pb({id<<1,st[id<<1]});
            rollback.pb({id<<1|1,st[id<<1|1]});
            st[id<<1]={t,st[id<<1].se};
            st[id<<1|1]={t,st[id<<1|1].se};
            laz[id<<1]=t;
            laz[id<<1|1]=t;
            laz[id]=0;
        }
        void build(int id, int l, int r) {
            if(l==r) {
                st[id]={d[a[l]],a[l]};
                return;
            }
            int mid=(l+r)>>1;
            build(id<<1,l,mid);
            build(id<<1|1,mid+1,r);
            st[id]=max(st[id<<1],st[id<<1|1]);
        }
        void update(int id, int l, int r, int i, int j, int v) {
            //down(id);
            if(l>j || r<i) return;
            if(l>=i && r<=j) {
                rollback.pb({id,st[id]});
                st[id].fi=v;
                laz[id]=v;
                return;
            }
            int mid=(l+r)>>1;
            if(i<=mid) update(id<<1,l,mid,i,j,v);
            if(j>mid) update(id<<1|1,mid+1,r,i,j,v);
            rollback.pb({id,st[id]});
            st[id]=max(st[id<<1],st[id<<1|1]);
        }
        void eroll() {
            while(!rollback.empty()) {
                auto[u,v]=rollback.back();
                rollback.pop_back();
                st[u]=v;
                //cerr << 'a';
            }
        }
        int query() {
            return st[1].se;
        }
}seg;
namespace soupfull{
    int logn;
    inline void dfs(int u, int p) {
        st[u]=++timer;
        for(int v:adj[u]) {
            if(v==p) continue;
            d[v]=d[u]+1;
            up[v][0]=u;
            dfs(v,u);
        }
        en[u]=timer;
    }
    inline int jump(int u, int k) {
        for(int i=logn; i>=0; --i) {
            if(k&(1<<i)) u=up[u][i];
        }
        return u;
    }
    void solve() {d[1]=1;
        dfs(1,0);
        
        logn=log2(n);
        for(int j=1; j<=logn; ++j) {
            for(int i=1; i<=n; ++i) up[i][j]=up[up[i][j-1]][j-1];
        }
        for(int i=1; i<=n; ++i) {
            a[st[i]]=i;
        }
        seg.build(1,1,n);
        int ans=0;
        for(int k=1; k<=n; ++k) {
            bool ck=false;
            while(!seg.check()) {
                ++ans;
                int u=seg.query();
                int v=jump(u,k);
                //cerr << v << '\n';
                if(v==1) break;
                if(v!=0) seg.update(1,1,n,st[v],en[v],0);
                else break;
                //cerr << 'b';
            }
            //ans+=ck^1;
            seg.eroll();
        }
        cout << ans;
    }
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> n;
    for(int i=1,u,v; i<n; ++i) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // if(n<=5000) soup1::solve();
    // else soup2::solve();
    soupfull::solve();
    return 0; 

} 
/**/
/*
4
1 2
2 3
2 4

5



6
1 2
1 3
1 4
4 5
4 6

7
*/
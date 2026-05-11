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
        pair<int,int> st_tree[maxn<<2];
        int laz[maxn<<2];
    public:
        inline bool check() {return st_tree[1].fi < 0;}
        void build(int id, int l, int r) {
            laz[id] = 0;
            if(l==r) {
                st_tree[id]={d[a[l]],a[l]};
                return;
            }
            int mid=(l+r)>>1;
            build(id<<1,l,mid);
            build(id<<1|1,mid+1,r);
            st_tree[id]=max(st_tree[id<<1],st_tree[id<<1|1]);
        }
        void update(int id, int l, int r, int i, int j, int v) {
            if(l>j || r<i) return;
            if(l>=i && r<=j) {
                laz[id] += v;
            } else {
                int mid=(l+r)>>1;
                update(id<<1,l,mid,i,j,v);
                update(id<<1|1,mid+1,r,i,j,v);
            }
            if(laz[id] > 0) st_tree[id] = {-1, 0};
            else {
                if(l == r) st_tree[id] = {d[a[l]], a[l]};
                else st_tree[id] = max(st_tree[id<<1], st_tree[id<<1|1]);
            }
        }
        int query() {
            return st_tree[1].se;
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
            if(k&(1<<i)) {
                u=up[u][i];
                if(u == 0) return 1;
            }
        }
        return u == 0 ? 1 : u;
    }

    int memo[maxn];
    ll get_f(int k) {
        if (memo[k] != -1) return memo[k];
        int ans = 0;
        vector<int> undo;
        while (!seg.check()) {
            int u = seg.query();
            int v = jump(u, k);
            seg.update(1, 1, n, st[v], en[v], 1);
            undo.pb(v);
            ++ans;
        }
        for (int v : undo) {
            seg.update(1, 1, n, st[v], en[v], -1);
        }
        return memo[k] = ans;
    }

    ll total_ans = 0;
    void solve_range(int l, int r, int fl, int fr) {
        if (fl == fr) {
            total_ans += 1LL * fl * (r - l + 1);
            return;
        }
        if (l + 1 == r) {
            total_ans += fl + fr;
            return;
        }
        int mid = (l + r) >> 1;
        int fmid = get_f(mid);
        solve_range(l, mid, fl, fmid);
        solve_range(mid + 1, r, fmid, fr);
    }

    void solve() {
        timer = 0;
        d[1] = 0;
        dfs(1,0);
        logn=18;
        for(int j=1; j<=logn; ++j) {
            for(int i=1; i<=n; ++i) up[i][j]=up[up[i][j-1]][j-1];
        }
        for(int i=1; i<=n; ++i) {
            a[st[i]]=i;
        }
        seg.build(1,1,n);
        
        for(int i=1; i<=n; ++i) memo[i] = -1;
        
        int max_depth = 0;
        for (int i = 1; i <= n; ++i) max_depth = max(max_depth, d[i]);
        
        if (max_depth == 0) {
            cout << n << "\n";
            return;
        }

        int f1 = get_f(1);
        int fmax = get_f(max_depth);
        total_ans = 0;
        solve_range(1, max_depth, f1, fmax);
        
        if (n > max_depth) {
            total_ans += 1LL * (n - max_depth) * 1;
        }
        
        cout << total_ans << '\n';
    }
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    if(!(cin >> n)) return 0;
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
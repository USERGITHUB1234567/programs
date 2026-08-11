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
mt19937_64 generator1(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 generator2(chrono::high_resolution_clock::now().time_since_epoch().count());
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);}
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);}
int n,d[maxn],st[maxn],en[maxn],timer=0;
vector<pair<int,int>>adj[maxn];
struct fenwick_tree {
    int bit[maxn];
    fenwick_tree() {memset(bit,0,sizeof(bit));}
    int sum(int i) {int res=0;while(i>0){res+=bit[i];i-=i&-i;}return res;}
    void upd(int i, int v) {while(i<=n){bit[i]+=v;i+=i&-i;}}
}ft;
int kq=INT_MAX,logn,up[maxn][20],de[maxn];
void dfslca(int u, int p) {
    for(auto [v,i]:adj[u]) {
        if(v==p) continue;
        up[v][0]=u;
        de[v]=de[u]+1;
        dfslca(v,u);
    }
}
int lca(int u, int v) {
    if(de[u]<de[v]) swap(u,v);
    for(int i=logn; i>=0; --i) {
        if(de[up[u][i]]>=de[v]) u=up[u][i];
    }
    if(u==v) return u;
    for(int i=logn; i>=0; --i) {
        if(up[u][i]!=up[v][i]) {
            u=up[u][i];
            v=up[v][i];
        }
    }
    return up[u][0];
}
int dfssetup(int u, int p) {
    int sz=1;
    for(auto [v,i]:adj[u]) {
        if(v==p) continue;
        sz+=dfssetup(v,u);
    }
    d[u]=sz;
    return sz;
}
namespace soup1 {
    bool cut[maxn],vis[maxn];
    int res=INT_MAX;
    int bfs(int s) {
        int kq=0;
        queue<int>q;
        q.push(s);
        while(!q.empty()) {
            int u=q.front();q.pop();
            vis[u]=true;++kq;
            for(auto [v,i]:adj[u]) {
                if(vis[v] || cut[i]) continue;
                q.push(v);
            }
        }
        return kq;
    }
    void solve() {
        for(int i=1; i<n; ++i) {
            for(int j=i+1; j<n; ++j) {
                for(int k=1; k<=n; ++k) vis[k]=false;
                cut[i]=cut[j]=true;
                vector<int>ans;
                for(int k=1; k<=n; ++k) {
                    if(!vis[k]) ans.pb(bfs(k));
                }
                sort(all(ans));
                res=min(res,ans[2]-ans[0]);
                cut[i]=cut[j]=false;
            }
        }
        printf("%d",res);
    }
}
namespace soup1and2 {
    void solve() {
        dfssetup(1,0);
        dfslca(1,0);
        logn=log(2,n);
        for(int j=1; j<=logn; ++j) {
            for(int i=1; i<=n; ++i) up[i][j]=up[up[i][j-1]][j-1];
        }
        for(int i=1; i<=n; ++i) {
            for(int j=1,u,v; j<=n; ++j) {
                u=i;v=j;
                if(d[u]<d[v]) swap(u,v);
                if(lca(u,v)==u) {
                    int t1=d[v]-1,t2=(d[u]-d[v]),t3=d[1]-d[u]+1;
                    int mi=min({t1,t2,t3}),ma=max({t1,t2,t3});
                    kq=min(kq,ma-mi);
                }
                else {
                    int t1=d[u]-1,t2=d[v]-1,t3=d[1]-d[lca(u,v)]+1;
                    int mi=min({t1,t2,t3}),ma=max({t1,t2,t3});
                    kq=min(kq,ma-mi);
                }
            }
        }
        printf("%d",kq);
    }
}
namespace soupfull {
    set<int> a,b;
    vector<int> closest(int x, set<int>& st) {
        vector<int> res;
        if (st.empty()) return res;
        auto it = st.lower_bound(x);
        if (it != st.end()) res.pb(*it);
        if (it != st.begin()) { auto it2 = it; --it2; res.pb(*it2); }
        return res;
    }
    int dif(int x,int y,int z) { return max({x,y,z})-min({x,y,z}); }
    int dfs(int u, int p) {
        int res=INT_MAX;
        {
            int key = (n + d[u]) / 2;
            vector<int> cl = closest(key, a);
            for (auto sv: cl) {
                int cand = dif(d[u], sv - d[u], n - sv);
                res = min(res, cand);
            }
        }
        {
            int key = (n - d[u]) / 2;
            vector<int> cl = closest(key, b);
            for (auto sv: cl) {
                int cand = dif(d[u], sv, n - d[u] - sv);
                res = min(res, cand);
            }
        }
        a.insert(d[u]);
        for(auto [v,i]:adj[u]) {
            if(v==p) continue;
            res=min(res,dfs(v,u));
        }
        a.erase(d[u]);
        b.insert(d[u]);
        return res;
    }
    void solve() {
        dfssetup(1,0);
        printf("%d",dfs(1,0));
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("chili")
    scanf("%d",&n);
    for(int i=1,u,v; i<n; ++i) {scanf("%d%d",&u,&v);adj[u].pb({v,i});adj[v].pb({u,i});}
    soupfull::solve();
    return 0;
}

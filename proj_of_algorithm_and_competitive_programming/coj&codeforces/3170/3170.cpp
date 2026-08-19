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
int n,s,q,e;
vector<pair<pair<int,ll>,int>>adj[maxn];
pair<pair<int,ll>,int>edge[maxn];
bool store[maxn];
namespace soup1and2 {
    long long i,r;
    ll di[maxn];
    void dfs(int u, int p, int f) {
        for(auto t:adj[u]) {
            auto [v,w]=t.fi;
            auto i=t.se;
            if(v==p) continue;
            if(i==f) continue;
            di[v]=di[u]+w;
            dfs(v,u,f);
        }
    }
    void solve() {
        while(q--) {
            cin >> i >> r;
            int u=edge[i].fi.fi,v=edge[i].fi.se;
            ll d=LLONG_MAX;
            for(int j=1; j<=n; ++j) di[j]=-1;
            di[r]=0;
            dfs(r,0,i);
            if(di[e]!=-1) {
                cout << "escaped\n";
            } else {
                for(int j=1; j<=n; ++j) {
                    //cout << di[j] << " ";
                    if(store[j] && di[j]!=-1) {
                        d=min(d,di[j]);
                    } 
                }
                if(d==LLONG_MAX) cout << "oo" << '\n'; else cout << d << '\n';
            }
        }
    }
}
namespace soup3 {
    int st[maxn],en[maxn],timer=0,d[maxn];
    void dfs(int u, int p) {
        st[u]=en[u]=++timer;
        for(auto t:adj[u]) {
            auto[v,w]=t.fi;
            auto id=t.se;
            if(v==p) continue;
            d[v]=d[u]+1;
            dfs(v,u);
        }
        en[u]=timer;
    }
    void solve() {
        d[e]=0;
        dfs(e,0);
        while(q--) {
            int i,r;
            cin >> i >> r;
            int u=edge[i].fi.fi,v=edge[i].fi.se;
            if(st[u]>st[v]) swap(u,v);
            if(st[r]<st[v] || en[r]>en[v]) cout << "escaped\n";
            else cout << "0\n";
        }
    }
}
namespace soupfull {
    int st[maxn],en[maxn],timer=0,up[maxn][20],h[maxn],logn;
    ll magic[maxn][20],d[maxn],md[maxn];
    void dfs(int u, int p) {
        up[u][0]=p;
        st[u]=++timer;
        md[u]=(store[u]?d[u]:1e18);
        for(auto t:adj[u]) {
            auto[v,w]=t.fi;
            auto id=t.se;
            if(v==p) continue;
            d[v]=d[u]+w;
            h[v]=h[u]+1;
            dfs(v,u);
            md[u]=min(md[u],md[v]);
        }
        en[u]=timer;
    }
    ll best(int r, int v) {
        int dist=h[r]-h[v]+1;
        ll ans=1e18;
        for(int j=logn;j>=0; --j) {
            if(((dist>>j)&1)==1) {
                ans=min(ans,magic[r][j]);
                r=up[r][j];
            }
        }
        return ans;
    }
    void solve() {
        logn=(int)log(2,n);
        d[e]=0;
        h[e]=0;
        dfs(e,0);
        for(int i=1; i<=n; ++i) {
            magic[i][0]=(md[i]==1e18?1e18:md[i]-2*d[i]);
        }
        for(int j=1; j<=logn; ++j) {
            for(int i=1; i<=n; ++i) {
                up[i][j]=up[up[i][j-1]][j-1];
                magic[i][j]=min(magic[i][j-1],magic[up[i][j-1]][j-1]);
            }
        }
        while(q--) {
            int i,r;
            cin >> i >> r;
            int v=edge[i].fi.fi;
            if(st[edge[i].fi.fi]<st[edge[i].fi.se]) v=edge[i].fi.se;
            if(st[r]<st[v] || en[r]>en[v]) cout << "escaped\n";
            else {
                ll res=best(r,v);
                if(res==1e18) cout << "oo\n";
                else cout << d[r]+res << "\n";
            }
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("3170")
    cin >> n >> s >> q >> e;
    for(int i=1,u,v,w; i<n; ++i) {
        cin >> u >> v >> w;
        edge[i]={{u,v},w};
        adj[u].pb({{v,w},i});
        adj[v].pb({{u,w},i});
    }
    for(int i=1,c; i<=s; ++i) {
        cin >> c;
        store[c]=true;
    }
    if(s==n) {
        soup3::solve();
        return 0;
    }
    //soup1and2::solve();
    /* if(n<=1000 && q<=1000) {
        soup1and2::solve();
        return 0;
    } */
    soup1and2::solve();
    return 0;
}

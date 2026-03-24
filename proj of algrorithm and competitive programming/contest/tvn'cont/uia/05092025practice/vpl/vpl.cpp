#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define forw(i,a,b) for(int (i)=(a); (i)<=(b); ++(i))
#define forb(i,a,b) for(int (i)=(a); (i)>=(b); --(i))
#define pb push_back
#define eb emplace_back
#define uni(x) sort(all(x)); x.erase(unique(all(x)), x.end())
#define mp make_pair
#define fi first
#define se second
#define file(n) freopen(n".inp", "r", stdin); freopen(n".out", "w", stdout);
using namespace std;
typedef long long ll;
const int maxn=1000006,maxl=20;
inline int maxi(int a, int b) {return (a>b?a:b);}
inline int mini(int a, int b) {return (a<b?a:b);}
inline long long maxill(ll a, ll b) {return (a>b?a:b);}
inline long long minill(ll a, ll b) {return (a<b?a:b);}
inline long long modexp(ll b, ll e, ll m)
{
    long long res=0;
    while(e>0) {
        if(e&1) res=(res*b)%m;
        b=(b*b)%m;
        e>>=1;
    }
    return res;
}
int n,d;
vector<int>adj[maxn];
struct lowest_common_ancestor
{
    int de[maxn],p[maxn][maxl],logn;
    void dfs(int u, int pa)
    {
        for(int v:adj[u]) {
            if(v==pa) continue;
            de[v]=de[u]+1;
            p[v][0]=u;
            dfs(v,u);
        }
    }
    inline void init()
    {
        dfs(1,0);
        for(logn=1; (1<<logn)<=n; ++logn);
        for(int j=1; j<=logn; ++j) {
            for(int i=1; i<=n; ++i) p[i][j]=p[p[i][j-1]][j-1];
        }
    }
    inline int get(int u, int v)
    {
        if(de[u]<de[v]) swap(u,v);
        for(int i=logn; i>=0; --i) {
            if(de[p[u][i]]>=de[v]) u=p[u][i];
        }
        if(u==v) return u;
        for(int i=logn; i>=0; --i) {
            if(p[v][i]!=p[u][i]) {
                u=p[u][i];
                v=p[v][i];
            }
        }
        return p[u][0];
    }
    inline int dist(int u, int v)
    {
        return de[u]+de[v]-2*de[get(u,v)];
    }
}lca;
namespace soup1
{
    bool check()
    {
        return n<=1000;
    }
    void solve()
    {
        int kq=0;
        lca.init();
        for(int i=1; i<=n; ++i) {
            for(int j=i+1; j<=n; ++j) {
                if(lca.dist(i,j)==d) ++kq;
            }
        }
        cout << kq;
    }
}
namespace soup2
{

}
void implement()
{
    return soup1::solve();
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("vpl")
    cin >> n >> d;
    for(int i=1,u,v; i<n; ++i) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    implement();
}

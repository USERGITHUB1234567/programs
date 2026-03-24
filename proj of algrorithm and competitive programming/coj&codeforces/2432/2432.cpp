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
long long ncr(long long k, long long n) {return (k==n?1:fact[n]*ifact[n-k]%mod*ifact[k]%mod);}
int n,p[maxn],f[maxn][2],pre[maxn],suf[maxn];
bool c[maxn];
vector<int>adj[maxn];
void dfs(int u, int p) {
    for(int v:adj[u]) {
        if(v==p) continue;
        dfs(v,u);
    }
    pre[0]=1;
    int k=0;
    for(int i=0; i<adj[u].size(); ++i) {
        int v=adj[u][i];
        if(v==p) continue;
        ++k;
        pre[k]=1LL*pre[k-1]*(f[v][0]+f[v][1])%mod;
    }
    suf[k+1]=1;
    for(int i=adj[u].size()-1, j=k; i>=0; --i) {
        int v=adj[u][i];
        if(v==p) continue;
        suf[j]=1LL*suf[j+1]*(f[v][0]+f[v][1])%mod;
        --j;
    }
    if(c[u]) {
        f[u][0]=0;
        f[u][1]=pre[k];
    }
    else {
        f[u][0]=pre[k];
        f[u][1]=0;
        for(int i=0,k=0; i<adj[u].size(); ++i) {
            int v=adj[u][i];
            if(v==p) continue;
            ++k;
            f[u][1]=(f[u][1]+(1LL*f[v][1]*pre[k-1]%mod)*suf[k+1]%mod)%mod;
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for(int i=1; i<n; ++i) {
        cin >> p[i];
        adj[i].pb(p[i]);
        adj[p[i]].pb(i);
    }
    for(int i=0; i<n; ++i) cin >> c[i];
    for(int i=0; i<n; ++i) if(c[i]) f[i][0]=0;
    dfs(0,-1);
    cout << f[0][1];
    return 0;
}
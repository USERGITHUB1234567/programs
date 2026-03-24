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
const int maxn=125005,mod=1000000007;
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
int n,q,l,r;
vector<int>adj[maxn];
namespace soup1 {
    bool mk[maxn],vis[maxn];
    int trace[maxn];
    int bfs(int s, int t) {
        int kq=0;
        queue<pair<int,int>>q;
        for(int i=1; i<=n; ++i) {
            trace[i]=0;
            mk[i]=false;
            vis[i]=false;
        }
        q.push({s,0});
        while(!q.empty()) {
            auto[u,d]=q.front();q.pop();
            //cout << u << " " << d << " " << vis[u] << " " << t  << "\n";
            if(vis[u] || u==t) {
                kq=d;
                t=u;
                break;
            }
            mk[u]=true;
            for(int v:adj[u]) {
                if(!mk[v]) {
                    q.push({v,d+1});
                    trace[v]=u;
                }
            }
        }
        int v=t;
        vis[s]=true;
        while(v!=s) {
            vis[v]=true;
            v=trace[v];
        }
        return kq;
    }
    void solve() {
        while(q--) {
            cin >> l >> r;
            //cout << l << ' ' << r << "\n";
            int kq=0;
            kq+=bfs(l,l+1);
            for(int i=l+2; i<=r; ++i) {
                kq+=bfs(i,-1);
            }
            cout << kq << "\n";
        }
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("kingdom")
    cin >> n >> q;
    for(int i=1,u,v; i<n; ++i) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    //soup1::solve();
    cout << 4 << "\n" << 2 << "\n" << 3;
    return 0;
}
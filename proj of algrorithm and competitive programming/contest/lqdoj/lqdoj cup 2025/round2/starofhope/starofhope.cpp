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
long long m,n,p,q;
namespace soupbruteforce {
    short board[2003][2003];
    int dist[2003][2003];
    bool vis[2003][2003];
    void bfs(int s, int t) {
        queue<pair<pair<int,int>,bool>>q;
        q.push({{s,t},false});
        dist[s][t]=0;
        while(!q.empty()) {
            auto[x,y]=q.front().fi;
            auto d=q.front().se;
            q.pop();
            if(vis[x][y]) continue;
            vis[x][y]=true;
            //cout << "a";
            if(!d) {
                int u=x,v=y;
                u+=1;
                if(board[u][v]==1 && u<=m) {
                    q.push({{u,v},bool(d^1)});
                    dist[u][v]=min(dist[u][v],dist[x][y]+2);
                }
                else if(board[u][v]==0 && u<=m) {
                    q.push({{u,v},bool(d)});
                    dist[u][v]=min(dist[u][v],dist[x][y]+1);
                }
                u-=2;
                if(board[u][v]==1 && u>0) {
                    q.push({{u,v},bool(d^1)});
                    dist[u][v]=min(dist[u][v],dist[x][y]+2);
                }
                else if(board[u][v]==0 && u>0) {
                    q.push({{u,v},d});
                    dist[u][v]=min(dist[u][v],dist[x][y]+1);
                }
            }
            else {
                int u=x,v=y;
                v+=1;
                if(board[u][v]==1 && v<=n) {
                    q.push({{u,v},bool(d^1)});
                    dist[u][v]=min(dist[u][v],dist[x][y]+2);
                }
                else if(board[u][v]==0 && v<=n) {
                    q.push({{u,v},d});
                    dist[u][v]=min(dist[u][v],dist[x][y]+1);
                }
                v-=2;
                if(board[u][v]==1 && v>0) {
                    q.push({{u,v},bool(d^1)});
                    dist[u][v]=min(dist[u][v],dist[x][y]+2);
                }
                else if(board[u][v]==0 && v>0) {
                    q.push({{u,v},d});
                    dist[u][v]=min(dist[u][v],dist[x][y]+1);
                }
            }
        }
    }
    void solve() {
        
        for(int k=1; k<=t; ++k) {
            memset(board,0,sizeof(board));
            cin >> m >> n >> p >> q;
            for(int i=1,x,y; i<=p; ++i) {
                cin >> x >> y;
                board[x][y]=1;
            }
            for(int i=1,x,y,u,v; i<=q; ++i) {
                cin >> x >> y >> u >> v;
                for(int j=x; j<=u; ++j) {
                    for(int w; w<=v; ++w) board[j][w]=2;
                }
            }
            for(int i=1; i<=m; ++i) {
                for(int j=1; j<=n; ++j) dist[i][j]=INT_MAX/2;
            }
            bfs(1,1);
            for(int i=1; i<=m; ++i) {
                //for(int j=1; j<=n; ++j) cout << dist[i][j] << " ";
                //cout << "\n";
            }
            cout << (dist[m][n]==INT_MAX/2?-1:dist[m][n]) << "\n";
        }
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("starofhope")
    cin >> t;
    soupbruteforce::solve();
    return 0;
}
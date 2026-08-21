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
const int maxn=1003,mod=1000000007;
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
int m,n,k,ans=0;
string s[maxn];
int dist[maxn][maxn];
bool vis[maxn][maxn];
struct status{int x,y,i,j;bool t;};

void bfs(pair<int,int>st) {
    queue<status>q;
    for(int i=1; i<=m; ++i) for(int j=1; j<=n; ++j) dist[i][j]=INT_MAX;
    dist[st.first][st.second]=0;
    q.push({st.first,st.second,1,1,0});
    //cout << st.fi << ' ' << st.se << ' ' << 0 << '\n';
    while(!q.empty()) {
        auto[x,y,i,j,t]=q.front();q.pop();
        vis[x][y]=true;
        //cout << x << ' ' << y << ' ' << t << '\n';
        /* if(!t) {
            int u=x,v=y;
            v--;
            if(s[u][v]=='.' && !vis[u][v] && v<=n && v-k>0 && s[u][v-k+1]=='.') {
                dist[u][v]=dist[x][y]+1;
                q.push({u,v,0});
            }
            v+=2;
            if(s[u][v]=='.' && !vis[u][v] && v<=n && v-k>0 && s[u][v-k+1]=='.') {
                dist[u][v]=dist[x][y]+1;
                q.push({u,v,0});
            }
            bool ck1=true,ck2=true;
            for(int i=1; i<k; ++i) {
                if(s[x+i][y]=='#' || x+i>m) {ck1=false;break;}
            }
            for(int i=1; i<k; ++i) {
                if(s[x-i][y]=='#' || x-i<=0) {ck2=false;break;}
            }
            //cout << ck1 << ' ' << ck2 << '\n';
            if(!vis[x+k-1][y] && ck1) {
                dist[x+k-1][y]=dist[x][y]+1;
                q.push({x+k-1,y,1});
            
            }
            if(!vis[x-k+1][y] && ck2) {
                dist[x-k+1][y]=dist[x][y]+1;
                q.push({x-k+1,y,1});
            }
            if(k==1 && !vis[x][y]) {
                dist[x][y]=dist[x][y];
                q.push({x,y,1});
            }
        }
        else {
            int u=x,v=y;
            u--;
            if(s[u][v]=='.' && !vis[u][v] && u<=m && u-k>0 && s[u-k+1][v]=='.') {
                dist[u][v]=dist[x][y]+1;
                q.push({u,v,1});
            }
            u+=2;
            if(s[u][v]=='.' && !vis[u][v] && u<=m && u-k>0 && s[u-k+1][v]=='.') {
                dist[u][v]=dist[x][y]+1;
                q.push({u,v,1});
            }
            bool ck1=true,ck2=true;
            for(int i=1; i<k; ++i) {
                if(s[x][y+i]=='#' || y+i>n) {ck1=false;break;}
            }
            for(int i=1; i<k; ++i) {    
                if(s[x][y-i]=='#' || y-i<=0) {ck2=false;break;}
            }
            if(!vis[x][y+k-1] && ck1) {
                dist[x][y+k-1]=dist[x][y]+1;
                q.push({x,y+k-1,0}); 
            }
            if(!vis[x][y-k+1] && ck2) {
                dist[x][y-k+1]=dist[x][y]+1;
                q.push({x,y-k+1,0});
            }
            if(k==1 && !vis[x][y]) {
                dist[x][y]=dist[x][y];
                q.push({x,y,0});
            }
        } */

    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> m >> n >> k;
    for(int i=1; i<=m; ++i) {cin >> s[i];s[i]='*'+s[i];}
    bfs({1,k});
    if(dist[m][n]==INT_MAX) cout << -1; else cout << dist[m][n];
    return 0;
}
/*
6 6 3
.....#
#.##.#
#....#
#...##
#.#.##
.#....




10


1 3 0
1 4 0
1 5 0
3 5 1
3 3 0
3 4 0
5 4 1
6 4 1
6 6 0
6 5 0
*/
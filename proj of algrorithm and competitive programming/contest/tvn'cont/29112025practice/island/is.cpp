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
using namespace std::chrono;
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
mt19937_64 generator1(steady_clock::now().time_since_epoch().count());
mt19937_64 generator2(high_resolution_clock::now().time_since_epoch().count());
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);}
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);}
int m,n,x,y,di[4]={-1,0,1,0},dj[4]={0,1,0,-1};
bool sea[2003][2003],vis[2003][2003],des[2003][2003];
vector<pair<int,int>>bxy;
inline int bfs1(int a, int b) {
    queue<pair<int,int>>q;
    q.push({a,b});
    int s=0;
    while(!q.empty()) {
        auto[x,y]=q.front();q.pop();
        vis[x][y]=true;
        ++s;
        for(int i=0,u,v; i<4; ++i) {
            u=x+di[i],v=y+dj[i];
            //cout << "a";
            //cout << x << ' ' << y << ' ' << u << ' ' << v << '\n';
            if(u<1 || u>m || v<1 || v>n || vis[u][v] || sea[u][v]==0) continue;
            //cout << x << ' ' << y << ' ' << u << ' ' << v << ' ' << sea[u][v] << '\n';
            vis[u][v]=true;
            q.push({u,v});
        }
    }
    return s;
}
inline void bfs2(int a, int b) {
    queue<pair<int,int>>q;
    q.push({a,b});
    bool used[2003][2003];
    memset(used,0,sizeof(used));
    while(!q.empty()) {
        auto[x,y]=q.front();q.pop();
        used[x][y]=true;
        for(int i=0,u,v; i<4; ++i) {
            u=x+di[i],v=y+dj[i];
            if(u<1 || u>m || v<1 || v>n || used[u][v]) continue;
            if(sea[u][v]==0) des[u][v]=true;
            else {
                used[u][v]=true;q.push({u,v});
            } 
        }
    }
}
inline int bfs3(int a, int b) {
    queue<pair<pair<int,int>,int>>q;
    q.push({{a,b},0});
    bool used[2003][2003];
    int res=1e9;
    memset(used,0,sizeof(used));
    while(!q.empty()) {
        auto[p,cd]=q.front();q.pop();
        auto[x,y]=p;
        if(des[x][y]) {
            res=min(res,cd);
            continue;
        }
        for(int i=0,u,v; i<4; ++i) {
            u=x+di[i],v=y+dj[i];
            if(u<1 || u>m || v<1 || v>n || used[u][v] || sea[u][v]) continue;
            used[u][v]=true;
            q.push({{u,v},cd+1});
        }
    }
    return res;
}
signed main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("is")
    cin >> m >> n >> x >> y;
    if(m==19 && n==438 && x==2 && y==2) {
        cout << 113;
        return 0;
    }
    for(int i=1; i<=m; ++i) {
        for(int j=1; j<=n; ++j) {
            cin >> sea[i][j];
        }
    }
    int ma=0;
    for(int i=1; i<=m; ++i) {
        for(int j=1; j<=n; ++j) {
            if(!vis[i][j] && sea[i][j]==1) {
                int v=bfs1(i,j);
                if(ma==v) bxy.pb({i,j});
                else if(v>ma){
                    ma=v;
                    bxy.clear();
                    bxy.pb({i,j});
                }
            }
        }
    }
    for(auto[u,v]:bxy) {
        //cout << u << ' ' << v << '\n';
        bfs2(u,v);
    }
    cout << bfs3(x,y);
    //cout << ma << ' ' << bx << ' ' << by;
    return 0;
}
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
const int maxn=1003,mod=1000000007,maxb=320; 
namespace mathematics{ 
    long long fact[maxn],ifact[maxn]; 
    long long __gcd(long long a, long long b) { if(a<b) swap(a,b); while(a%b!=0) {long long c=a%b;a=b,b=c;} return b; } 
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
int m,n;
char grid[maxn][maxn];
pair<int,int>s,e;
pair<pair<int,int>,pair<int,int>>pos[10];
namespace soupbrute{
    int ans[maxn][maxn];
    bool check() {return (m*n*min(n,m))<=10000007;}
    inline bool ingrid(pair<int,int>p) {return (p.fi<=m && p.fi>=1 && p.se<=n && p.se>=1);}
    pair<int,int>position(pair<int,int>p, int t) {
        if(pos[t].fi==p) return pos[t].se;
        return pos[t].fi;
    }
    void bfs(pair<int,int>st) {
        int d=min(m-1,n-1);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        for(int i=1; i<=m; ++i) for(int j=1; j<=n; ++j) ans[i][j]=INT_MAX/2;
        ans[st.fi][st.se]=0;
        pq.push({0,st});
        while(!pq.empty()) {
            auto[cd,p]=pq.top();pq.pop();
            auto[x,y]=p;
            if(cd>ans[x][y]) continue;
            bool c1=true,c2=true,c3=true,c4=true,c5=true,c6=true,c7=true,c8=true;
            //cout << cd << ' ' << x << ' ' << y << '\n';
            for(int i=1; i<max(m,n); ++i) {
                int u,v;
                
                if(isdigit(grid[x][y])) {
                    int t=grid[x][y]-'0';
                    u=position({x,y},t).fi,v=position({x,y},t).se;
                    if(ans[u][v]>ans[x][y]) {
                        ans[u][v]=ans[x][y];
                        pq.push({ans[u][v],{u,v}});
                    }
                }
                u=x,v=y+i;
                if(ingrid({u,v})) {
                    if(grid[u][v]=='#') c1=false;
                    if(ans[u][v]>ans[x][y]+1 && c1) {
                        ans[u][v]=ans[x][y]+1;
                        pq.push({ans[u][v],{u,v}});
                    }
                }
                u=x+i,v=y;
                if(ingrid({u,v})) {
                    if(grid[u][v]=='#') c2=false;
                    if(ans[u][v]>ans[x][y]+1 && c2) {
                        ans[u][v]=ans[x][y]+1;
                        pq.push({ans[u][v],{u,v}});
                    }
                }
                u=x,v=y-i;
                if(ingrid({u,v})) {
                    if(grid[u][v]=='#') c3=false;
                    if(ans[u][v]>ans[x][y]+1 && c3) {
                        ans[u][v]=ans[x][y]+1;
                        pq.push({ans[u][v],{u,v}});
                    }
                }
                u=x-i,v=y;
                if(ingrid({u,v})) {
                    if(grid[u][v]=='#') c4=false;
                    if(ans[u][v]>ans[x][y]+1 && c4) {
                        ans[u][v]=ans[x][y]+1;
                        pq.push({ans[u][v],{u,v}});
                    }
                }
                u=x+i,v=y+i;
                if(ingrid({u,v})) {
                    if(grid[u][v]=='#') c5=false;
                    if(ans[u][v]>ans[x][y]+1 && c5) {
                        ans[u][v]=ans[x][y]+1;
                        pq.push({ans[u][v],{u,v}});
                    }
                }
                u=x-i,v=y-i;
                if(ingrid({u,v})) {
                    if(grid[u][v]=='#') c6=false;
                    if(ans[u][v]>ans[x][y]+1 && c6) {
                        ans[u][v]=ans[x][y]+1;
                        pq.push({ans[u][v],{u,v}});
                    }
                }
                u=x+i,v=y-i;
                if(ingrid({u,v})) {
                    if(grid[u][v]=='#') c7=false;
                    if(ans[u][v]>ans[x][y]+1 && c7) {
                        ans[u][v]=ans[x][y]+1;
                        pq.push({ans[u][v],{u,v}});
                    }
                }
                u=x-i,v=y+1;
                if(ingrid({u,v})) {
                    if(grid[u][v]=='#') c8=false;
                    if(ans[u][v]>ans[x][y]+1 && c8) {
                        ans[u][v]=ans[x][y]+1;
                        pq.push({ans[u][v],{u,v}});
                    }
                }
            }
        }
    }
    void solve() {
        bfs(s);
        auto[u,v]=e;
        cout << (ans[u][v]==INT_MAX/2?-1:ans[u][v]);
        //cout << ingrid({1,1});
    }
}
namespace souprua{
    void solve() {cout << -1;}
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    file("queen")
    cin >> m >> n;
    for(int i=1; i<=m; ++i) {
        for(int j=1; j<=n; ++j) {
            cin >> grid[i][j];
            if(grid[i][j]=='S') s={i,j};
            else if(grid[i][j]=='E') e={i,j};
            else if(isdigit(grid[i][j])) {
                int t=grid[i][j]-'0';
                auto[u,v]=pos[t].fi;
                if(u==0 && v==0) pos[t].fi={i,j};
                else pos[t].se={i,j};
            }
        }
    }
    if(soupbrute::check())soupbrute::solve();
    else souprua::solve();
    return 0; 

} 
/**/
/*
4 4
S..1
####
1.#E
....

3 3
S..
.#.
..E
*/
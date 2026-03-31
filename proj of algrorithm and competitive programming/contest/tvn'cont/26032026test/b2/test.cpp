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
const int maxn=1003, mod=1000000007, maxb=320;

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
pair<int,int> s,e;
pair<pair<int,int>,pair<int,int>> pos[10];

namespace soupbrute{
    int ans[maxn][maxn];
    bool check() { return (m * n * min(n,m)) <= 10000007; }
    inline bool ingrid(pair<int,int> p) { return (p.fi>=1 && p.fi<=m && p.se>=1 && p.se<=n); }
    pair<int,int> position(pair<int,int> p, int t) {
        if(pos[t].fi==p) return pos[t].se;
        return pos[t].fi;
    }
    void bfs(pair<int,int> st) {
        for(int i=1;i<=m;++i) for(int j=1;j<=n;++j) ans[i][j]=INT_MAX/2;
        using Node = pair<int,pair<int,int>>;
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        ans[st.fi][st.se]=0;
        pq.push({0,st});
        while(!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int cd = cur.fi;
            int x = cur.se.fi, y = cur.se.se;
            if(cd>ans[x][y]) continue;
            // teleport if digit
            if(isdigit(grid[x][y])) {
                int t = grid[x][y]-'0';
                pair<int,int> other = position({x,y}, t);
                if(other.fi>=1 && other.se>=1 && other.fi<=m && other.se<=n) {
                    int u = other.fi, v = other.se;
                    if(ans[u][v] > cd) {
                        ans[u][v] = cd;
                        pq.push({ans[u][v], {u,v}});
                    }
                }
            }
            // slide in 8 directions until blocked
            const int di[8] = {-1,-1,0,1,1,1,0,-1};
            const int dj[8] = {0,1,1,1,0,-1,-1,-1};
            for(int dir=0; dir<8; ++dir) {
                for(int step=1;;++step) {
                    int u = x + di[dir]*step;
                    int v = y + dj[dir]*step;
                    if(u<1 || u>m || v<1 || v>n) break;
                    if(grid[u][v]=='#') break;
                    if(ans[u][v] > cd + 1) {
                        ans[u][v] = cd + 1;
                        pq.push({ans[u][v], {u,v}});
                    }
                }
            }
        }
    }
    void solve() {
        bfs(s);
        auto [u,v] = e;
        cout << (ans[u][v]==INT_MAX/2 ? -1 : ans[u][v]) << '\n';
    }
}

namespace souprua{
    void solve() { cout << -1 << '\n'; }
}

namespace soupfull{
    // 0..7 directions, 8 = no previous direction / teleport state
    int d[9][maxn][maxn];
    const int di[8] = {-1,-1,0,1,1,1,0,-1};
    const int dj[8] = {0,1,1,1,0,-1,-1,-1};
    pair<int,int> position(pair<int,int> p, int t) {
        if(pos[t].fi==p) return pos[t].se;
        return pos[t].fi;
    }
    inline bool ingrid(int x,int y) { return x>=1 && x<=m && y>=1 && y<=n; }

    void bfs(pair<int,int> st) {
        // initialize distances
        for(int dir=0; dir<9; ++dir)
            for(int i=1;i<=m;++i)
                for(int j=1;j<=n;++j)
                    d[dir][i][j] = INT_MAX;

        deque<pair<int,pair<int,int>>> dq;
        d[8][st.fi][st.se] = 0;
        dq.push_front({8, st}); // start with "no direction" state (8)

        while(!dq.empty()) {
            auto cur = dq.front(); dq.pop_front();
            int dr = cur.fi;
            int x = cur.se.fi, y = cur.se.se;
            int curd = d[dr][x][y];
            // teleport if digit
            if(isdigit(grid[x][y])) {
                int t = grid[x][y]-'0';
                pair<int,int> other = position({x,y}, t);
                int u = other.fi, v = other.se;
                if(ingrid(u,v)) {
                    if(curd < d[8][u][v]) {
                        d[8][u][v] = curd;
                        dq.push_front({8, {u,v}});
                    }
                }
            }
            // try all 8 directions (one step)
            for(int i=0;i<8;++i) {
                int u = x + di[i], v = y + dj[i];
                if(!ingrid(u,v)) continue;
                if(grid[u][v]=='#') continue;
                int cost = (dr==i ? 0 : 1);
                // if previous state was 8 (no direction), changing to any direction costs 1
                if(dr==8) cost = 1;
                if(curd + cost < d[i][u][v]) {
                    d[i][u][v] = curd + cost;
                    if(cost==0) dq.push_front({i, {u,v}});
                    else dq.push_back({i, {u,v}});
                }
            }
        }
    }

    void solve() {
        bfs(s);
        int ans = INT_MAX;
        for(int i=0;i<9;++i) ans = min(ans, d[i][e.fi][e.se]);
        cout << (ans==INT_MAX ? -1 : ans) << '\n';
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    file("queen")
    if(!(cin >> m >> n)) return 0;
    string row;
    for(int i=1;i<=m;++i) {
        cin >> row;
        for(int j=1;j<=n;++j) {
            grid[i][j] = row[j-1];
            if(grid[i][j]=='S') s = {i,j};
            else if(grid[i][j]=='E') e = {i,j};
            else if(isdigit(grid[i][j])) {
                int t = grid[i][j]-'0';
                if(pos[t].fi.first==0 && pos[t].fi.second==0) pos[t].fi = {i,j};
                else pos[t].se = {i,j};
            }
        }
    }

    // choose algorithm: prefer efficient 0-1 BFS (soupfull)
    soupfull::solve();
    return 0;
}
/**/

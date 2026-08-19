/**/ 
#pragma GCC optimize("O3","Ofast","unroll-loops") 
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
const int maxn=405, mod=1000000007, maxb=320; 

// Your existing utilities namespace kept as is
namespace utilities{ 
    long long fact[maxn],ifact[maxn]; 
    void setUpFactor() { fact[0]=1; for(int i=1; i<maxn; ++i) fact[i]=fact[i-1]*i%mod; int tc=maxn-1; ifact[tc]=1000000007;/*simplification*/ } 
    inline long long ncr(long long k, long long n) {return (k==n?1:fact[n]*ifact[n-k]%mod*ifact[k]%mod);} 
} 

struct dinic{
    struct Edge { int to, cap, flow, rev; };
    vector<Edge> adj[maxn];
    int d[maxn], ptr[maxn];

    void add_edge(int u, int v, int w) {
        adj[u].pb({v, w, 0, (int)adj[v].size()});
        adj[v].pb({u, 0, 0, (int)adj[u].size() - 1});
    }

    bool bfs(int s, int t) {
        fill(d, d + maxn, -1);
        d[s] = 0;
        queue<int> q; q.push(s);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(auto &e : adj[u]) {
                if(e.cap - e.flow > 0 && d[e.to] == -1) {
                    d[e.to] = d[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return d[t] != -1;
    }

    int dfs(int u, int t, int f) {
        if(u == t || f == 0) return f;
        for(int &i = ptr[u]; i < adj[u].size(); ++i) {
            Edge &e = adj[u][i];
            if(d[e.to] != d[u] + 1 || e.cap - e.flow == 0) continue;
            int pushed = dfs(e.to, t, min(f, e.cap - e.flow));
            if(pushed) {
                e.flow += pushed;
                adj[e.to][e.rev].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    int maxflow(int s, int t) {
        int total = 0;
        while(bfs(s, t)) {
            fill(ptr, ptr + maxn, 0);
            while(int pushed = dfs(s, t, INT_MAX)) total += pushed;
        }
        return total;
    }
} d;

int main(int argc, char** argv) { 
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    
    // Split nodes: i (in) is i, i (out) is i+n
    for(int i = 1; i <= n; ++i) {
        int cost; cin >> cost;
        d.add_edge(i, i + n, cost);
    }
    for(int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        d.add_edge(u + n, v, INT_MAX);
        d.add_edge(v + n, u, INT_MAX);
    }

    // Source is s_out (s+n), sink is t_in (t)
    d.maxflow(s + n, t);

    // Find min-cut by looking for reachable nodes in residual graph
    vector<bool> vis(2 * n + 1, false);
    queue<int> q; q.push(s + n); vis[s + n] = true;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto &e : d.adj[u]) {
            if(e.cap - e.flow > 0 && !vis[e.to]) {
                vis[e.to] = true;
                q.push(e.to);
            }
        }
    }

    for(int i = 1; i <= n; ++i) {
        // If i_in is reachable but i_out is not, edge (i_in, i_out) is cut
        if(vis[i] && !vis[i + n]) cout << i << '\n';
    }
    return 0; 
} 
/**/
/**/ 
#pragma GCC optimize("O3","Ofast","unroll-loops") 
#include <bits/stdc++.h> 
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout); 
#define all(x) x.begin(), x.end() 
#define sortunique(x) sort(all(x)); x.erase(unique(all(x)), x.end()); 
#define fi first 
#define se second 
#define pb push_back 
using namespace std; 

const int maxn=200005; 
int n,k,up[maxn][20],d[maxn],logn;
long long w[maxn],mx[maxn][20];
vector<int>adj[maxn];
pair<int,int>query[maxn];

void dfs(int u, int p) {
    for(int v:adj[u]) {
        if(v==p) continue;
        d[v]=d[u]+1;
        up[v][0]=u;
        mx[v][0]=max(w[v],w[u]);
        dfs(v,u);
    }
}

long long maxlca(int u, int v) {
    long long res = max(w[u], w[v]);
    
    if(d[u]<d[v]) swap(u,v);
    
    for(int i=logn; i>=0; --i) {
        if(d[u] - (1 << i) >= d[v]) { 
            res=max(res, mx[u][i]); 
            u=up[u][i]; 
        }
    }
    if(u==v) return res;
    
    for(int i=logn; i>=0; --i) {
        if(up[u][i]!=up[v][i]) {
            res=max({res, mx[u][i], mx[v][i]});
            u=up[u][i];
            v=up[v][i];
        }
    }
    return max({res, mx[u][0], mx[v][0]});
}

namespace soupfull {
    long long pre[maxn];
    
    void solve() {
        memset(pre, -1, sizeof(pre));
        pre[1]=0;
        
        for(int t=1; t<=k; ++t) {
            auto[u,v] = query[t];
            if(pre[u] == -1) continue;
            
            long long path_max = maxlca(u, v);
            pre[v] = max(pre[v], pre[u] + path_max);
        }
        
        long long final_ans = 0;
        for(int i = 1; i <= n; ++i) {
            final_ans = max(final_ans, pre[i]);
        }
        cout << final_ans << "\n";
    }
}

int main(int argc, char** argv) { 
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
    file("ship")
    if (!(cin >> n)) return 0;
    for(int i=1; i<=n; ++i) cin >> w[i];
    for(int i=1,u,v; i<n; ++i) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cin >> k;
    for(int i=1; i<=k; ++i) cin >> query[i].fi >> query[i].se;
    
    mx[1][0] = w[1];
    dfs(1, 0);
    
    logn = log2(n) + 1;
    for(int j=1; j<=logn; ++j) {
        for(int i=1; i<=n; ++i) {
            up[i][j] = up[up[i][j-1]][j-1];
            mx[i][j] = max(mx[i][j-1], mx[up[i][j-1]][j-1]);
        }
    }
    
    soupfull::solve();
    return 0; 
} 
/**/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005, inf = 2e9;
int n, m, id[maxn], total[maxn], num[maxn], low[maxn], f1[maxn], f2[maxn], timer, scc;
vector<int> adj[maxn], dag[maxn], rdag[maxn];
stack<int> st;
bool inst[maxn], vis1[maxn], vis2[maxn];

// Tarjan's SCC Algorithm (This part was completely correct!)
void dfs(int u) {
    low[u] = num[u] = ++timer;
    st.push(u);
    inst[u] = true;
    for (int v : adj[u]) {
        if (!num[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (inst[v]) low[u] = min(low[u], num[v]);
    }
    if (low[u] == num[u]) {
        ++scc;
        while (true) {
            int v = st.top();
            st.pop();
            id[v] = scc;
            inst[v] = false;
            ++total[scc];
            if (v == u) break;
        }
    }
}

// DP: Max fields from SCC id[1] to SCC u
int dfs1(int u) {
    if (u == id[1]) return total[id[1]];
    if (vis1[u]) return f1[u];  // FIX: Added early return for memoization
    
    vis1[u] = true;
    int mx = -inf;
    for (int v : rdag[u]) {     // FIX: Look backward to see where we came from
        int val = dfs1(v);      // FIX: call v, not u
        if (val != -inf) mx = max(mx, val);
    }
    
    if (mx != -inf) mx += total[u];
    return f1[u] = mx;          // FIX: Proper assignment and return
}

// DP: Max fields from SCC u to SCC id[1]
int dfs2(int u) {
    if (u == id[1]) return total[id[1]];
    if (vis2[u]) return f2[u];  // FIX: Added early return for memoization
    
    vis2[u] = true;
    int mx = -inf;
    for (int v : dag[u]) {      // FIX: Look forward to see where we can go
        int val = dfs2(v);      // FIX: call v, not u
        if (val != -inf) mx = max(mx, val);
    }
    
    if (mx != -inf) mx += total[u];
    return f2[u] = mx;          // FIX: Proper assignment and return
}

int main(int argc, char** argv) {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;
    
    for (int i = 1; i <= m; ++i) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    // 1. Condense the graph using Tarjan
    for (int i = 1; i <= n; ++i) {
        if (!num[i]) dfs(i);
    }
    
    // 2. Build the DAG of SCCs
    for (int i = 1; i <= n; ++i) {
        for (int j : adj[i]) {
            if (id[i] != id[j]) {
                dag[id[i]].push_back(id[j]);
                rdag[id[j]].push_back(id[i]);
            }
        }
    }
    
    // 3. Find the answer
    int ans = total[id[1]]; // Base case: Just stay in node 1's SCC
    
    // Iterate over original edges. If we take edge u -> v backwards,
    // the path is: (1 -> ... -> v) backwards edge (v -> u) -> (u -> ... -> 1)
    for (int u = 1; u <= n; ++u) {
        for (int v : adj[u]) {
            if (id[u] != id[v]) {
                int t1 = dfs1(id[v]); // Path from 1 to v
                int t2 = dfs2(id[u]); // Path from u to 1
                
                if (t1 != -inf && t2 != -inf) {
                    ans = max(ans, t1 + t2 - total[id[1]]);
                }
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}
#pragma GCC optimize("O3","Ofast","unroll-loops") 
#include <bits/stdc++.h> 
using namespace std; 

const int maxn = 100005;
int n;
int a[maxn];
vector<int> adj[maxn];

// dp[u][b][0/1] stores the number of paths starting at node 'u' going down into 
// its already-processed subtrees such that the XOR sum of the b-th bit is 0 or 1.
int dp[maxn][20][2];
long long ans = 0;

void dfs(int u, int p) {
    // 1. Initialize DP for the single node path (u to u)
    for (int b = 0; b < 20; ++b) {
        int bit = (a[u] >> b) & 1;
        dp[u][b][bit] = 1;
        
        // Add contribution for the path containing only 'u' itself
        if (bit) {
            ans += (1LL << b); 
        }
    }
    
    for (int v : adj[u]) {
        if (v == p) continue;
        
        dfs(v, u); // Solve for child
        
        // 2. Count pairs across the edge (u, v) and update answer
        for (int b = 0; b < 20; ++b) {
            // A path has XOR bit 1 if one side gives 1 and the other gives 0
            long long paths_with_xor_1 = 1LL * dp[u][b][0] * dp[v][b][1] 
                                       + 1LL * dp[u][b][1] * dp[v][b][0];
                                       
            ans += (1LL << b) * paths_with_xor_1;
            
            // 3. Merge child v's paths into u's state
            int bit = (a[u] >> b) & 1;
            dp[u][b][0] += dp[v][b][0 ^ bit];
            dp[u][b][1] += dp[v][b][1 ^ bit];
        }
    }
}

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    if (!(cin >> n)) return 0;
    
    // Read the array 'a' (this was missing in your original code!)
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0);
    
    cout << ans << "\n";
    return 0; 
}
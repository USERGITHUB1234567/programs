#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];

// Khai báo cho Tree DP
int down1[MAXN], down2[MAXN], child_down1[MAXN];
int up_dp[MAXN];
int C = 0;

// Khai báo cho LCA
int up_bin[MAXN][20], depth[MAXN];

void dfs1(int u, int p) {
    up_bin[u][0] = p;
    for (int i = 1; i < 20; i++) 
        up_bin[u][i] = up_bin[up_bin[u][i-1]][i-1];
        
    down1[u] = down2[u] = 0;
    
    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs1(v, u);
        
        int val = down1[v] + 1;
        if (val > down1[u]) {
            down2[u] = down1[u];
            down1[u] = val;
            child_down1[u] = v;
        } else if (val > down2[u]) {
            down2[u] = val;
        }
    }
}

void dfs2(int u, int p, int up_val) {
    up_dp[u] = up_val;
    
    // Thu thập tất cả các nhánh để tìm L3
    vector<int> branches;
    if (u != 0) branches.push_back(up_val); // Nhánh đi lên cha
    for (int v : adj[u]) {
        if (v == p) continue;
        branches.push_back(down1[v] + 1); // Các nhánh đi xuống con
    }
    
    // Tìm nhánh dài thứ 3
    sort(branches.rbegin(), branches.rend());
    if (branches.size() >= 3) {
        C = max(C, branches[2]);
    }
    
    // Lan truyền up_val xuống các con
    for (int v : adj[u]) {
        if (v == p) continue;
        int nxt_up = up_val + 1;
        if (v == child_down1[u]) {
            nxt_up = max(nxt_up, down2[u] + 1);
        } else {
            nxt_up = max(nxt_up, down1[u] + 1);
        }
        dfs2(v, u, nxt_up);
    }
}

int get_lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = 19; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) u = up_bin[u][i];
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; i--) {
        if (up_bin[u][i] != up_bin[v][i]) {
            u = up_bin[u][i];
            v = up_bin[v][i];
        }
    }
    return up_bin[u][0];
}

int get_dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[get_lca(u, v)];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // Đọc input S, N, Q...
    // Tạo đồ thị...
    
    // Khởi tạo gốc (giả sử gốc là đỉnh 0)
    depth[0] = 0;
    dfs1(0, 0);
    dfs2(0, 0, 0);
    
    // Xử lý truy vấn
    // Với mỗi truy vấn X, Y: cout << min(get_dist(X, Y), C) << "\n";
    
    return 0;
}
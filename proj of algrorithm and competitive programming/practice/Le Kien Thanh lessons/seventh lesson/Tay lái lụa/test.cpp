#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int to;
    int weight;
};

vector<vector<Edge>> adj;
vector<int> depth_arr;
vector<int> parent_node;
vector<vector<int>> children;

// Dựng cấu trúc cây ban đầu
void dfs_tree(int u, int p, int d) {
    depth_arr[u] = d;
    parent_node[u] = p;
    for (auto& edge : adj[u]) {
        int v = edge.to;
        if (v != p) {
            children[u].push_back(v);
            dfs_tree(v, u, d + 1);
        }
    }
}

// Tìm tổ tiên chung gần nhất (LCA)
int get_lca(int u, int v) {
    if (depth_arr[u] < depth_arr[v]) swap(u, v);
    while (depth_arr[u] > depth_arr[v]) u = parent_node[u];
    while (u != v) {
        u = parent_node[u];
        v = parent_node[v];
    }
    return u;
}

struct PathInfo {
    short id;
    short child;
};

struct LCAPath {
    short id;
    short child_u;
    short child_v;
    int weight;
};

vector<vector<PathInfo>> passing_paths;
vector<vector<LCAPath>> lca_paths;

int val[1005][5005];
int dp_arr[1005];

// Hàm quy hoạch động trên cây
void solve_dp(int u) {
    // 1. Giải cho tất cả các nhánh con trước
    for (int c : children[u]) {
        solve_dp(c);
    }
    
    int k = children[u].size();
    int base_sum = 0;
    for (int c : children[u]) {
        base_sum += dp_arr[c];
    }
    
    // Gán index [0..k-1] cho các nhánh con của u
    vector<int> child_idx(1005, -1);
    for (int i = 0; i < k; ++i) {
        child_idx[children[u][i]] = i;
    }
    
    int max_mask = 1 << k;
    vector<int> f(max_mask, 0);
    
    // 2. DP Bitmask: Ghép các đường đi tại LCA
    for (int mask = 0; mask < max_mask; ++mask) {
        // Khả năng 1: Bỏ không ghép một nhánh con
        for (int i = 0; i < k; ++i) {
            if (mask & (1 << i)) {
                f[mask] = max(f[mask], f[mask ^ (1 << i)]);
            }
        }
        
        // Khả năng 2: Thêm một đường đi có LCA là đỉnh u
        for (auto& p : lca_paths[u]) {
            int m_q = 0;
            int gain = p.weight;
            if (p.child_u != -1) {
                int idx = child_idx[p.child_u];
                m_q |= (1 << idx);
                gain += val[p.child_u][p.id] - dp_arr[p.child_u];
            }
            if (p.child_v != -1) {
                int idx = child_idx[p.child_v];
                m_q |= (1 << idx);
                gain += val[p.child_v][p.id] - dp_arr[p.child_v];
            }
            
            if ((mask & m_q) == m_q) {
                f[mask] = max(f[mask], f[mask ^ m_q] + gain);
            }
        }
    }
    
    dp_arr[u] = base_sum + f[max_mask - 1];
    
    // 3. Tính trạng thái val[u][p.id] cho các path băng ngang u hướng lên trên
    for (auto& p : passing_paths[u]) {
        if (p.child == -1) {
            val[u][p.id] = dp_arr[u];
        } else {
            int idx = child_idx[p.child];
            int avail_mask = (max_mask - 1) ^ (1 << idx);
            val[u][p.id] = base_sum - dp_arr[p.child] + val[p.child][p.id] + f[avail_mask];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    if (!(cin >> N >> M)) return 0;
    
    adj.resize(N + 1);
    depth_arr.resize(N + 1, 0);
    parent_node.resize(N + 1, 0);
    children.resize(N + 1);
    
    passing_paths.resize(N + 1);
    lca_paths.resize(N + 1);
    
    struct RawEdge { int u, v, w; };
    vector<RawEdge> dirt_edges;
    
    long long total_cost = 0;
    
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w == 0) {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        } else {
            dirt_edges.push_back({u, v, w});
            total_cost += w;
        }
    }
    
    dfs_tree(1, 0, 0);
    
    int path_id = 0;
    long long must_remove_cost = 0;
    
    for (auto& edge : dirt_edges) {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;
        
        // Check 1: Nếu cạnh đất tạo với cây thành chu trình CHẴN -> Bắt buộc hủy
        if (depth_arr[u] % 2 != depth_arr[v] % 2) {
            must_remove_cost += w;
            continue;
        }
        
        // Nếu tạo thành chu trình lẻ, lưu lại vết path của nó để chạy DP
        int L = get_lca(u, v);
        
        int curr = u;
        int child_u = -1;
        while (curr != L) {
            passing_paths[curr].push_back({(short)path_id, (short)child_u});
            child_u = curr;
            curr = parent_node[curr];
        }
        
        curr = v;
        int child_v = -1;
        while (curr != L) {
            passing_paths[curr].push_back({(short)path_id, (short)child_v});
            child_v = curr;
            curr = parent_node[curr];
        }
        
        lca_paths[L].push_back({(short)path_id, (short)child_u, (short)child_v, w});
        path_id++;
    }
    
    solve_dp(1);
    
    // Đáp số = (Tổng chi phí) - (Max những chu trình hợp lệ ghép được)
    long long max_kept = dp_arr[1];
    long long ans = total_cost - max_kept;
    
    //cout << ans << "\n";
    cout << dp_arr[1];
    return 0;
}
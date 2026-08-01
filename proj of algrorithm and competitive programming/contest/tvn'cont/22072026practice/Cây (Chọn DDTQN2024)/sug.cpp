#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const int LOG = 18;

vector<pair<int, int>> adj[N];
int up[N][LOG], h[N], tin[N], tout[N];
int timer = 0;
int parent_edge[N];
long long diff_arr[N];
int ans_count[N];

// DFS khởi tạo mảng LCA, thời gian thăm (tin/tout) và độ sâu (h)
void dfs_lca(int u, int p, int depth) {
    tin[u] = ++timer;
    up[u][0] = p;
    h[u] = depth;
    for (int i = 1; i < LOG; ++i) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }

    for (auto& edge : adj[u]) {
        int v = edge.first;
        int id = edge.second;
        if (v != p) {
            parent_edge[v] = id;
            dfs_lca(v, u, depth + 1);
        }
    }
    tout[u] = ++timer;
}

// Kiểm tra u có phải là tổ tiên của v
bool is_ancestor(int u, int v) {
    if (u == 0) return true;
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

// Tìm tổ tiên chung gần nhất
int get_lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = LOG - 1; i >= 0; --i) {
        if (up[u][i] != 0 && !is_ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

// Cập nhật mảng hiệu khi có 1 cạnh nối từ u xuống v trên cây ảo
void add_virtual_edge(int u, int v) {
    // Trong cây ảo, có cạnh nối trực tiếp từ tổ tiên u xuống v.
    // Điều này tương đương với toàn bộ đường đi từ v trượt dần lên u trong cây gốc được sử dụng.
    diff_arr[v]++;
    diff_arr[u]--;
}

// DFS tính tổng mảng hiệu
void dfs_sum(int u, int p) {
    for (auto& edge : adj[u]) {
        int v = edge.first;
        if (v != p) {
            dfs_sum(v, u);
            diff_arr[u] += diff_arr[v]; // Cộng dồn từ con lên cha
        }
    }
    // Gán kết quả cho cạnh nối u lên cha của nó
    if (u != 1) {
        ans_count[parent_edge[u]] = diff_arr[u];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (fopen("tr.inp", "r")) {
        freopen("tr.inp", "r", stdin);
        freopen("tr.out", "w", stdout);
    }

    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    for (int i = 1; i <= n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    tin[0] = 0;
    tout[0] = 1e9;
    dfs_lca(1, 0, 1);

    // Xử lý các truy vấn
    for (int i = 0; i < m; ++i) {
        int s;
        cin >> s;
        vector<int> nodes(s);
        for (int j = 0; j < s; ++j) {
            cin >> nodes[j];
        }

        // 1. Sắp xếp tập đỉnh theo thứ tự thăm DFS
        sort(nodes.begin(), nodes.end(), [](int a, int b) {
            return tin[a] < tin[b];
        });
        
        // Loại bỏ các đỉnh trùng lặp
        nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
        
        if (nodes.size() <= 1) continue;

        // 2. Xây dựng cây ảo (Virtual Tree) bằng Stack
        vector<int> st;
        st.push_back(nodes[0]);
        
        for (int j = 1; j < (int)nodes.size(); ++j) {
            int u = nodes[j];
            int lca = get_lca(st.back(), u);
            
            // Nếu phần tử kế top của stack vẫn nằm dưới hoặc bằng lca, rút cạnh và pop ra
            while (st.size() > 1 && h[st[st.size() - 2]] >= h[lca]) {
                add_virtual_edge(st[st.size() - 2], st.back());
                st.pop_back();
            }
            
            // Nếu top của stack (hiện tại) nằm sâu hơn lca, ta cần chèn lca vào để rẽ nhánh
            if (st.back() != lca) {
                add_virtual_edge(lca, st.back());
                st.pop_back();
                st.push_back(lca);
            }
            
            // Đưa đỉnh hiện tại vào stack
            st.push_back(u);
        }
        
        // Rút nốt các cạnh còn lại đang nằm trên stack
        while (st.size() > 1) {
            add_virtual_edge(st[st.size() - 2], st.back());
            st.pop_back();
        }
    }

    // Tính tổng tiền tố từ lá lên gốc
    dfs_sum(1, 0);

    // In kết quả
    vector<int> result;
    for (int i = 1; i <= n - 1; ++i) {
        if (ans_count[i] >= k) {
            result.push_back(i);
        }
    }

    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << (i + 1 == result.size() ? "" : " ");
    }
    cout << "\n";

    return 0;
}
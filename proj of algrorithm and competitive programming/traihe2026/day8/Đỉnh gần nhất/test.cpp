#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int MAXN = 100005;
const int LOG = 18;

vector<int> adj[MAXN];
int depth[MAXN];
int up[MAXN][LOG];

// ==========================================
// PHẦN 1: TÌM LCA VÀ TÍNH KHOẢNG CÁCH (LCA)
// ==========================================
void dfs_lca(int u, int p) {
    up[u][0] = p;
    for (int i = 1; i < LOG; i++) {
        up[u][i] = up[up[u][i-1]][i-1];
    }
    for (int v : adj[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs_lca(v, u);
        }
    }
}

int get_lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    
    for (int i = 0; i < LOG; i++) {
        if ((diff >> i) & 1) u = up[u][i];
    }
    if (u == v) return u;
    
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int get_dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[get_lca(u, v)];
}

// ==========================================
// PHẦN 2: PHÂN RÃ TRỌNG TÂM (CENTROID)
// ==========================================
bool del_node[MAXN];
int sz[MAXN];
int cent_par[MAXN];
int min_dist[MAXN];

// Tính kích thước cây con
void get_sz(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v != p && !del_node[v]) {
            get_sz(v, u);
            sz[u] += sz[v];
        }
    }
}

// Tìm trọng tâm
int get_centroid(int u, int p, int total) {
    for (int v : adj[u]) {
        if (v != p && !del_node[v] && sz[v] > total / 2) {
            return get_centroid(v, u, total);
        }
    }
    return u;
}

// Dựng cây trọng tâm
void build_centroid(int u, int p) {
    get_sz(u, -1);
    int centroid = get_centroid(u, -1, sz[u]);
    
    del_node[centroid] = true;
    cent_par[centroid] = p; // Lưu cha trên cây trọng tâm
    
    for (int v : adj[centroid]) {
        if (!del_node[v]) {
            build_centroid(v, centroid);
        }
    }
}

// ==========================================
// PHẦN 3: XỬ LÝ TRUY VẤN
// ==========================================
void update(int u) {
    int curr = u;
    while (curr != -1) {
        min_dist[curr] = min(min_dist[curr], get_dist(u, curr));
        curr = cent_par[curr];
    }
}

int query(int u) {
    int res = INF;
    int curr = u;
    while (curr != -1) {
        res = min(res, min_dist[curr] + get_dist(u, curr));
        curr = cent_par[curr];
    }
    return res;
}

int main() {
    // Tối ưu I/O trong C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Tiền xử lý LCA
    depth[1] = 0;
    dfs_lca(1, 1);

    // Tiền xử lý Cây trọng tâm
    build_centroid(1, -1);

    // Khởi tạo trạng thái ban đầu
    for (int i = 1; i <= n; i++) {
        min_dist[i] = INF;
    }
    update(1); // Đỉnh 1 ban đầu màu đỏ

    // Xử lý m truy vấn
    for (int i = 0; i < m; i++) {
        int type, v;
        cin >> type >> v;
        if (type == 1) {
            update(v);
        } else {
            cout << query(v) << "\n";
        }
    }

    return 0;
}
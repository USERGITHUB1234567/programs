#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 200005;

int parent_node[MAXN];
int sz[MAXN];
set<int> st[MAXN];
vector<int> adj[MAXN];

// Tìm gốc của tập hợp chứa đỉnh v (kèm tối ưu nén đường)
int find_set(int v) {
    if (v == parent_node[v]) return v;
    return parent_node[v] = find_set(parent_node[v]);
}

// Hàm hợp nhất hai thành phần liên thông trong DSU cùng với các danh sách kết nối
int merge_dsu(int u, int v) {
    int root_u = find_set(u);
    int root_v = find_set(v);
    if (root_u != root_v) {
        // Gộp DSU: Thành phần nhỏ hơn sẽ trỏ vào thành phần lớn hơn
        if (sz[root_u] < sz[root_v]) {
            swap(root_u, root_v);
        }
        parent_node[root_v] = root_u;
        sz[root_u] += sz[root_v];
        
        // Gộp set theo kĩ thuật "Nhỏ vào Lớn" (Small to Large) để tối ưu thời gian
        if (st[root_u].size() < st[root_v].size()) {
            swap(st[root_u], st[root_v]);
        }
        auto hint = st[root_u].begin();
        for (int x : st[root_v]) {
            hint = st[root_u].insert(hint, x); // Cung cấp hint giúp lệnh insert tốn ít thời gian (O(1) amortized)
        }
        st[root_v].clear();
    }
    return root_u;
}

int main() {
    // Tối ưu hóa I/O để chạy cực nhanh
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Khởi tạo DSU và chèn những kết nối ban đầu vào tập hợp
    for (int i = 1; i <= n; ++i) {
        parent_node[i] = i;
        sz[i] = 1;
        for (int v : adj[i]) {
            if (v > i) {
                st[i].insert(v);
            }
        }
    }

    long long total_filled_edges = 0;

    for (int u = 1; u <= n; ++u) {
        int current_root = find_set(u);
        
        // Hợp nhất u với mọi thành phần liên thông của láng giềng nhỏ hơn nó
        for (int v : adj[u]) {
            if (v < u) {
                current_root = merge_dsu(current_root, v);
            }
        }
        
        // Loại bỏ mọi láng giềng đã bị tháo khỏi mạng <= u
        while (!st[current_root].empty() && *st[current_root].begin() <= u) {
            st[current_root].erase(st[current_root].begin());
        }

        // Kích thước của danh sách hiện tại chính là số kết nối (đã có + mới) của u với các trạm > u
        total_filled_edges += st[current_root].size();
        //cerr << total_filled_edges << '\n';
    }

    // Kết quả là hiệu số giữa tổng kết nối lúc tháo bỏ và kết nối ban đầu
    cout << total_filled_edges - m << "\n";

    return 0;
}
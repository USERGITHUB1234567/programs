#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SparseDSU {
private:
    int n;
    int maxK;
    // Mảng lab 2 chiều: lab[k][u]
    // lab < 0: u là gốc, trị tuyệt đối là kích thước tập hợp
    // lab >= 0: chỉ tới đỉnh cha
    vector<vector<int>> lab;
    vector<int> min_pos;
    vector<int> max_pos;

public:
    SparseDSU(int _n) {
        init(_n);
    }

    inline void init(int _n) {
        n = _n;
        // Tính số lượng mức k cần thiết (log2(N) làm tròn lên)
        maxK = 32 - __builtin_clz(n); 
        lab.assign(maxK, vector<int>(n + 1, -1));
        
        min_pos.resize(n + 1);
        max_pos.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            min_pos[i] = i;
            max_pos[i] = i;
        }
    }

    // Tìm gốc của u ở mức k, kèm nén đường (path compression)
    inline int root(int k, int u) {
        return lab[k][u] < 0 ? u : lab[k][u] = root(k, lab[k][u]);
    }

    // Gộp 2 phân đoạn độ dài 2^k bắt đầu tại u và v
    inline void unite(int k, int u, int v) {
        int root_u = root(k, u);
        int root_v = root(k, v);
        
        if (root_u != root_v) {
            // Gộp theo size (Union by size):
            // lab lưu số âm, nên lab lớn hơn nghĩa là kích thước nhỏ hơn.
            if (lab[k][root_u] > lab[k][root_v]) {
                swap(root_u, root_v);
            }
            lab[k][root_u] += lab[k][root_v]; // Cộng dồn size
            lab[k][root_v] = root_u;          // root_v trỏ về root_u
            
            // Nếu là mức 0 (từng phần tử đơn lẻ), cập nhật vị trí min/max
            if (k == 0) {
                min_pos[root_u] = min(min_pos[root_u], min_pos[root_v]);
                max_pos[root_u] = max(max_pos[root_u], max_pos[root_v]);
            } else {
                // Nếu chưa phải mức 0, đệ quy đẩy xuống mức k-1
                unite(k - 1, u, v);
                unite(k - 1, u + (1 << (k - 1)), v + (1 << (k - 1)));
            }
        }
    }

    // Lấy đáp án cho truy vấn loại 1
    inline pair<int, int> get_bounds(int u) {
        int r = root(0, u);
        return {min_pos[r], max_pos[r]};
    }
};

int main() {
    // Tối ưu hóa I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    SparseDSU dsu(n);

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            pair<int, int> ans = dsu.get_bounds(x);
            cout << ans.first << " " << ans.second << "\n";
        } else if (type == 2) {
            int l, r, len;
            cin >> l >> r >> len;
            // Tìm số mũ k sao cho 2^k <= len < 2^(k+1)
            int k = 31 - __builtin_clz(len); 
            // Gộp 2 đoạn lớn nhất có thể phủ trọn độ dài len
            dsu.unite(k, l, r);
            dsu.unite(k, l + len - (1 << k), r + len - (1 << k));
        }
    }

    return 0;
}
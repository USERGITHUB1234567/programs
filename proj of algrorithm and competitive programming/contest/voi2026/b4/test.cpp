#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N, Q;
vector<int> A;
vector<int> P;
vector<bool> active_r; // Trạng thái kích hoạt của đĩa trong quá trình duyệt ngược
vector<int> parent_dsu;
vector<long long> M_dsu;
vector<long long> S_dsu;
vector<map<int, int>> freq_dsu;

// Hàm tìm gốc của tập hợp trong DSU
int find_set(int v) {
    if (v == parent_dsu[v])
        return v;
    return parent_dsu[v] = find_set(parent_dsu[v]);
}

// Hàm tính độ đa dạng hiện tại của một thành phần liên thông
long long get_diversity(int u) {
    u = find_set(u);
    long long len = M_dsu[u];
    return 1 + len * (len - 1) / 2 - S_dsu[u];
}

// Hàm gộp hai đoạn con bằng kỹ thuật Small-to-Large
void union_sets(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u == v) return;
    
    // Đảm bảo u luôn là tập hợp có map lớn hơn
    if (freq_dsu[u].size() < freq_dsu[v].size()) {
        swap(u, v);
    }
    
    parent_dsu[v] = u;
    M_dsu[u] += M_dsu[v];
    
    // Chuyển các phần tử từ map v sang map u và cập nhật S
    for (auto const& [val, count] : freq_dsu[v]) {
        long long old_cnt = freq_dsu[u][val];
        S_dsu[u] -= old_cnt * (old_cnt - 1) / 2;
        
        long long new_cnt = old_cnt + count;
        freq_dsu[u][val] = new_cnt;
        S_dsu[u] += new_cnt * (new_cnt - 1) / 2;
    }
    freq_dsu[v].clear(); // Giải phóng bộ nhớ của map v đã gộp xong
}

int main() {
    // Tối ưu hóa I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    if (!(cin >> N >> Q)) return 0;
    
    A.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    
    P.resize(Q + 1);
    vector<bool> removed(N + 1, false);
    for (int j = 1; j <= Q; ++j) {
        cin >> P[j];
        removed[P[j]] = true; // Đánh dấu các đĩa bị lấy đi
    }
    
    // Khởi tạo cấu trúc dữ liệu DSU
    active_r.assign(N + 1, false);
    parent_dsu.resize(N + 1);
    M_dsu.assign(N + 1, 0);
    S_dsu.assign(N + 1, 0);
    freq_dsu.resize(N + 1);
    
    // Kích hoạt các đĩa không bao giờ bị khách lấy
    for (int i = 1; i <= N; ++i) {
        parent_dsu[i] = i;
        if (!removed[i]) {
            active_r[i] = true;
            M_dsu[i] = 1;
            freq_dsu[i][A[i]] = 1;
            S_dsu[i] = 0;
        }
    }
    
    // Gộp các đĩa không bao giờ bị lấy đứng cạnh nhau thành các đoạn ban đầu
    for (int i = 1; i <= N; ++i) {
        if (active_r[i]) {
            if (i > 1 && active_r[i - 1]) {
                union_sets(i, i - 1);
            }
        }
    }
    
    // Tìm độ đa dạng lớn nhất từ trạng thái nền ban đầu
    long long max_div = 0;
    for (int i = 1; i <= N; ++i) {
        if (active_r[i] && parent_dsu[i] == i) {
            max_div = max(max_div, get_diversity(i));
        }
    }
    
    // Tiến hành xử lý ngược từ truy vấn cuối lên đầu
    vector<long long> ans(Q + 1);
    for (int j = Q; j >= 1; --j) {
        ans[j] = max_div; // Kết quả ngay sau khi vị khách j lấy đĩa chính là max_div hiện tại
        
        int p = P[j];
        active_r[p] = true;
        M_dsu[p] = 1;
        freq_dsu[p][A[p]] = 1;
        S_dsu[p] = 0;
        max_div = max(max_div, get_diversity(p));
        
        // Gộp với phần tử liền kề bên trái nếu có
        if (p > 1 && active_r[p - 1]) {
            union_sets(p, p - 1);
            max_div = max(max_div, get_diversity(p));
        }
        // Gộp với phần tử liền kề bên phải nếu có
        if (p < N && active_r[p + 1]) {
            union_sets(p, p + 1);
            max_div = max(max_div, get_diversity(p));
        }
    }
    
    // In ra kết quả theo đúng thứ tự các vị khách đến
    for (int j = 1; j <= Q; ++j) {
        cout << ans[j] << "\n";
    }
    
    return 0;
}
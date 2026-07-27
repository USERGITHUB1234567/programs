#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

const int MAXN = 1005;

struct Edge {
    int v;
    double c;
};

int n, m;
vector<Edge> adj[MAXN];

// Hàm kiểm tra xem có tồn tại chu trình âm nếu trừ mọi cạnh đi 'mid' hay không
bool check(double mid) {
    vector<double> dist(n + 1, 0.0);
    vector<int> cnt(n + 1, 0);
    vector<bool> inQueue(n + 1, true);
    queue<int> q;

    // Đẩy tất cả các đỉnh vào hàng đợi ban đầu
    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inQueue[u] = false;

        for (auto edge : adj[u]) {
            int v = edge.v;
            // Trọng số mới = Trọng số cũ - mid
            double weight = edge.c - mid; 

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                cnt[v] = cnt[u] + 1;

                // Nếu số cạnh trên đường đi >= N -> Có chu trình âm
                if (cnt[v] >= n) {
                    return true;
                }

                if (!inQueue[v]) {
                    q.push(v);
                    inQueue[v] = true;
                }
            }
        }
    }
    return false; // Không có chu trình âm
}

int main() {
    // Tối ưu I/O để chạy nhanh hơn
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;

    for (int i = 0; i < m; ++i) {
        int u, v;
        double c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
    }

    // Kiểm tra xem đồ thị có tồn tại bất kỳ chu trình nào không
    // Chọn một giá trị siêu lớn, nếu không có chu trình âm -> đồ thị không có chu trình
    if (!check(1e10)) {
        cout << "NO TOUR\n";
        return 0;
    }

    // Chặt nhị phân tìm chi phí trung bình nhỏ nhất
    double low = 0.0, high = 1e9;
    double ans = 0.0;
    
    // Lặp 65 lần để đảm bảo độ chính xác tuyệt đối cho số thực
    for (int iter = 0; iter < 65; ++iter) {
        double mid = low + (high - low) / 2.0;
        
        if (check(mid)) {
            ans = mid;    // Có thể đạt được mức phí <= mid, lưu lại và thử tìm mức thấp hơn
            high = mid;
        } else {
            low = mid;    // Không đạt được, phải tăng mức phí lên
        }
    }

    // In ra kết quả làm tròn đúng 2 chữ số thập phân
    cout << fixed << setprecision(2) << ans << "\n";

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // prev[i]: vị trí gần nhất bên trái có giá trị giống a[i]
    // next[i]: vị trí gần nhất bên phải có giá trị giống a[i]
    vector<int> prev_pos(n, -1), next_pos(n, n);
    
    // Vì a[i] <= n nên mảng lưu vị trí cuối cùng có kích thước n + 1
    vector<int> last_pos(n + 1, -1);
    
    for (int i = 0; i < n; i++) {
        prev_pos[i] = last_pos[a[i]];
        last_pos[a[i]] = i;
    }

    fill(last_pos.begin(), last_pos.end(), n);
    for (int i = n - 1; i >= 0; i--) {
        next_pos[i] = last_pos[a[i]];
        last_pos[a[i]] = i;
    }

    // Hàm đệ quy chia để trị
    auto check = [&](auto& self, int l, int r) -> bool {
        if (l >= r) return true; // Đoạn có 1 hoặc 0 phần tử luôn hợp lệ
        
        int i = l, j = r;
        // Tìm phần tử xuất hiện duy nhất bằng cách chạy 2 con trỏ từ 2 đầu vào giữa
        while (i <= j) {
            // Kiểm tra phần tử a[i]
            if (prev_pos[i] < l && next_pos[i] > r) {
                return self(self, l, i - 1) && self(self, i + 1, r);
            }
            // Kiểm tra phần tử a[j]
            if (prev_pos[j] < l && next_pos[j] > r) {
                return self(self, l, j - 1) && self(self, j + 1, r);
            }
            i++;
            j--;
        }
        
        // Nếu duyệt hết đoạn mà không có phần tử nào xuất hiện duy nhất 1 lần
        return false;
    };

    if (check(check, 0, n - 1)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Tối ưu hóa I/O để chạy nhanh hơn
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
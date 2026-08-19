#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Tối ưu hóa I/O trong C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> a(n);
    int sum_a = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum_a += a[i];
    }

    vector<int> b(m);
    int sum_b = 0;
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        sum_b += b[i];
    }

    // Nếu tổng số tiền ngân hàng có ít hơn tổng số lương cần trả thì chắc chắn không đủ
    if (sum_a > sum_b) {
        cout << "NO\n";
        return 0;
    }

    // Mảng cộng dồn mức lương cần thiết
    vector<int> S(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        S[i + 1] = S[i] + a[i];
    }

    // next_S[x] lưu mục tiêu cần đạt được (tổng tích luỹ S_k) tiếp theo nếu tổng hiện tại là x
    vector<int> next_S(sum_b + 1, -1);
    int current_k = 0;
    for (int x = 0; x <= sum_b; ++x) {
        if (current_k < n && x >= S[current_k + 1]) {
            current_k++;
        }
        if (current_k < n) {
            next_S[x] = S[current_k + 1];
        } else {
            next_S[x] = -1;
        }
    }

    // Tính trước tổng tiền cho mỗi cấu hình mask
    int num_masks = 1 << m;
    vector<int> sum_mask(num_masks, 0);
    for (int i = 1; i < num_masks; ++i) {
        int lowest = i & -i; 
        int bit = __builtin_ctz(lowest); 
        sum_mask[i] = sum_mask[i ^ lowest] + b[bit];
    }

    // Khởi tạo mảng Quy hoạch động
    vector<bool> dp(num_masks, false);
    dp[0] = true;

    bool possible = false;
    for (int i = 0; i < num_masks; ++i) {
        if (!dp[i]) continue;
        
        // Nếu đạt được tổng số lương yêu cầu cho tất cả mọi người
        if (sum_mask[i] == S[n]) {
            possible = true;
            break;
        }

        int target = next_S[sum_mask[i]];
        if (target == -1) continue;

        // Chỉ xét các tờ tiền chưa được sử dụng
        int avail = (num_masks - 1) ^ i;
        while (avail > 0) {
            int lowest = avail & -avail;
            int bit = __builtin_ctz(lowest);
            
            // Chỉ thêm tờ tiền nếu chưa vượt quá mốc trả lương đang xử lý của người hiện tại
            if (sum_mask[i] + b[bit] <= target) {
                dp[i | lowest] = true;
            }
            avail ^= lowest;
        }
    }

    // In kết quả
    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
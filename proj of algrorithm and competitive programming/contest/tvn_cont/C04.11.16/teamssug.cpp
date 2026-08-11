#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // Dùng 1e9 để tránh tràn số khi trừ

struct Player {
    int s, p;
    // Sắp xếp theo P giảm dần
    bool operator<(const Player& other) const {
        return p > other.p; 
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Lưu ý: Trên ClueOJ (DMOJ) thường dùng Standard I/O (stdin/stdout)
    // Bạn hãy cân nhắc mở comment 2 dòng freopen dưới nếu thực sự nộp file
    // freopen("TEAMS.INP", "r", stdin);
    // freopen("TEAMS.OUT", "w", stdout);

    int n;
    if (!(cin >> n)) return 0;

    vector<Player> players(n);
    int total_s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> players[i].s;
        total_s += players[i].s;
    }
    for (int i = 0; i < n; ++i) cin >> players[i].p;

    // BƯỚC 1: Sort giảm dần theo P để fix Đội trưởng
    sort(players.begin(), players.end());

    // BƯỚC 2: Khởi tạo bảng DP
    // dp1[j]: Max P_A với tổng kỹ năng đội A = j (Đội B chưa có ai)
    vector<int> dp1(total_s + 1, -INF);
    
    // dp2[j]: Max (P_A - P_B) với (Tổng A - Tổng B) = j - total_s 
    // Cộng thêm offset total_s để xử lý chỉ số âm
    vector<int> dp2(2 * total_s + 1, -INF);

    int curr_s = 0; // Biến tối ưu: Tổng kỹ năng tối đa có thể với i học sinh đầu tiên

    for (int i = 0; i < n; ++i) {
        int s = players[i].s;
        int p = players[i].p;

        // Dùng mảng tạm để tránh lỗi Unbounded Knapsack (dùng 1 người nhiều lần)
        vector<int> nxt_dp1 = dp1;
        vector<int> nxt_dp2 = dp2;

        // Hành động 1: Cho học sinh vào Đội A làm Đội trưởng (Mở bát)
        nxt_dp1[s] = max(nxt_dp1[s], p);

        // Hành động 2: Cho học sinh vào Đội A (Khi đội A đã có Đội trưởng)
        for (int j = 0; j <= curr_s; ++j) {
            if (dp1[j] != -INF) {
                nxt_dp1[j + s] = max(nxt_dp1[j + s], dp1[j]);
            }
        }

        // Hành động 3: Cho học sinh vào Đội B làm Đội trưởng (Bước chuyển từ dp1 -> dp2)
        // Hiệu số kỹ năng ban đầu là j, sau khi trừ s vào đội B sẽ là (j - s)
        for (int j = 0; j <= curr_s; ++j) {
            if (dp1[j] != -INF) {
                nxt_dp2[j - s + total_s] = max(nxt_dp2[j - s + total_s], dp1[j] - p);
            }
        }

        // Hành động 4 & 5: Cho học sinh vào Đội A hoặc Đội B (Khi cả 2 đội đều đã có Đội trưởng)
        // Lặp trong khoảng diff khả thi [-curr_s, curr_s] -> cộng offset
        for (int j = total_s - curr_s; j <= total_s + curr_s; ++j) {
            if (dp2[j] != -INF) {
                // Hành động 4: Vào Đội A (Hiệu kỹ năng tăng)
                nxt_dp2[j + s] = max(nxt_dp2[j + s], dp2[j]);
                // Hành động 5: Vào Đội B (Hiệu kỹ năng giảm)
                nxt_dp2[j - s] = max(nxt_dp2[j - s], dp2[j]);
            }
        }

        // Cập nhật lại mảng DP cho người tiếp theo
        dp1 = move(nxt_dp1);
        dp2 = move(nxt_dp2);
        curr_s += s; // Cập nhật biên kỹ năng để vòng lặp chạy nhanh hơn
    }

    // Kết quả cuối cùng là lúc 2 đội có chênh lệch kỹ năng bằng 0 (Index chính giữa total_s)
    cout << dp2[total_s] << "\n";

    return 0;
}
/*
8
4 7 3 8 5 6 9 2
15 3 20 11 8 30 6 25
*/
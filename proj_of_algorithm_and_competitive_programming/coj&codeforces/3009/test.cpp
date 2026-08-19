#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Hàm tìm số nguyên P trong đoạn [A, B] có biểu diễn chuỗi (string) nhỏ nhất theo thứ tự từ điển
string get_best_string(long long A, long long B, string pref = "") {
    if (pref != "") {
        long long val = stoll(pref);
        if (val >= A && val <= B) return pref;
    }
    
    int start_d = (pref == "") ? 1 : 0;
    for (int d = start_d; d <= 9; ++d) {
        string nxt_str = pref + to_string(d);
        long long nxt_val = stoll(nxt_str);
        bool possible = false;
        
        long long low = nxt_val;
        long long high = nxt_val;
        
        // Kiểm tra xem tiền tố này có thể sinh ra số nào nằm trong [A, B] không
        for (int k = 0; k <= 10; ++k) {
            if (max(A, low) <= min(B, high)) {
                possible = true;
                break;
            }
            if (low > 2e18 / 10) break; // Tránh tràn số (overflow)
            low = low * 10;
            high = high * 10 + 9;
        }
        
        // Nếu có, đi sâu vào nhánh này vì nó sẽ cho chuỗi nhỏ nhất
        if (possible) {
            return get_best_string(A, B, nxt_str);
        }
    }
    return "";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> a(n);
    long long M = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > M) M = a[i];
    }

    // Đếm số lượng bánh có kích thước lớn nhất M và lưu chỉ số
    int c = 0;
    vector<int> C_list;
    for (int i = 0; i < n; ++i) {
        if (a[i] == M) {
            c++;
            C_list.push_back(i);
        }
    }

    // Tìm kích thước lớn thứ hai K và số lượng của nó c_K
    long long K = 0;
    int c_K = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != M && a[i] > K) {
            K = a[i];
            c_K = 1;
        } else if (a[i] != M && a[i] == K && K > 0) {
            c_K++;
        }
    }

    string best_move = "";

    // Hàm lambda cập nhật kết quả có thứ tự từ điển nhỏ nhất
    auto update_best = [&](int C, string P_str) {
        string move = "CAKE " + to_string(C) + " PIECES " + P_str;
        if (best_move == "" || move < best_move) {
            best_move = move;
        }
    };

    if (c % 2 == 0 || c >= 3) {
        // Trạng thái c chẵn hoặc lẻ >= 3: P = 1 luôn cho xâu nhỏ nhất
        for (int C : C_list) {
            update_best(C, "1");
        }
    } else {
        // Trạng thái c = 1
        int C = C_list[0];
        if (c_K % 2 != 0) {
            // c_K lẻ: Bắt buộc phải ăn chừa lại đúng K miếng
            update_best(C, to_string(M - K));
        } else {
            // c_K chẵn
            if (K == 0) {
                // Không còn bánh nào khác, phải ăn toàn bộ
                update_best(C, to_string(M));
            } else {
                // Có thể ăn để lại số lượng tùy ý từ 0 đến K-1 miếng
                // Tức là lượng ăn P nằm trong khoảng [M - K + 1, M]
                string best_P = get_best_string(M - K + 1, M);
                update_best(C, best_P);
            }
        }
    }

    cout << best_move << "\n";
    return 0;
}
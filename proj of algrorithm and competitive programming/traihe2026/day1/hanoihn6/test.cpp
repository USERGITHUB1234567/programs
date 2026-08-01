#pragma GCC optimize("O3")
#include <iostream>

using namespace std;

// Mảng lưu số bước tối thiểu cho tháp 4 cọc
long long dp[105];
// Mảng lưu k tối ưu để chia bài toán
int best_k[105];

// Hàm đệ quy tháp Hà Nội 3 cọc cổ điển
void solve3(int n, char source, char dest, char aux) {
    if (n == 0) return;
    if (n == 1) {
        cout << source << dest << '\n';
        return;
    }
    solve3(n - 1, source, aux, dest);
    cout << source << dest << '\n';
    solve3(n - 1, aux, dest, source);
}

// Hàm đệ quy tháp Hà Nội 4 cọc
void solve4(int n, char source, char dest, char aux1, char aux2) {
    if (n == 0) return;
    if (n == 1) {
        cout << source << dest << '\n';
        return;
    }
    
    int k = best_k[n];
    
    // Bước 1: Chuyển k đĩa lên cọc trung gian thứ nhất, dùng cả 4 cọc
    solve4(n - k, source, aux1, aux2, dest);
    
    // Bước 2: Chuyển (n-k) đĩa lớn nhất sang cọc đích, chỉ dùng 3 cọc
    solve3(k, source, dest, aux2);
    
    // Bước 3: Chuyển k đĩa từ cọc trung gian thứ nhất sang cọc đích, dùng cả 4 cọc
    solve4(n - k, aux1, dest, source, aux2);
}

int main() {
    // Tối ưu I/O (Rất quan trọng vì output có thể lên tới hàng trăm ngàn dòng cho N=100)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    // Khởi tạo DP
    dp[1] = 1;
    best_k[1] = 0;
    
    for (int i = 2; i <= 100; ++i) {
        dp[i] = 2e18; // Set max vô cùng
        for (int k = 1; k < i; ++k) {
            // Với n=100, tháp 4 cọc chỉ cần i-k rơi vào khoảng <= 14. 
            // Ta chặn i - k > 60 để tránh tràn giới hạn kiểu long long khi tính 2^(i-k)
            if (k > 60) continue; 
            
            long long moves3 = (1LL << (k)) - 1; 
            long long current_moves = 2 * dp[i - k] + moves3;
            
            if (current_moves < dp[i]) {
                dp[i] = current_moves;
                best_k[i] = k;
            }
        }
    }
    
    // In ra tổng số bước
    cout << dp[n] << '\n';
    
    // In lộ trình: Nguồn A, Đích D, 2 cọc trung gian là B và C
    solve4(n, 'A', 'D', 'B', 'C');
    
    return 0;
}
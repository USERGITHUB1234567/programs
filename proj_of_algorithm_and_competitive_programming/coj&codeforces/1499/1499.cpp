#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXK = 17;
const int MAXN = 1e5 + 1;

int st[MAXK + 1][MAXN];
int k = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;  // Đọc số phần tử và số truy vấn
    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Xác định số mức k cho bảng Sparse Table
    while ((1 << k) <= n) k++;
    k--;

    // Khởi tạo Sparse Table cho mức đầu tiên
    for (int j = 1; j <= n; j++) {
        st[0][j] = a[j];
    }

    // Xây dựng các mức còn lại của Sparse Table
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }

    // Xử lý các truy vấn
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = INT_MAX;  // Khởi tạo `ans` là `INT_MAX` để tìm min đúng

        // Tính giá trị min trong đoạn [l, r]
        for (int i = k; i >= 0; i--) {
            if ((1 << i) <= r - l + 1) {
                ans = min(ans, st[i][l]);
                l += (1 << i);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}

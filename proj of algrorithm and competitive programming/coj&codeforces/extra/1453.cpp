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

    int n, q, m;
    cin >> n >> q >> m;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Tìm giá trị k lớn nhất sao cho 2^k <= n
    while ((1 << k) <= n) k++;
    k--;

    // Khởi tạo bảng Sparse Table cho mức đầu tiên (i = 0)
    for (int j = 1; j <= n; j++) {
        st[0][j] = a[j] % m;
    }

    // Xây dựng các mức còn lại của Sparse Table
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            st[i][j] = 1LL * st[i - 1][j] * st[i - 1][j + (1 << (i - 1))] % m;
        }
    }

    // Xử lý từng truy vấn
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = 1;

        // Tính tích của đoạn [l, r] với chia để trị dựa trên bảng Sparse Table
        for (int i = k; i >= 0; i--) {
            if ((1 << i) <= r - l + 1) {
                ans = 1LL * ans * st[i][l] % m;
                l += (1 << i);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}

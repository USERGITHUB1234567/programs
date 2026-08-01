#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);  // Sử dụng vector thay cho mảng động
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    queue<int> q;
    int vt = 0;  // Vị trí hiện tại

    for (int i = 0; i < n; i++) {
        if (a[i] > vt) {
            // Đẩy các giá trị từ vt+1 đến a[i]-1 vào hàng đợi
            for (int j = vt + 1; j < a[i]; j++) {
                q.push(j);
            }
            vt = a[i];  // Cập nhật vt thành giá trị hiện tại a[i]
        } else {
            // Kiểm tra hàng đợi và điều kiện pop
            if (!q.empty() && q.front() == a[i]) {
                q.pop();
            } else {
                cout << "No";
                return 0;
            }
        }
    }

    cout << "Yes";
    return 0;
}

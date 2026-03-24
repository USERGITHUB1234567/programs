#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    // Sử dụng vector<bool> để lưu trạng thái "đã nhận quà"
    vector<bool> hasGift(n + 1, false);
    int child;

    // Đọc danh sách những người nhận quà ở túi thứ nhất
    for (int i = 0; i < m; i++) {
        cin >> child;
        hasGift[child] = true;
    }

    // Đọc danh sách những người nhận quà ở túi thứ hai
    for (int i = 0; i < k; i++) {
        cin >> child;
        hasGift[child] = true;
    }

    // Tìm danh sách những người nhận quà ở túi thứ ba (không có trong túi 1 và túi 2)
    vector<int> bag3;
    for (int i = 1; i <= n; i++) {
        if (!hasGift[i]) {
            bag3.push_back(i);
        }
    }

    // Xuất kết quả
    cout << bag3.size() << "\n";
    if (!bag3.empty()) {
        for (int i = 0; i < bag3.size(); i++) {
            cout << bag3[i];
            if (i != bag3.size() - 1)
                cout << " ";
        }
    }

    return 0;
}

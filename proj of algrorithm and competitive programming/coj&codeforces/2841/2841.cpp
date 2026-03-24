#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int t; // Số test
    cin >> t;

    while (t--) {
        int n; // Số chữ số bị cấm
        cin >> n;

        set<int> forbidden; // Tập chứa các chữ số bị cấm
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            forbidden.insert(x);
        }

        // Lấy các chữ số còn lại (0-9 không thuộc tập bị cấm)
        vector<int> available;
        for (int i = 0; i <= 9; ++i) {
            if (!forbidden.count(i)) {
                available.push_back(i);
            }
        }

        int k = available.size();
        if (k < 2) {
            cout << 0 << endl; // Không đủ chữ số để tạo mật khẩu
            continue;
        }

        // Số cặp (2 chữ số khác nhau) có thể chọn từ available: C(k, 2)
        int combinations = (k * (k - 1)) / 2;

        // Với mỗi cặp, có đúng 6 hoán vị hợp lệ
        cout << combinations * 6 << endl;
    }

    return 0;
}

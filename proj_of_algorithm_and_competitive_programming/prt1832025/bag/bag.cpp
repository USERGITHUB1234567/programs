#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long s;
    cin >> n >> s;

    vector<long long> w(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) cin >> c[i];

    long long max_value = 0, current_weight = 0, current_value = 0;
    int left = 1;

    for (int right = 1; right <= n; right++) {
        // Thêm phần tử hiện tại vào tổng
        current_weight += w[right];
        current_value += c[right];

        // Kiểm tra nếu trọng lượng vượt quá giới hạn
        while (current_weight > s) {
            current_weight -= w[left];
            current_value -= c[left];
            left++;
        }

        // Cập nhật giá trị lớn nhất
        max_value = max(max_value, current_value);
    }

    cout << max_value << endl;
    return 0;
}

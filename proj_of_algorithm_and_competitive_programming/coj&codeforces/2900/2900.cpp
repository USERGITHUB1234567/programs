#include <iostream>
using namespace std;

// Hàm tính toán vị trí người sống sót cuối cùng trong bài toán Josephus
int josephus(int n, int k) {
    int result = 0; // Vị trí người sống sót cuối cùng trong vòng tròn có 1 người
    for (int i = 2; i <= n; ++i) {
        result = (result + k) % i;
    }
    return result + 1; // Chuyển từ chỉ số 0-based sang 1-based
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        cout << josephus(n, k) << "\n";
    }

    return 0;
}

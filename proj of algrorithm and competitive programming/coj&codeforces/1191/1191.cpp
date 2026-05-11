#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; // Số hộp chứa vi khuẩn
    cin >> n;

    vector<long long> prefixSum(n + 1, 0); // Mảng tích lũy
    for (int i = 1; i <= n; ++i) {
        int ai;
        cin >> ai;
        prefixSum[i] = prefixSum[i - 1] + ai;
    }

    int m; // Số con vi khuẩn cần lấy ra
    cin >> m;
    while (m--) {
        long long qi;
        cin >> qi;

        // Tìm kiếm nhị phân để xác định hộp chứa con vi khuẩn
        int box = lower_bound(prefixSum.begin(), prefixSum.end(), qi) - prefixSum.begin();
        cout << box << endl;
    }

    return 0;
}

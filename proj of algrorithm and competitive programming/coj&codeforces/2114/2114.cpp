#include <iostream>
using namespace std;

int main() {
    long long k;
    cin >> k;

    long long n = k / 5;
    long long remainder = k % 5;

    // Tính tổng thời gian cho các nhóm 5 lần bấm
    long long total_time = 5 * n * (30 + 30 * (n - 1) / 2);

    // Tính thời gian cho các lần bấm còn lại
    total_time += remainder * (30 + 30 * n);

    cout << total_time << endl;

    return 0;
}

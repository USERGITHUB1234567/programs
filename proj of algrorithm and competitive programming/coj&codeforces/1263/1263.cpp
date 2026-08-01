#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string N;
    cin >> N;

    // Kiểm tra xem có chữ số 0 hay không
    if (N.find('0') == string::npos) {
        cout << -1 << endl;
        return 0;
    }

    // Tính tổng các chữ số
    int sum = 0;
    for (char c : N) {
        sum += c - '0';
    }

    // Kiểm tra xem tổng các chữ số có chia hết cho 3 hay không
    if (sum % 3 != 0) {
        cout << -1 << endl;
        return 0;
    }

    // Sắp xếp các chữ số theo thứ tự giảm dần để tạo số lớn nhất
    sort(N.rbegin(), N.rend());
    cout << N << endl;

    return 0;
}

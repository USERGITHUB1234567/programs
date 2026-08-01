#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Tìm ước chung lớn nhất của tất cả các phần tử trong mảng
    int gcd_all = a[0];
    for (int i = 1; i < n; ++i) {
        gcd_all = __gcd(gcd_all, a[i]);
    }

    // Kiểm tra xem GCD có phải là một phần tử trong mảng hay không
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (a[i] == gcd_all) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << gcd_all << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}

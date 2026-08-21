#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    while(n--) {
        // Sử dụng long long để đảm bảo các phép tính với giá trị lớn
        long long a, b;
        cin >> a >> b;

        // Nếu tổng a + b không chia hết cho 2 thì không có x nguyên thỏa mãn
        if ((a + b) % 2 != 0)
            cout << "No" << "\n";
        else
            cout << (a + b) / 2 << "\n";
    }

    return 0;
}

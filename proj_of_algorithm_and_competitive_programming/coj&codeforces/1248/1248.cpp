#include <iostream>
#include <string>

using namespace std;

int main() {
    string x;
    cin >> x;

    for (int i = 0; i < x.length(); ++i) {
        int digit = x[i] - '0';
        int inverted_digit = 9 - digit;
        if (inverted_digit < digit) {
            // Đảm bảo số cuối cùng không bắt đầu bằng chữ số 0
            if (i == 0 && inverted_digit == 0) {
                continue;
            }
            x[i] = inverted_digit + '0';
        }
    }

    cout << x << endl;
    return 0;
}

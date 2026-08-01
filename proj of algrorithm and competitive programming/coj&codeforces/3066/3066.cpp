#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int count = 0; // Đếm số ký tự cần xóa
    for (int i = 0; i < n - 2; ) { // Duyệt qua các ký tự trong xâu
        if (s[i] == 'x' && s[i + 1] == 'x' && s[i + 2] == 'x') {
            count++; // Phát hiện "xxx", cần xóa 1 ký tự
            i++; // Tiếp tục kiểm tra từ ký tự tiếp theo
        } else {
            i++; // Chuyển sang ký tự tiếp theo
        }
    }

    cout << count << endl; // In kết quả
    return 0;
}

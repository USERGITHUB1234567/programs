#include <bits/stdc++.h>

int main() {
    std::cout << "Chú ý: chương trình sẽ tắt máy. Tiếp tục? (yes/no): ";
    std::string ans;
    std::cin >> ans;
    if (ans == "yes") {
        // Yêu cầu chạy chương trình bằng sudo hoặc sẽ không có quyền
        int ret = std::system("sudo shutdown -h now");
        if (ret != 0) std::cerr << "Lệnh tắt máy thất bại hoặc không có quyền.\n";
    } else {
        std::cout << "Hủy lệnh tắt máy.\n";
    }
    return 0;
}

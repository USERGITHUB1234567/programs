#include <iostream>
#include <functional>
#include <cmath>
using namespace std;

// Hàm ternary_search_min nhận vào:
/// - lo, hi: khoảng tìm kiếm trên trục số thực.
/// - f: một hàm số (kiểu std::function<double(double)>) mà ta giả sử là unimodal trên [lo, hi],
///        tức có duy nhất một cực tiểu (minimum) trong khoảng đó.
/// Hàm trả về giá trị cực tiểu của f(x) (bạn cũng có thể điều chỉnh để trả về x tối ưu nếu cần).
double ternary_search_min(double lo, double hi, function<double(double)> f) {
    const double eps = 1e-9; // độ chính xác, có thể điều chỉnh theo yêu cầu
    while (hi - lo > eps) {
        double m1 = lo + (hi - lo) / 3.0;
        double m2 = hi - (hi - lo) / 3.0;
        // So sánh giá trị của f tại m1 và m2 để xác định phía có cực tiểu
        if (f(m1) < f(m2))
            hi = m2;
        else
            lo = m1;
    }
    return f(lo); // Hoặc trả về (lo + hi) / 2 nếu cần trả về x tối ưu.
}

int main() {
    // Ví dụ sử dụng: Tìm kiếm cực tiểu của hàm f(x) = (x - 2)^2 + 3, cực tiểu đạt tại x = 2
    auto f = [](double x) -> double {
        return (x - 2) * (x - 2) + 3;
    };

    double lo = -100, hi = 100;
    double min_value = ternary_search_min(lo, hi, f);

    cout << "Gia tri nho nhat cua f(x) o doan [" << lo << ", " << hi << "] la: " << min_value << "\n";
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    // Sử dụng kiểu long long để xử lý trường hợp m, n có giá trị lớn (lớn nhất 10^9, tích có thể lên tới 10^18)
    long long m, n;
    cin >> m >> n;

    // Tổng số ô vuông của công viên
    long long total = m * n;

    // Mỗi đèn có thể chiếu sáng tối đa 2 ô vuông nên số đèn tối thiểu là: ceil(total/2)
    long long lamps = (total + 1) / 2;

    cout << lamps;
    return 0;
}

#include <iostream>
#include <unordered_map>
using namespace std;

// Ta định nghĩa trạng thái bằng vị trí và hướng (d = 1: sang phải, d = -1: sang trái)
// Hàm encodeState chuyển (pos, d) thành một số nguyên duy nhất (vì m ≤ 100 nên cách mã hóa đơn giản là đủ)
long long encodeState(int pos, int d) {
    // Dùng công thức đơn giản: mỗi trạng thái là: pos * 10 + (d==1 ? 1 : 2)
    return pos * 10LL + (d == 1 ? 1LL : 2LL);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    long long n;
    cin >> m >> n;

    // Mảng gạch được đánh số từ 1 đến m.
    // a[i] = 0: viên gạch màu vàng, a[i] > 0: viên gạch màu trắng,
    // a[i] = 2 hoặc 3: chỉ ra vị trí và hướng ban đầu của Gholam.
    int a[102];
    int startPos = -1;
    int startDir = 0; // 1 nếu hướng sang phải (khi a[i] == 2), -1 nếu sang trái (khi a[i] == 3)

    for (int i = 1; i <= m; i++){
        cin >> a[i];
        if(a[i] > 1){ // xác định vị trí khởi đầu; đảm bảo chỉ có một số như vậy.
            startPos = i;
            startDir = (a[i] == 2 ? 1 : -1);
        }
    }

    // Số bước đã đi và số lần bước lên gạch vàng (chỉ tính khi “đặt chân” lên)
    long long steps = 0, yellow = 0;
    int pos = startPos, d = startDir;

    // Sử dụng bảng băm để lưu trạng thái (đã gặp trạng thái nào rồi, lưu theo: {số bước đã đi, số vàng được đếm})
    unordered_map<long long, pair<long long, long long>> seen;
    seen[encodeState(pos, d)] = {0, 0};  // trạng thái ban đầu, tại bước 0, yellow = 0

    // Mô phỏng chuyển động đến khi đi đủ n bước
    while (steps < n) {
        // Tính vị trí kế theo hướng hiện tại
        int next = pos + d;
        // Nếu vượt ra ngoài [1, m] thì quay 180 độ và tính lại vị trí kế
        if (next < 1 || next > m) {
            d = -d;
            next = pos + d;
        }
        pos = next;
        if (a[pos] == 0) {
            yellow++;  // đếm mỗi lần bước sang viên gạch màu vàng
        }
        steps++;
        if (steps == n)
            break;

        long long stateKey = encodeState(pos, d);
        // Nếu trạng thái đã được gặp trước đó rồi => bắt chu kỳ
        if (seen.find(stateKey) != seen.end()){
            auto prev = seen[stateKey];
            long long cycleSteps = steps - prev.first;
            long long cycleYellows = yellow - prev.second;
            long long remaining = n - steps;
            long long cycles = remaining / cycleSteps;

            yellow += cycles * cycleYellows;
            steps += cycles * cycleSteps;
        }
        else {
            seen[stateKey] = {steps, yellow};
        }
    }

    cout << yellow;
    return 0;
}

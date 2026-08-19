#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Tối ưu hóa I/O để đọc chuỗi lớn nhanh hơn
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    
    string s;
    cin >> s;

    int blocks = 0;
    int unique_count = 0;
    vector<bool> seen(n, false);

    // Quét qua từng ký tự của chuỗi s
    for (char c : s) {
        int idx = c - 'a';
        
        // Chỉ quan tâm đến các ký tự nằm trong bảng chữ cái n ký tự đầu tiên
        if (idx >= 0 && idx < n) {
            if (!seen[idx]) {
                seen[idx] = true;
                unique_count++;

                // Khi đã thu thập đủ n ký tự khác nhau -> hoàn thành 1 đoạn (block)
                if (unique_count == n) {
                    blocks++;
                    unique_count = 0;
                    // Reset lại trạng thái để đếm đoạn tiếp theo
                    fill(seen.begin(), seen.end(), false);
                }
            }
        }
    }

    // Độ dài ngắn nhất của chuỗi không là dãy con
    cout << blocks + 1 << "\n";

    return 0;
}
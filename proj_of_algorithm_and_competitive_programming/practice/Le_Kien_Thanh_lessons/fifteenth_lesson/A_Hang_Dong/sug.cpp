#include <bits/stdc++.h>
#include "cave.h"

using namespace std;

void exploreCave(int n) {
    int S[5005] = {0}; // Mảng lưu trạng thái đúng của các công tắc
    int D[5005] = {0}; // Mảng lưu cánh cửa mà công tắc điều khiển
    bool found[5005] = {false}; // Đánh dấu công tắc đã được xác định
    
    // Duyệt tìm công tắc cho từng cửa từ 0 đến N-1
    for (int i = 0; i < n; ++i) {
        int testS[5005];
        
        // BƯỚC 1: Xác định trạng thái (0 hay 1) để mở cửa i
        for (int j = 0; j < n; ++j) {
            if (found[j]) testS[j] = S[j]; // Giữ nguyên các cửa đã biết
            else testS[j] = 0;             // Gán thử tất cả chưa biết là 0
        }
        
        int res = tryCombination(testS);
        // Nếu res > i hoặc -1 thì cửa i đã mở -> trạng thái là 0, ngược lại là 1
        int correct_state = (res > i || res == -1) ? 0 : 1;
        
        // BƯỚC 2: Tìm kiếm nhị phân để tìm vị trí công tắc
        int low = 0, high = n - 1;
        int ans_switch = -1;
        
        while (low <= high) {
            if (low == high) {
                ans_switch = low;
                break;
            }
            
            int mid = low + (high - low) / 2;
            
            for (int j = 0; j < n; ++j) {
                if (found[j]) {
                    testS[j] = S[j];
                } else if (j >= low && j <= mid) {
                    testS[j] = correct_state; // Nửa trái thử gán bằng trạng thái đúng
                } else {
                    testS[j] = 1 - correct_state; // Nửa phải gán ngược lại
                }
            }
            
            res = tryCombination(testS);
            
            // Nếu cửa i mở ra, nghĩa là công tắc nằm trong đoạn [low, mid]
            if (res > i || res == -1) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        // Đánh dấu đã tìm thấy
        found[ans_switch] = true;
        S[ans_switch] = correct_state;
        D[ans_switch] = i;
    }
    
    // Trả kết quả cuối cùng
    answer(S, D);
}
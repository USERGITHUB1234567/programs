#include <bits/stdc++.h>
#include "coingamelib.h"
using namespace std;

namespace personA {
    string send(string w) {
        // Trả về chính xác xâu trạng thái vì n <= 10^5 không vượt quá giới hạn
        return w;
    }
}

namespace personB {
    void play(string s) {
        int n = s.size();
        vector<int> p;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                p.push_back(i);
            }
        }
        
        // Nếu không có đồng xu úp nào, không thể thực hiện nước đi
        if (p.empty()) return;

        if (p.size() % 2 != 0) {
            // Lẻ số 0: Lấy được TOÀN BỘ n đồng xu
            int l = 0, r = n - 1;
            for (int i = 0; i < (int)p.size(); i += 2) {
                if (i != (int)p.size() - 1) r = p[i + 1] - 1;
                else r = n - 1; // [ĐÃ FIX] Bao phủ đến hết mảng bên phải
                
                int cur = p[i];
                for (int j = cur; j >= l; --j) take(j);
                for (int j = cur + 1; j <= r; ++j) take(j);
                if (i + 1 < (int)p.size()) l = p[i + 1];
            }
        } else {
            // Chẵn số 0: Lấy được TỐI ĐA n - 1 đồng xu
            // Áp dụng thuật toán của mảng lẻ lên chuỗi [p[1] ... p_last]
            int l = p[0] + 2, r = n - 1;
            for (int i = 1; i < (int)p.size(); i += 2) {
                if (i != (int)p.size() - 1) r = p[i + 1] - 1;
                else r = n - 1;
                
                int cur = p[i];
                for (int j = cur; j >= l; --j) take(j);
                for (int j = cur + 1; j <= r; ++j) take(j);
                if (i + 1 < (int)p.size()) l = p[i + 1];
            }
            
            // Cuối cùng, xử lý nốt phần còn lại từ p[0] đổ về vị trí 0
            // Đồng xu duy nhất không bị lấy ra khỏi mảng sẽ nằm tại vị trí (p[0] + 1)
            int cur = p[0];
            for (int j = cur; j >= 0; --j) take(j);
        }
    }
}
#ifndef SECRET_H
#define SECRET_H

#include <algorithm>
#include <iostream>

// Hàm trợ giúp Secret giả lập trình chấm mẫu
inline int Secret(int X, int Y) {
    // Trình chấm mẫu của hệ thống: min(x + 2 * floor(y/2), 10^{9})
    return std::min(X + 2 * (Y / 2), 1000000000);
}

// Khai báo 2 hàm mà bạn sẽ triển khai trong file bài làm của mình
void Init(int N, int A[]);
int Query(int L, int R);

#endif // SECRET_H
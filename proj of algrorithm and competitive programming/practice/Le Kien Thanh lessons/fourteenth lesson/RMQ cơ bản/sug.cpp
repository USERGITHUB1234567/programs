#include "secret.h"

// Mảng 2 chiều lưu trữ các giá trị tiền tố/hậu tố theo từng tầng đệ quy
// Tầng tối đa với N=1000 là khoảng 10, khai báo 12 cho an toàn.
int val[12][1005];
int arr[1005];
int n;

// Hàm xây dựng cây chia để trị
void build(int level, int L, int R) {
    if (L == R) return;
    int mid = (L + R) / 2;
    
    // Tính hậu tố cho nửa trái (từ mid lùi về L)
    val[level][mid] = arr[mid];
    for (int i = mid - 1; i >= L; --i) {
        val[level][i] = Secret(arr[i], val[level][i + 1]);
    }
    
    // Tính tiền tố cho nửa phải (từ mid+1 tiến lên R)
    val[level][mid + 1] = arr[mid + 1];
    for (int i = mid + 2; i <= R; ++i) {
        val[level][i] = Secret(val[level][i - 1], arr[i]);
    }
    
    // Tiếp tục đệ quy xuống 2 nửa
    build(level + 1, L, mid);
    build(level + 1, mid + 1, R);
}

void Init(int N, int A[]) {
    n = N;
    // Lưu lại mảng ban đầu
    for (int i = 0; i < N; ++i) {
        arr[i] = A[i];
    }
    
    // Nếu có nhiều hơn 1 phần tử mới cần xây dựng
    if (N > 1) {
        build(0, 0, N - 1);
    }
}

// Hàm duyệt tìm điểm tách (mid)
int query_ans(int level, int node_L, int node_R, int qL, int qR) {
    if (node_L == node_R) return arr[qL];
    
    int mid = (node_L + node_R) / 2;
    
    // Nếu truy vấn [qL, qR] bị cắt ngang bởi điểm mid của node hiện tại
    if (qL <= mid && qR > mid) {
        return Secret(val[level][qL], val[level][qR]);
    }
    
    // Nếu toàn bộ truy vấn nằm hoàn toàn bên nửa trái
    if (qR <= mid) {
        return query_ans(level + 1, node_L, mid, qL, qR);
    }
    
    // Nếu toàn bộ truy vấn nằm hoàn toàn bên nửa phải
    return query_ans(level + 1, mid + 1, node_R, qL, qR);
}

int Query(int L, int R) {
    // Xử lý góc: Đoạn chỉ có 1 phần tử
    if (L == R) return arr[L];
    
    // Bắt đầu duyệt từ tầng 0, bao phủ toàn bộ mảng [0, n - 1]
    return query_ans(0, 0, n - 1, L, R);
}
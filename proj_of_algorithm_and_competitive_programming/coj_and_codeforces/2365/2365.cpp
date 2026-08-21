/*#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

const int sumN = 1e5 + 7;
int st[4 * sumN];
int n, m;
int a[sumN];

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }

    int mid = (l + r) >> 1;  // (l + r) / 2
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);

    st[id] = st[2 * id] + st[2 * id + 1];
}

void update(int id, int l, int r, int i, int val) {
    if (l > i || r < i) return;

    if (l == r) {
        st[id] = val;
        return;
    }
    int mid = (l + r) >> 1;  // (l + r) / 2
    update(2 * id, l, mid, i, val);
    update(2 * id + 1, mid + 1, r, i, val);

    st[id] = st[2 * id] + st[2 * id + 1];
}

int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;

    if (l >= u && r <= v) return st[id];

    int mid = (l + r) >> 1;  // (l + r) / 2
    int get1 = get(2 * id, l, mid, u, v);
    int get2 = get(2 * id + 1, mid + 1, r, u, v);

    return get1 + get2;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    build(1, 0, n - 1);
    while (m--) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) {
            update(1, 0, n - 1, x, y);
        } else {
            cout << get(1, 0, n - 1, x , y - 1) << "\n";
        }
    }
    //for(long long i=0; i<=4*sumN; i++) cout << st[i] << " ";
}*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
long long st[4 * MAXN]; // Segment Tree
int n, m;
int a[MAXN]; // Mảng lưu các phần tử ban đầu

// Hàm xây dựng cây đoạn
void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l]; // Gán giá trị tại nút lá
        return;
    }

    int mid = (l + r) / 2;
    build(2 * id, l, mid);        // Xây dựng cây cho nửa trái
    build(2 * id + 1, mid + 1, r); // Xây dựng cây cho nửa phải

    // Gán giá trị của nút hiện tại là tổng của 2 con
    st[id] = st[2 * id] + st[2 * id + 1];
}

// Hàm cập nhật giá trị tại chỉ số i thành val
void update(int id, int l, int r, int i, int val) {
    if (l == r) {
        st[id] = val; // Cập nhật giá trị tại nút lá
        return;
    }

    int mid = (l + r) / 2;
    if (i <= mid)
        update(2 * id, l, mid, i, val); // Cập nhật bên trái
    else
        update(2 * id + 1, mid + 1, r, i, val); // Cập nhật bên phải

    // Sau khi cập nhật, tính lại giá trị cho nút hiện tại
    st[id] = st[2 * id] + st[2 * id + 1];
}

// Hàm truy vấn tổng các phần tử trong đoạn [u, v]
long long query(int id, int l, int r, int u, int v) {
    if (u > r || v < l) return 0; // Nếu đoạn không giao nhau

    if (u <= l && r <= v) return st[id]; // Đoạn hiện tại nằm hoàn toàn trong [u, v]

    int mid = (l + r) / 2;
    long long leftSum = query(2 * id, l, mid, u, v); // Truy vấn bên trái
    long long rightSum = query(2 * id + 1, mid + 1, r, u, v); // Truy vấn bên phải

    return leftSum + rightSum; // Trả về tổng của 2 nửa
}

int main() {
    ios::sync_with_stdio(0); // Tăng tốc độ nhập/xuất
    cin.tie(0);

    cin >> n >> m; // Nhập số phần tử và số truy vấn

    // Nhập các phần tử của mảng ban đầu
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Xây dựng cây đoạn
    build(1, 0, n - 1);

    // Xử lý các truy vấn
    while (m--) {
        int type, x, y;
        cin >> type >> x >> y;

        if (type == 1) {
            // Cập nhật a[x] = y (x là chỉ số 0-based)
            update(1, 0, n - 1, x, y);
        } else {
            // Truy vấn tổng các phần tử từ a[x] đến a[y-1] (x, y là chỉ số 0-based)
            cout << query(1, 0, n - 1, x, y - 1) << "\n";
        }
    }

    return 0;
}

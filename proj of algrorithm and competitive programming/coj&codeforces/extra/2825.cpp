/*#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,l,r;
    cin >> n >> l >> r;
    pair<char,long long>p[n];
    for(long long i=0; i<n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    long long d=r-l+1,vt=l;
    pair<long long,long long>a[d];
    for(long long i=0; i<=d; i++;) {
        a[i].second=vt;
        vt++;
    }
    for(long long i=0; i<n; i++) {

    }
}*/

#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;
int water[MAXN * 4];  // Segment tree lưu mực nước
int lazy[MAXN * 4];   // Lazy propagation để tối ưu cập nhật

// Hàm đẩy lazy
void push(int node, int start, int end) {
    if (lazy[node] != 0) {
        water[node] += lazy[node];  // Cập nhật giá trị cho nút hiện tại
        if (start != end) {
            // Truyền giá trị lazy cho 2 con
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;  // Xóa lazy cho nút hiện tại
    }
}

// Hàm cập nhật giá trị trong đoạn [l, r]
void update(int node, int start, int end, int l, int r, int val) {
    push(node, start, end);  // Đẩy lazy trước khi cập nhật
    if (start > end || start > r || end < l) {
        return;  // Ngoài đoạn cập nhật
    }
    if (start >= l && end <= r) {
        // Nằm hoàn toàn trong đoạn [l, r]
        lazy[node] += val;
        push(node, start, end);
        return;
    }
    // Chia nhỏ đoạn và cập nhật 2 con
    int mid = (start + end) / 2;
    update(node * 2, start, mid, l, r, val);
    update(node * 2 + 1, mid + 1, end, l, r, val);
    // Cập nhật lại giá trị cho nút cha sau khi con đã được cập nhật
    water[node] = max(water[node * 2], water[node * 2 + 1]);
}

// Hàm truy vấn giá trị tại vị trí idx
int query(int node, int start, int end, int idx) {
    push(node, start, end);  // Đẩy lazy trước khi truy vấn
    if (start == end) {
        return water[node];
    }
    int mid = (start + end) / 2;
    if (idx <= mid) {
        return query(node * 2, start, mid, idx);
    } else {
        return query(node * 2 + 1, mid + 1, end, idx);
    }
}

// Hàm chính
int main() {
    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 0; i < n; i++) {
        char type;
        int x;
        cin >> type >> x;

        // Điều chỉnh chỉ số x về đúng đoạn đường (0-indexed)
        x -= a;

        if (type == '+') {
            // Mưa tại đoạn đường x
            update(1, 0, b - a, x, x, 1);

            // Kiểm tra tràn nước
            while (true) {
                bool overflow = false;
                for (int j = 0; j <= b - a; j++) {
                    if (query(1, 0, b - a, j) >= 2) {
                        // Nước tràn tại đoạn j
                        update(1, 0, b - a, j, j, -2);  // Giảm mực nước đoạn j
                        if (j - 1 >= 0) update(1, 0, b - a, j - 1, j - 1, 1);  // Tăng đoạn trước
                        if (j + 1 <= b - a) update(1, 0, b - a, j + 1, j + 1, 1);  // Tăng đoạn sau
                        overflow = true;
                    }
                }
                if (!overflow) break;
            }
        } else if (type == '?') {
            // Truy vấn mực nước tại đoạn đường x
            cout << query(1, 0, b - a, x) << endl;
        }
    }

    return 0;
}

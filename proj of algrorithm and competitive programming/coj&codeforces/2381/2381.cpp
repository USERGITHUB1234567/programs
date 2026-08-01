#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;
const int INF = 1e9;

int n, m;
vector<int> segTree(4 * MAXN, 0); // Cây Segment Tree
vector<int> lazy(4 * MAXN, -1);  // Mảng Lazy Propagation

void propagate(int node, int start, int end) {
    if (lazy[node] != -1) {
        segTree[node] = lazy[node]; // Gán giá trị trong đoạn [start, end]
        if (start != end) {
            lazy[node * 2] = lazy[node];
            lazy[node * 2 + 1] = lazy[node];
        }
        lazy[node] = -1; // Xóa trạng thái lazy của nút hiện tại
    }
}

void update(int node, int start, int end, int l, int r, int value) {
    propagate(node, start, end);
    if (start > r || end < l) return; // Ngoài đoạn cập nhật

    if (start >= l && end <= r) {
        segTree[node] = value;
        if (start != end) {
            lazy[node * 2] = value;
            lazy[node * 2 + 1] = value;
        }
        return;
    }

    int mid = (start + end) / 2;
    update(node * 2, start, mid, l, r, value);
    update(node * 2 + 1, mid + 1, end, l, r, value);
    segTree[node] = segTree[node * 2]; // Gộp giá trị từ con
}

int query(int node, int start, int end, int idx) {
    propagate(node, start, end);
    if (start == end) return segTree[node];

    int mid = (start + end) / 2;
    if (idx <= mid) {
        return query(node * 2, start, mid, idx);
    } else {
        return query(node * 2 + 1, mid + 1, end, idx);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            update(1, 0, n - 1, l, r - 1, v);
        } else if (type == 2) {
            int idx;
            cin >> idx;
            cout << query(1, 0, n - 1, idx) << endl;
        }
    }

    return 0;
}

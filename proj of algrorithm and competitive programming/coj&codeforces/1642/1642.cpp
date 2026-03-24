#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long sum, prefix, suffix, best;
};

// Hàm kết hợp (merge) hai nút của cây segment tree
Node combine(Node left, Node right) {
    Node parent;
    parent.sum = left.sum + right.sum;
    parent.prefix = max(left.prefix, left.sum + right.prefix);
    parent.suffix = max(right.suffix, right.sum + left.suffix);
    parent.best = max({left.best, right.best, left.suffix + right.prefix});
    return parent;
}

// Hàm khởi tạo một nút từ một giá trị
Node make_node(long long val) {
    Node node;
    node.sum = val;
    node.prefix = val;
    node.suffix = val;
    node.best = val;
    return node;
}

vector<long long> arr;
vector<Node> tree;

// Xây dựng cây segment tree cho đoạn [l, r] tại node có chỉ số idx
void build(int idx, int l, int r) {
    if(l == r) {
        tree[idx] = make_node(arr[l]);
    } else {
        int mid = (l + r) / 2;
        build(2 * idx + 1, l, mid);
        build(2 * idx + 2, mid + 1, r);
        tree[idx] = combine(tree[2 * idx + 1], tree[2 * idx + 2]);
    }
}

// Truy vấn cây segment tree cho đoạn [ql, qr] trên nút quản lý [l, r]
Node query(int idx, int l, int r, int ql, int qr) {
    if(ql == l && qr == r)
        return tree[idx];
    int mid = (l + r) / 2;
    if(qr <= mid)
        return query(2 * idx + 1, l, mid, ql, qr);
    else if(ql > mid)
        return query(2 * idx + 2, mid + 1, r, ql, qr);
    else {
        Node left = query(2 * idx + 1, l, mid, ql, mid);
        Node right = query(2 * idx + 2, mid + 1, r, mid + 1, qr);
        return combine(left, right);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    tree.resize(4 * n);
    build(0, 0, n - 1);

    int m;
    cin >> m;
    while(m--){
        int x, y;
        cin >> x >> y;
        // Chuyển sang 0-indexed
        x--; y--;
        Node ans = query(0, 0, n - 1, x, y);
        cout << ans.best << "\n";
    }

    return 0;
}

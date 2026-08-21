#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int size;
    vector<int> ft;
    Fenwick(int n = 0) { init(n); }
    void init(int n) { size = n; ft.assign(n+1, 0); }
    void reset() { fill(ft.begin(), ft.end(), 0); }
    void update(int i, int v) {
        if (i <= 0 || i > size) return;
        while (i <= size) {
            ft[i] += v;
            i += i & -i;
        }
    }
    int query(int i) {
        if (i > size) i = size;
        int res = 0;
        while (i > 0) {
            res += ft[i];
            i -= i & -i;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<int> p(n+1);
    for (int i = 1; i <= n; ++i) cin >> p[i];

    vector<pair<int,int>> qu(q+1);
    vector<int> L(q+1), R(q+1);
    for (int i = 1; i <= q; ++i) {
        cin >> qu[i].first >> qu[i].second;
        int len = qu[i].second - qu[i].first + 1;
        if (len < 1) len = 1;
        if (len > n) len = n;
        L[i] = 1;
        R[i] = len;
    }

    // trace theo giá trị đã bị giới hạn bởi n (vì k không thể > n)
    vector<vector<int>> trace(n+1);
    for (int i = 1; i <= n; ++i) {
        int val = p[i];
        if (val > n) val = n;
        if (val >= 1) trace[val].push_back(i);
    }

    Fenwick fen(n);

    // parallel binary search
    while (true) {
        bool done = true;
        vector<vector<int>> bucket(n+1);
        for (int i = 1; i <= q; ++i) {
            if (L[i] < R[i]) {
                done = false;
                int mid = (L[i] + R[i] + 1) >> 1; // upper mid
                bucket[mid].push_back(i);
            }
        }
        if (done) break;

        fen.reset();
        // duyệt threshold từ n xuống 1
        for (int val = n; val >= 1; --val) {
            if (!trace[val].empty()) {
                for (int pos : trace[val]) fen.update(pos, 1);
            }
            if (!bucket[val].empty()) {
                for (int qi : bucket[val]) {
                    int x = qu[qi].first;
                    int y = qu[qi].second;
                    int cnt = fen.query(y) - fen.query(x - 1);
                    //cout << cnt << '\n';
                    if (cnt >= val) L[qi] = val;
                    else R[qi] = val - 1;
                }
            }
        }
    }

    for (int i = 1; i <= q; ++i) {
        cout << L[i] << '\n';
    }
    return 0;
}

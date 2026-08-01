#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

// Fenwick Tree để hỗ trợ tính tổng tiền tố
struct FenwickTree {
    int n;
    vector<int> tree;
    FenwickTree(int n) : n(n), tree(n + 1, 0) {}
    void update(int i, int delta) {
        for (; i <= n; i += i & -i) tree[i] = (tree[i] + delta) % MOD;
    }
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum = (sum + tree[i]) % MOD;
        return sum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    // dp1[a] lưu số lượng b < a mà P_b < P_a
    vector<ll> dp1(n, 0);
    FenwickTree ft1(n);
    for (int i = 0; i < n; ++i) {
        dp1[i] = ft1.query(p[i]);
        ft1.update(p[i], 1);
    }

    // dp2[c] lưu số bộ (a, b) sao cho b < a < c và P_b < P_a < P_c
    vector<ll> dp2(n, 0);
    FenwickTree ft2(n);
    for (int i = 0; i < n; ++i) {
        dp2[i] = ft2.query(p[i]);
        ft2.update(p[i], dp1[i]);
    }

    // Đếm số lượng d > c mà P_d > P_c
    // Ta duyệt ngược từ phải sang trái
    ll ans = 0;
    FenwickTree ft3(n);
    for (int i = n - 1; i >= 0; --i) {
        ll count_d = (n - p[i]) - (ft3.query(n) - ft3.query(p[i]));
        ans = (ans + dp2[i] * count_d) % MOD;
        ft3.update(p[i], 1);
    }

    cout << ans << endl;

    return 0;
}
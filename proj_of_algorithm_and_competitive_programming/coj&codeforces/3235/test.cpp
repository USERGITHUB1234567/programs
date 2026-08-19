#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 100005;
const int MAXB = 320;

int n, k;
ll c[MAXN + 5];
ll sum[MAXB + 5][MAXB + 5];    // sum[d][r]
ll dif[MAXB + 5][MAXN + 5];    // dif[d][pos] : số sequence cần remove khỏi sum[d][...] tại pos

struct container {
    int a, l, d;
    bool operator<(const container &o) const { return a < o.a; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> k)) return 0;
    vector<container> ops(k);
    for (int i = 0; i < k; ++i) cin >> ops[i].a >> ops[i].l >> ops[i].d;
    sort(ops.begin(), ops.end());

    int b = max(1, (int)sqrt(n));
    int cur = 0;

    for (int i = 1; i <= n; ++i) {
        // apply removals scheduled at i for each small d, then add contribution from active classes
        for (int dd = 1; dd <= b; ++dd) {
            if (dif[dd][i] != 0) {
                // remove scheduled sequences from the active class
                sum[dd][i % dd] -= dif[dd][i];
                // optional: dif[dd][i] = 0; // not necessary since we won't revisit i
            }
            c[i] += sum[dd][i % dd];
        }

        // process operations that start at position i
        while (cur < k && ops[cur].a == i) {
            int a = ops[cur].a;
            int l = ops[cur].l;
            int d = ops[cur].d;

            if (d <= b) {
                // activate class
                ++sum[d][a % d];
                // schedule removal after last element: position a + l*d
                int rem_pos = a + l * d;
                if (rem_pos <= n) ++dif[d][rem_pos];
                // current position gets contribution from this new sequence
                ++c[i];
            } else {
                // large d: apply directly
                for (int j = 0; j < l; ++j) {
                    int pos = a + j * d;
                    if (pos > n) break;
                    ++c[pos];
                }
            }
            ++cur;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (i > 1) cout << ' ';
        cout << c[i];
    }
    cout << '\n';
    return 0;
}

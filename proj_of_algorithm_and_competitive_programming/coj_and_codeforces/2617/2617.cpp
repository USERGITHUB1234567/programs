#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, m, b[N];
long long tree[N];

void upd(int x, int v) {
    if (x <= 0) return;
    while (x <= n) {
        tree[x] += v;
        x += x & -x;
    }
}

long long sum(int x) {
    long long res = 0;
    while (x > 0) {
        res += tree[x];
        x -= x & -x;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        upd(i, b[i]);
    }

    cin >> m;
    for (int i = 1; i <= m; ++i) {
        int t;
        cin >> t;
        cout << min(sum(t - 1), sum(n) - sum(t));
        if (i < m) cout << " ";
        upd(t, 1);
    }

    return 0;
}

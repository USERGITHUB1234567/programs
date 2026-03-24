#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int l[100001], n, ans[100001], sum[524288];

void upd(int id, int l, int r, int i, int v) {
    if (l == r) {
        sum[id] += v;
        return;
    }
    int p1 = 2 * id, p2 = 2 * id + 1, c = (l + r) >> 1;
    if (i <= c) upd(p1, l, c, i, v);
    else upd(p2, c + 1, r, i, v);
    sum[id] = sum[p1] + sum[p2];
}
int query(int id, int l, int r, int u, int v) {
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return sum[id];
    int p1 = 2 * id, p2 = 2 * id + 1, c = (l + r) >> 1;
    return query(p1, l, c, u, v) + query(p2, c + 1, r, u, v);
}

int main() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        int a;
        cin >> a;
        if (l[a] == 0) {
            l[a] = i;
        } else {
            ans[a] = query(1, 1, 2 * n, l[a], i - 1);
            upd(1, 1, 2 * n, l[a], 1);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i];
        if(i < n) cout << " ";
    }
    return 0;
}

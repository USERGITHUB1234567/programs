#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int fenwick[MAXN], result[MAXN], p[MAXN], n;
void update(int idx, int val) {
    while (idx <= n) {
        fenwick[idx] += val;
        idx += idx & -idx;
    }
}
int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += fenwick[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        result[i] = query(n) - query(p[i]);
        update(p[i], 1);
    }
    for (int i = 1; i <= n; i++) {
        cout << result[i];
        if (i < n) cout << " ";
    }

    return 0;
}

#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int MOD = 1e9 + 7;
const long long inf = 1e18;
const long double EPS = 1e-15;
const int N = 2e5 + 5;
int n, BIT[N], res, a[N], p[N], nxt[N], prv[N];
void update(int i, int val) {
    while (i <= n) {
        BIT[i] += val;
        i += i & -i;
    }
}
int query(int i) {
    int s = 0;
    while (i) {
        s += BIT[i];
        i -= i & -i;
    }
    return s;
}
int range(int l, int r) {
    if (l > r) return 0;
    return query(r) - query(l - 1);
}
bool cmp(int &x, int &y) {
    return nxt[x] < nxt[y];
}
map<int, int> mp1, mp2;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, 1);
    }
    for (int i = 1; i <= n; i++) {
        if (mp1[a[i]] != 0) prv[i] = mp1[a[i]];
        mp1[a[i]] = i;
    }
    for (int i = n; i >= 1; i--) {
        if (mp2[a[i]] != 0)
            nxt[i] = mp2[a[i]];
        else
            nxt[i] = n + 1;
        mp2[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) p[i] = i;
    sort(p + 1, p + 1 + n, cmp);
    for (int r = 1, j = 1; r <= n; ++r) {
        while (j <= n && nxt[p[j]] <= r) {
            int t = p[j];
            update(t, -1);
            ++j;
        }
        res += range(prv[r] + 1, r - 1);
    }
    cout << res;
    return 0;
}

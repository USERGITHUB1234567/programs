#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;

const int maxn = 100005;
const int INF = 2000000000;

int n, m;
int sum[262144], sums[262144], suml[262144], sumr[262144], laz[262144];
void down(int id, int l, int r) {
    int p1 = 2 * id + 1, p2 = 2 * id + 2;
    int mid = (l + r) >> 1;
    laz[p1] = laz[id];
    sum[p1] = (mid - l + 1) * laz[p1];
    sums[p1] = suml[p1] = sumr[p1] = max(0LL, sum[p1]);
    laz[p2] = laz[id];
    sum[p2] = (r - mid) * laz[p2];
    sums[p2] = suml[p2] = sumr[p2] = max(0LL, sum[p2]);
    laz[id] = INF;
}
void up(int id) {
    int p1 = 2 * id + 1, p2 = 2 * id + 2;
    sum[id] = sum[p1] + sum[p2];
    suml[id] = max(suml[p1], sum[p1] + suml[p2]);
    sumr[id] = max(sumr[p2], sumr[p1] + sum[p2]);
    sums[id] = max({sums[p1], sums[p2], sumr[p1] + suml[p2]});
}
void upd(int id, int l, int r, int i, int j, int v) {
    if (l > j || r < i) return;
    if (l >= i && r <= j) {
        laz[id] = v;
        sum[id] = (r - l + 1) * v;
        sums[id] = suml[id] = sumr[id] = max(0LL, sum[id]);
        return;
    }
    int mid = (l + r) >> 1;
    if (laz[id] != INF) {
        down(id, l, r);
    }
    if (i <= mid)
        upd(2 * id + 1, l, mid, i, min(j, mid), v);
    if (j >= mid + 1)
        upd(2 * id + 2, mid + 1, r, max(mid + 1, i), j, v);
    up(id);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill(laz, laz + 262144, INF);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int l, r, v;
        cin >> l >> r >> v;
        upd(0, 0, n - 1, l, r - 1, v);
        cout << sums[0] << "\n";
    }
    return 0;
}
/*
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;

const int maxn = 100005;
const int INF = 2000000000;

int n, m;
int sum[262144], sums[262144], suml[262144], sumr[262144], laz[262144];
void down(int id, int l, int r) {
    int p1 = 2 * id + 1, p2 = 2 * id + 2;
    int mid = (l + r) >> 1;
    laz[p1] = laz[id];
    sum[p1] = (mid - l + 1) * laz[p1];
    sums[p1] = suml[p1] = sumr[p1] = max(0LL, sum[p1]);
    laz[p2] = laz[id];
    sum[p2] = (r - mid) * laz[p2];
    sums[p2] = suml[p2] = sumr[p2] = max(0LL, sum[p2]);
    laz[id] = INF;
}
void up(int id) {
    int p1 = 2 * id + 1, p2 = 2 * id + 2;
    sum[id] = sum[p1] + sum[p2];
    suml[id] = max(suml[p1], sum[p1] + suml[p2]);
    sumr[id] = max(sumr[p2], sumr[p1] + sum[p2]);
    sums[id] = max({sums[p1], sums[p2], sumr[p1] + suml[p2]});
}
void upd(int id, int l, int r, int i, int j, int v) {
    if (l > j || r < i) return;
    if (l >= i && r <= j) {
        laz[id] = v;
        sum[id] = (r - l + 1) * v;
        sums[id] = suml[id] = sumr[id] = max(0LL, sum[id]);
        return;
    }
    int mid = (l + r) >> 1;
    if (laz[id] != INF) {
        down(id, l, r);
    }
    if (i <= mid)
        upd(2 * id + 1, l, mid, i, min(j, mid), v);
    if (j >= mid + 1)
        upd(2 * id + 2, mid + 1, r, max(mid + 1, i), j, v);
    up(id);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill(laz, laz + 262144, INF);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int l, r, v;
        cin >> l >> r >> v;
        upd(0, 0, n - 1, l, r - 1, v);
        cout << sums[0] << "\n";
    }
    return 0;
}
*/

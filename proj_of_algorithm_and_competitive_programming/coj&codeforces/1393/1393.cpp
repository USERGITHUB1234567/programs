#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int DI[4] = {-1, 0, 0, 1};
const int DJ[4] = {0, -1, 1, 0};
int n, h[101][101], ans = 1e9;
bool used[101][101];
void dfs1(int i, int j, int hmin, int hmax) {
    if (i == n && j == n) {
        ans = min(ans, hmax - hmin);
        return;
    }
    for (int k = 0; k < 4; k++) {
        int r = i + DI[k], c = j + DJ[k];
        if (r < 1 || r > n || c < 1 || c > n || used[r][c])
            continue;
        used[r][c] = true;
        dfs1(r, c, min(hmin, h[r][c]), max(hmax, h[r][c]));
        used[r][c] = false;
    }
}

void sub1() {
    memset(used, false, sizeof(used));
    used[1][1] = true;
    dfs1(1, 1, h[1][1], h[1][1]);
    cout << ans;
}

bool dfs2(int i, int j, int hmin, int hmax) {
    if (i < 1 || i > n || j < 1 || j > n || used[i][j] || h[i][j] < hmin || h[i][j] > hmax)
        return false;
    used[i][j] = true;
    return (i == n && j == n) ||
           dfs2(i - 1, j, hmin, hmax) ||
           dfs2(i, j - 1, hmin, hmax) ||
           dfs2(i, j + 1, hmin, hmax) ||
           dfs2(i + 1, j, hmin, hmax);
}
void sub2() {
    for (int hmin = 0; hmin <= 200; hmin++) {
        for (int hmax = hmin; hmax <= 200; hmax++) {
            memset(used, false, sizeof(used));
            if (dfs2(1, 1, hmin, hmax))
                ans = min(ans, hmax - hmin);
        }
    }
    cout << ans;
}
void sub3() {
    for (int hmin = 0; hmin <= 200; hmin++) {
        int l = hmin, r = 201;
        while (l < r) {
            int hmax = (l + r) / 2;
            memset(used, false, sizeof(used));
            if (dfs2(1, 1, hmin, hmax))
                r = hmax;
            else
                l = hmax + 1;
        }
        if (l < 201)
            ans = min(ans, l - hmin);
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> h[i][j];

    sub3();
    return 0;
}

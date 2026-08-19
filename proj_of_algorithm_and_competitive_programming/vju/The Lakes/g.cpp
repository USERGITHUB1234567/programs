#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
bool vis[1001][1001];
int a[1001][1001];

int bfs(int i, int j) {
    int kq = 0;
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true;
    kq += a[i][j];
    while (!q.empty()) {
        pair<int, int> u = q.front();
        int x = u.first, y = u.second;
        q.pop();

        if (x + 1 <= 1000 && a[x + 1][y] != 0 && !vis[x + 1][y]) {
            q.push({x + 1, y});
            vis[x + 1][y] = true;
            kq += a[x + 1][y];
        }
        if (x - 1 >= 1 && a[x - 1][y] != 0 && !vis[x - 1][y]) {
            q.push({x - 1, y});
            vis[x - 1][y] = true;
            kq += a[x - 1][y];
        }
        if (y + 1 <= 1000 && a[x][y + 1] != 0 && !vis[x][y + 1]) {
            q.push({x, y + 1});
            vis[x][y + 1] = true;
            kq += a[x][y + 1];
        }
        if (y - 1 >= 1 && a[x][y - 1] != 0 && !vis[x][y - 1]) {
            q.push({x, y - 1});
            vis[x][y - 1] = true;
            kq += a[x][y - 1];
        }
    }
    return kq;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        memset(vis, false, sizeof(vis));
        memset(a, 0, sizeof(a));
        int n, m, kq = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) cin >> a[i][j];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (!vis[i][j] && a[i][j] != 0) kq = max(kq, bfs(i, j));
            }
        }
        cout << kq << "\n";
    }
    return 0;
}

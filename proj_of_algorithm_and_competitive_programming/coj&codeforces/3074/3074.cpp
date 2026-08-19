#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int n, m;
char c[1003][1003];
bool vis[1003][1003];
int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true;
    while (!q.empty()) {
        auto [u, v] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int x = u + di[k];
            int y = v + dj[k];
            if (x >= 1 && x <= m && y >= 1 && y <= n && c[x][y] == '.' && !vis[x][y]) {
                vis[x][y] = true;
                q.push({x, y});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(vis, false, sizeof(vis));
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    int kq = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (!vis[i][j] && c[i][j] == '.') {
                bfs(i, j);
                kq++;
            }
        }
    }
    cout << kq;
}

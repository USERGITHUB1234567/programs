#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
bool vis[1005][1005];
char r[1005][1005];
void bfs(int i, int j) {
    queue<pair<int, int>> q;
    vis[i][j] = true;
    q.push({i, j});
    while (!q.empty()) {
        pair<int, int> u = q.front();
        int x = u.first, y = u.second;
        q.pop();
        if (x + 1 < 1005 && r[x + 1][y] == '.' && !vis[x + 1][y]) {
            q.push({x + 1, y});
            vis[x + 1][y] = true;
        }
        if (x - 1 >= 0 && r[x - 1][y] == '.' && !vis[x - 1][y]) {
            q.push({x - 1, y});
            vis[x - 1][y] = true;
        }
        if (y + 1 < 1005 && r[x][y + 1] == '.' && !vis[x][y + 1]) {
            q.push({x, y + 1});
            vis[x][y + 1] = true;
        }
        if (y - 1 >= 0 && r[x][y - 1] == '.' && !vis[x][y - 1]) {
            q.push({x, y - 1});
            vis[x][y - 1] = true;
        }
    }
}
int main() {
    memset(vis, false, sizeof(vis));
    memset(r, '#', sizeof(r));
    int n, m, d = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> r[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (r[i][j] == '.' && !vis[i][j]) {
                bfs(i, j);
                d++;
            }
        }
    }
    cout << d;
    return 0;
}

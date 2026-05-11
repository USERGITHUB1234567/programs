#include <bits/stdc++.h>
using namespace std;

char a[3][701];
bool vis[3][701];
int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

void bfs(int i1, int j1, int n) {
    queue<pair<int, int>> q;
    q.push({i1, j1});
    vis[i1][j1] = true;
    while (!q.empty()) {
        int u = q.front().first, v = q.front().second;
        q.pop();
        for (int d = 0; d < 8; d++) {
            int x = u + di[d], y = v + dj[d];
            if (x >= 1 && x <= 2 && y >= 1 && y <= n && !vis[x][y] && a[x][y] == '0') {
                vis[x][y] = true;
                q.push({x, y});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= 2; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }
        memset(vis, false, sizeof(vis));
        bfs(1, 1, n);
        cout << (vis[2][n] ? "YES" : "NO") << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int n, m;
char c[1003][1003];
bool vis[1003][1003];
int s, t, f, h;
char tr[1003][1003];
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
            if (x >= 1 && x <= m && y >= 1 && y <= n && c[x][y] != '#' && !vis[x][y]) {
                vis[x][y] = true;
                q.push({x, y});
                if (k == 0) tr[x][y] = 'D';
                if (k == 1) tr[x][y] = 'R';
                if (k == 2) tr[x][y] = 'U';
                if (k == 3) tr[x][y] = 'L';
            }
        }
    }
}

vector<char> kq;
void trace(int i, int j) {
    if (i == s && j == t) return;
    kq.push_back(tr[i][j]);
    if (tr[i][j] == 'D') trace(i - 1, j);
    else if (tr[i][j] == 'R') trace(i, j - 1);
    else if (tr[i][j] == 'U') trace(i + 1, j);
    else trace(i, j + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
            if (c[i][j] == 'A') {
                s = i;
                t = j;
            } else if (c[i][j] == 'B') {
                f = i;
                h = j;
            }
        }
    }
    bfs(s, t);

    if (!vis[f][h]) {
        cout << "NO\n";
        return 0;
    }
    trace(f, h);
    reverse(kq.begin(), kq.end());
    cout << "YES\n";
    cout << kq.size() << "\n";
    for (char step : kq) {
        cout << step;
    }
    cout << "\n";
    return 0;
}

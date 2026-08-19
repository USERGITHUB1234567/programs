#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int n, m;
pair<pair<int, int>, char> pre[1005][1005];
char c[1005][1005];
bool vis[1005][1005];

void bf(int sr, int sc) {
    queue<pair<int, int>> q;
    vis[sr][sc] = true;
    q.push({sr, sc});

    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();
        int x = u.first, y = u.second;

        if (x + 1 < n && c[x + 1][y] != '#' && !vis[x + 1][y]) {
            vis[x + 1][y] = true;
            q.push({x + 1, y});
            pre[x + 1][y] = {{x, y}, 'D'};
        }
        if (x - 1 >= 0 && c[x - 1][y] != '#' && !vis[x - 1][y]) {
            vis[x - 1][y] = true;
            q.push({x - 1, y});
            pre[x - 1][y] = {{x, y}, 'U'};
        }
        if (y + 1 < m && c[x][y + 1] != '#' && !vis[x][y + 1]) {
            vis[x][y + 1] = true;
            q.push({x, y + 1});
            pre[x][y + 1] = {{x, y}, 'R'};
        }
        if (y - 1 >= 0 && c[x][y - 1] != '#' && !vis[x][y - 1]) {
            vis[x][y - 1] = true;
            q.push({x, y - 1});
            pre[x][y - 1] = {{x, y}, 'L'};
        }
    }
}

vector<char> fp(int sr, int sc, int er, int ec) {
    vector<char> path;
    int i = er, j = ec;

    while (!(i == sr && j == sc)) {
        char direction = pre[i][j].second;
        path.push_back(direction);
        int prevI = pre[i][j].first.first;
        int prevJ = pre[i][j].first.second;
        i = prevI;
        j = prevJ;
    }

    reverse(path.begin(), path.end());
    return path;
}

int main() {
    cin >> n >> m;

    memset(vis, false, sizeof(vis));
    int sr, sc, er, ec;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
            if (c[i][j] == 'A') {
                sr = i;
                sc = j;
            }
            if (c[i][j] == 'B') {
                er = i;
                ec = j;
            }
        }
    }

    bf(sr, sc);

    if (!vis[er][ec]) {
        cout << "NO" << "\n";
    } else {
        vector<char> path = fp(sr, sc, er, ec);
        cout << "YES" << "\n";
        cout << path.size() << "\n";
        for (char direction : path) {
            cout << direction;
        }
        cout << "\n";
    }

    return 0;
}

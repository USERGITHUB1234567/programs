#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int n, m;
char grid[1001][1001];
int monster_dist[1001][1001], human_dist[1001][1001];
int par_x[1001][1001], par_y[1001][1001]; // Lưu tọa độ cha của mỗi ô
char par_move[1001][1001];             // Lưu ký tự di chuyển từ cha đến ô đó

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const string directions = "DRUL";

void bfs_monster(queue<pair<int, int>> &mq) {
    while (!mq.empty()) {
        auto [x, y] = mq.front();
        mq.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (grid[nx][ny] != '.' || monster_dist[nx][ny] != -1) continue;
            monster_dist[nx][ny] = monster_dist[x][y] + 1;
            mq.push({nx, ny});
        }
    }
}

pair<bool, string> bfs_human(pair<int, int> start) {
    queue<pair<int, int>> hq;
    hq.push(start);
    human_dist[start.first][start.second] = 0;
    // Khởi tạo tọa độ cha của ô bắt đầu
    par_x[start.first][start.second] = -1;
    par_y[start.first][start.second] = -1;

    while (!hq.empty()) {
        auto [x, y] = hq.front();
        hq.pop();
        // Nếu đạt đến đường biên
        if (x == 1 || x == n || y == 1 || y == m) {
            string path;
            int cx = x, cy = y;
            while (!(cx == start.first && cy == start.second)) {
                char d = par_move[cx][cy];
                path.push_back(d);
                int px = par_x[cx][cy], py = par_y[cx][cy];
                cx = px; cy = py;
            }
            reverse(path.begin(), path.end());
            return {true, path};
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (grid[nx][ny] != '.' || human_dist[nx][ny] != -1) continue;
            // Kiểm tra nếu con quái đã đến ô (nx,ny) và sắp đến trước hoặc cùng lúc
            if (monster_dist[nx][ny] != -1 && human_dist[x][y] + 1 >= monster_dist[nx][ny]) continue;
            human_dist[nx][ny] = human_dist[x][y] + 1;
            par_x[nx][ny] = x;
            par_y[nx][ny] = y;
            par_move[nx][ny] = directions[i];
            hq.push({nx, ny});
        }
    }
    return {false, ""};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    pair<int, int> start;
    queue<pair<int, int>> mq;

    memset(monster_dist, -1, sizeof(monster_dist));
    memset(human_dist, -1, sizeof(human_dist));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                start = {i, j};
                grid[i][j] = '.';
            } else if (grid[i][j] == 'M') {
                mq.push({i, j});
                monster_dist[i][j] = 0;
            }
        }
    }

    bfs_monster(mq);
    auto [can_escape, path] = bfs_human(start);

    if (can_escape) {
        cout << "YES\n" << path.size() << "\n" << path << "\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}

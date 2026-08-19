#include <bits/stdc++.h>
using namespace std;

int a[702][702];
bool vis[702][702];
int n, m, kq = 0;
int di[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dj[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void bfs(int x, int y) {
    bool hilltop = true;
    int height = a[x][y];
    queue<pair<int,int>> q;
    q.push({x, y});
    vis[x][y] = true;

    while (!q.empty()) {
        auto [u, v] = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int l = u + di[i], r = v + dj[i];
            if (l >= 1 && l <= n && r >= 1 && r <= m) {
                if (a[l][r] > height) {
                    hilltop = false;
                }
                else if (a[l][r] == height && !vis[l][r]) {
                    vis[l][r] = true;
                    q.push({l, r});
                }
            }
        }
    }
    if (hilltop) kq++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (!vis[i][j])
                bfs(i, j);
        }
    }
    cout << kq;
    return 0;
}

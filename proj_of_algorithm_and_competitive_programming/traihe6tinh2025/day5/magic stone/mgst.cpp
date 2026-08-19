#include <bits/stdc++.h>
using namespace std;
static const int INF = 1e9;
int R, C, T;
vector<string> G;
pair<int,int> S, F;
vector<pair<int,int>> st;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

vector<vector<int>> mfBFS(const vector<pair<int,int>>& src) {
    vector<vector<int>> d(R, vector<int>(C, INF));
    queue<pair<int,int>> q;
    for (auto &p : src) {
        d[p.first][p.second] = 0;
        q.push(p);
    }
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        int dd = d[x][y];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (G[nx][ny] == '#') continue;
            if (d[nx][ny] > dd + 1) {
                d[nx][ny] = dd + 1;
                q.push({nx, ny});
            }
        }
    }
    return d;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C >> T;
    G.resize(R);
    for (int i = 0; i < R; i++) {
        cin >> G[i];
        for (int j = 0; j < C; j++) {
            if (G[i][j] == 'S') S = {i, j};
            else if (G[i][j] == 'F') F = {i, j};
        }
    }
    st.resize(T);
    for (int i = 0; i < T; i++) {
        int x, y;
        cin >> x >> y;
        st[i] = {x-1, y-1};
    }

    vector<pair<int,int>> front = {S};
    vector<int> cst = {0};

    for (int ti = 0; ti < T; ti++) {
        vector<pair<int,int>> touch;
        auto [sx, sy] = st[ti];
        for (int i = 0; i < 4; i++) {
            int nx = sx + dx[i], ny = sy + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (G[nx][ny] == '#') continue;
            touch.push_back({nx, ny});
        }
        if (touch.empty()) { cout << -1; return 0; }

        unordered_map<int,int> best;
        for (int i = 0; i < front.size(); i++) {
            auto src = front[i];
            int base = cst[i];
            auto d = mfBFS({src});
            for (auto &p : touch) {
                int idx = p.first * C + p.second;
                if (d[p.first][p.second] < INF) {
                    int cand = base + d[p.first][p.second];
                    if (!best.count(idx) || cand < best[idx]) best[idx] = cand;
                }
            }
        }

        vector<pair<int,int>> nf;
        vector<int> nc;
        for (auto &p : touch) {
            int idx = p.first * C + p.second;
            if (best.count(idx)) {
                nf.push_back(p);
                nc.push_back(best[idx]);
            }
        }
        if (nf.empty()) { cout << -1; return 0; }
        front = move(nf);
        cst = move(nc);
    }

    int ans = INF;
    for (int i = 0; i < front.size(); i++) {
        auto d = mfBFS({front[i]});
        int dd = d[F.first][F.second];
        if (dd < INF) ans = min(ans, cst[i] + dd);
    }

    cout << (ans < INF ? ans : -1);
    return 0;
}

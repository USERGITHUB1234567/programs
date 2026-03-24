#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C, K;
    cin >> R >> C >> K;
    vector<string> grid(R);
    pair<int,int> S, G;
    for(int i = 0; i < R; i++){
        cin >> grid[i];
        for(int j = 0; j < C; j++){
            if(grid[i][j] == 'S') S = {i,j};
            if(grid[i][j] == 'G') G = {i,j};
        }
    }
    vector<vector<int>> dist(R, vector<int>(C, INF));
    deque<pair<int,int>> dq;
    dist[S.first][S.second] = 0;
    dq.emplace_back(S.first, S.second);
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};

    while(!dq.empty()){
        auto [r,c] = dq.front(); dq.pop_front();
        int d = dist[r][c];
        for(int dir = 0; dir < 4; ++dir){
            for(int step = 1; step <= K; ++step){
                int nr = r + dr[dir]*step;
                int nc = c + dc[dir]*step;
                if(nr < 0 || nr >= R || nc < 0 || nc >= C) break;
                if(grid[nr][nc] == '#') break;
                if(dist[nr][nc] < d+1) break;
                if(dist[nr][nc] == d+1) continue;
                dist[nr][nc] = d+1;
                dq.emplace_back(nr,nc);
            }
        }
    }
    int ans = dist[G.first][G.second];
    cout << ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

char ch[101][101];
int vis[101][101];
int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};
int r, c, x1, y12, x2, y2;

void bfs() {
    queue<pair<int,int>> q;
    q.push({x1, y12});
    vis[x1][y12] = 0;
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int xc = x + di[i], yc = y + dj[i];
            if(xc < 1 || xc > r || yc < 1 || yc > c) continue;
            if(vis[xc][yc] == -1 && ch[xc][yc] != '*'){
                vis[xc][yc] = vis[x][y] + 1;
                q.push({xc, yc});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(vis, -1, sizeof(vis));
    cin >> r >> c;
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            cin >> ch[i][j];
            if(ch[i][j] == 'B'){
                x2 = i;
                y2 = j;
            }
            if(ch[i][j] == 'C'){
                x1 = i;
                y12 = j;
            }
        }
    }
    bfs();
    cout << vis[x2][y2];
    return 0;
}

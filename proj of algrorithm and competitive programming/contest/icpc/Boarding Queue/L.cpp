#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define ford(a,b,c) for(int a=b;a<=c;a++)
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, c, n, p;
    cin >> r >> c >> n >> p;
    vector<vector<int>> grid(r+1, vector<int>(c+1,0));
    vector<pair<int,int>> pos(n+1, {0,0});
    ford(i,1,r){
        ford(j,1,c){
            int x;
            cin >> x;
            grid[i][j] = x;
            if(x) pos[x] = {i,j};
        }
    }
    int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
    vector<bool> k(n+1, false);
    ford(i,1,p){
        int s = p - i, x = pos[i].first, y = pos[i].second;
        for(int d = 0; d < 4; d++){
            int nx = x + di[d], ny = y + dj[d];
            if(nx < 1 || nx > r || ny < 1 || ny > c) continue;
            int j = grid[nx][ny];
            if(!j) continue;
            int ok = j + s;
            if(ok >= 1 && ok <= n) k[ok] = true;
        }
    }
    k[p] = false;
    int count = 0;
    ford(q,1,n){
        if(q==p) continue;
        if(k[q]) count++;
    }
    cout << count << "/" << (n - 1) << "\n";
    return 0;
}

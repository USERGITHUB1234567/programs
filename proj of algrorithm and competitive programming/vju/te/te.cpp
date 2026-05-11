#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int di[4]={1,0,-1,0},dj[4]={0,1,0,-1};
char c[1001][1001];
int vis[1001][1001];
int n,m,k,x1,y1,x2,y2;
void bfs(int x1, int y1, int x1, int y2)
{
    queue<pair<int,int>>q;
    q.push({x1,y1});
    vis[x1][y1]=0;
    while(!q.empty()) {
        int x=q.front().first,y=q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int xt=x+di[i],yt=y+dj[i];
            if(vis[xt][yt]!=-1) {
                vis[xt][yt]=vis[x][y]+1;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    memset(vis,-1,sizeof(vis));
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) cin >> c[i][j];
    }
    cin >> x1 >> y1 >> x2 >> y2;
    bfs(x1,y1,x2,y2);
    cout << vis[x2][y2];
}

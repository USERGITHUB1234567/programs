#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int a[3][701],di[4]={1,0,-1,0},dj[4]={0,1,0,-1};
int t;
bool vis[3][701];
void bfs(int i1, int j1, int i2, int j2)
{
    queue<pair<int,int>>q;
    q.push({i1,j1});
    vis[i1][j1]=true;
    while(!q.empty()) {
        int u=q.front().first, v=q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int x=u+di[i],y=dj[i];
            if(a[x][y]!=1) q.push({x,y});
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
}

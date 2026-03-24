#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
const int maxn=1003;
string s[maxn];
int sccnum[maxn][maxn],r,c,cur=1,di[4]={1,0,-1,0},dj[4]={0,1,0,-1},d[maxn*maxn];
vector<int>adj[maxn];
struct qu {
    char c;
    int x,y;
};
void bfs(int x, int y) {
    queue<qu>q;
    //x--;
    //y--;
    q.push({s[x][y],x,y});
    while(!q.empty()) {
        auto[c,x,y]=q.front();
        q.pop();
        sccnum[x][y]=cur;
        for(int i=0; i<4; i++) {
            int u=x+di[i],v=y+dj[i];
            if(u<0 || v<0 || u>=r || v>=c) continue;
            if(s[u][v]!=c) {
                if(sccnum[u][v]!=0) {
                    int a=sccnum[u][v],b=sccnum[x][y];
                    adj[a].push_back(b);
                    adj[b].push_back(a);
                }

            }
            else {
                if(!sccnum[u][v]) q.push({c,u,v});
            }
        }
    }
    ++cur;
}
void dfs(int u, int p) {
    d[u]=(u==p?1:d[p]+1);
    for(int v:adj[u]) {
        if(v==p) continue;
        dfs(v,u);
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> r >> c;
    for(int i=0; i<r; i++) cin >> s[i];
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(s[i][j]!='*' && !sccnum[i][j]) {
                bfs(i,j);
                //cout << cur << " " << i << "  " << j << "\n"; 
            }
        }
    }
    dfs(1,1);
    int kq=0;
    for(int i=1; i<=cur; i++) kq=max(kq,d[i]);
    cout << kq;
    /*for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cout << sccnum[i][j] << " ";
        }
        cout << "\n";
    }*/
}
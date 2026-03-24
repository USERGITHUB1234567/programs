#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=252,maxm=60004,inf=1e9;
vector<int>adj[maxn];
int n,m,a,b,kq;
int dist[maxn];
bool vis[maxn][maxn];
struct no
{
    int u,v,c;
};
void bfs(int s, int t, int f)
{
    for(int i=0; i<maxn; i++) dist[i]=inf;
    queue<no>q;
    q.push({s,t,f});
    while(!q.empty()) {
        auto[u,v,c]=q.front();
        q.pop();
        if(u==v) {
            kq=c;
            return;
        }
        for(int i:adj[u]) {
            for(int j:adj[v]) {
                if(!vis[i][j]) {
                    vis[i][j]=true;
                    q.push({i,j,c+1});
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m >> a >> b;
    for(int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    bfs(a,b,0);
    cout << kq;
}

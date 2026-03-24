#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
vector<int>adj[100005];
int pre[100005];
bool vis[100005];
void bfs(int u)
{
    memset(vis,0,sizeof(vis));
    queue<int>q;
    vis[u]=true;
    q.push(u);
    while(!q.empty()) {
        int v=q.front();
        q.pop();
        for(int i:adj[v]) {
            if(!vis[i]) {
                q.push(i);
                vis[i]=true;
                pre[i]=v;
            }
        }
    }
}
vector<int>kq;
void trace(int u,int q)
{
    kq.push_back(u);
    if(u!=q) trace(pre[u],q);
}
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    if(!vis[n]) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    trace(n,1);
    cout << kq.size() << "\n";
    for(int i=kq.size()-1; i>=0; i--) cout << kq[i] << " ";
    return 0;
}

#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
vector<int>adj[500005];
int n1,n2,m,d[500005];
bool vis[500005];
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    d[s]=0;
    vis[s]=true;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(int v:adj[u]) {
            if(!vis[v]) {
                vis[v]=true;
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("add.inp", "r", stdin);
    freopen("add.out", "w", stdout);
    cin >> n1 >> n2 >> m;
    for(int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    bfs(n1+n2);
    int m1=0,m2=0;
    for(int i=1; i<=n1; i++) m1=max(m1,d[i]);
    for(int i=n1+1; i<=n1+n2; i++) m2=max(m2,d[i]);
    cout << m1+m2+1;
}

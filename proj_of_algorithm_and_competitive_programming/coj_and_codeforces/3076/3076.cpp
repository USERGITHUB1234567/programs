#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,m;
vector<int>adj[200005];
bool vis[200005];
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    vis[s]=true;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(int v:adj[u]) {
            if(!vis[v]) {
                vis[v]=true;
                q.push(v);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<pair<int,int>>re;
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            bfs(i);
            if(i==1)continue;
            re.push_back({1,i});
        }
    }
    cout << re.size() << "\n";
    for(auto [u,v]:re) cout << u << " " << v << "\n";
}

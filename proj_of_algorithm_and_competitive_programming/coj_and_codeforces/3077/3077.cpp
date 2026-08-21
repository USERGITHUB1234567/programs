#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,m;
int p[100005];
vector<int>adj[100005];
vector<int>re;
bool vis[100005];
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    vis[s]=true;
    p[s]=-1;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(int v:adj[u]) {
            if(!vis[v]) {
                q.push(v);
                vis[v]=true;
                p[v]=u;
            }
        }
    }
}
void trace(int s)
{
    if(s==-1) return;
    re.push_back(s);
    trace(p[s]);
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
    bfs(1);
    if(!vis[n]) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    trace(n);
    cout << re.size() << "\n";
    for(int i=re.size()-1; i>=0; i--) {
        cout << re[i] << " ";
    }
}

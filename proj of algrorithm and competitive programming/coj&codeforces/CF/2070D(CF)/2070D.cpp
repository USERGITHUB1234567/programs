#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int mod=998244353;
int d[300005];
bool vis[300005];
void bfs(int i)
{
    queue<int>q;
    q.push(i);
    d[i]=0;
    vis[i]=true;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(int v:adj[u]) {
            if(vis[v]) continue;
            d[v]=d[u]+1;
            q.push(v);
            vis[v]=true;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        memset(d,0,sizeof(d));
        memset(vis,false,sizeof(vis));
        int n;
        cin >> n;
        for(int i=1; i<=n; i++) {
            int p;
            cin >> p;
            adj[i].push_back(p);
            adj[p].push_back(i);
        }
        bfs(1);

    }
}

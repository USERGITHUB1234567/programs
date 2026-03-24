#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int di[10004];
int d[10004];
vector<int>adj[10004];
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    di[s]=0;
    d[s]=1;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(int i:adj[u]) {
            if(di[i]>di[u]+1) {
                di[i]=di[u]+1;
                q.push(i);
                d[i]=d[u];
            }
            else if(di[i]==di[u]+1) {
                d[i]+=d[u];
            }
        }
    }
}
int main()
{se3
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    fill(di,di+10004,1e9);
    int n,m,s,kq=0;
    cin >> n >> m >> s;
    for(int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i=1; i<=n; i++){
        sort(adj[i].begin(), adj[i].end());
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }
    bfs(s);
    for(int i=1; i<=n; i++) {
        if(i!=s and d[i]>=2) kq++;
    }
    cout << kq;
}

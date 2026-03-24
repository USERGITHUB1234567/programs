#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
pair<int,int> adj[1001];
int main()
{
    for(int i=0; i<1001; i++) adj[i].first=-1;adj[i].second=-1;
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u,v,t;
        cin >> u >> v >> t;
        if(adj[u].first==-1 or adj[u].second>t) adj[u]={v,t};
        if(adj[v].first==-1 or adj[v].second>t) adj[v]={u,t};
    }
    int kq=0;
    for(int i=1 i<=n; i++) kq=max(kq,adj[i].second);
    cout << kq;
}

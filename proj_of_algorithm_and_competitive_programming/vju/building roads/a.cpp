#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
vector<int>adj[100005];
bool visited[100005];
void dfs(int u)
{
    for(int i:adj[u]) {
        if(!visited[i]) {
            visited[i]=true;
            dfs(i);
        }
    }
}
int main()
{
    memset(visited,false,sizeof(visited));
    int n,m,d=0;
    cin >> n >> m;
    vector<int>kq;
    for(int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            dfs(i);
            d++;
            if(i!=1)kq.push_back(i);
        }
    }
    cout << d-1 << "\n";
    for(int i=0; i<kq.size(); i++) {
        cout << 1 << " " << kq[i] << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,m;
int si[100005];
vector<int>adj[100005];
bool bfs()
{
    memset(si,0,sizeof(si));
    queue<int>q;
    bool ck=true;
    for(int i=1; i<=n && ck; i++) {
        if(si[i]==0) {
            q.push(i);
            si[i]=1;
            while(!q.empty() && ck) {
                int u=q.front();
                q.pop();
                for(int v:adj[u]) {
                    if(si[v]==0) {
                        si[v]=3-si[u];
                        q.push(v);
                    }
                    else {
                        ck&=(si[u]!=si[v]);
                    }
                }
            }
        }
    }
    return ck;
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
    if(bfs()) {
        for(int i=1; i<n; i++) cout << si[i] << " ";
        cout << si[n];
    }
    else cout << "IMPOSSIBLE";
}

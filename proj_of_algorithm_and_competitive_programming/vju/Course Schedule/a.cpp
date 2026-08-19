#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int in[100005];
vector<int>adj[100005];
int n,m;
vector<int>tp;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    queue<int>q;
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        in[v]++;
    }
    for(int i=1; i<=n; i++) {
        if(in[i]==0) q.push(i);
    }
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        tp.push_back(u);
        for(int v:adj[u]) {
            in[v]--;
            if(in[v]==0) q.push(v);
        }
    }
    if(tp.size()<n) cout << "IMPOSSIBLE";
    else {
        for(int i:tp) cout << i << " ";
    }
}

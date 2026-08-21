#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n,m,in[100001];
    vector<int>a[100001],topo;
    queue<int>q;
    cin >> n >> m;
    memset(in,0,sizeof(in));
    for(int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        in[v]++;
    }
    for(int i=1; i<=n; i++) {
        if(in[i]==0) q.push(i);
    }
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        topo.push_back(u);
        for(int i=0; i<a[u].size(); i++) {
            int v=a[u][i];
            in[v]--;
            if(in[v]==0) q.push(v);
        }
    }
    if(topo.size()<n) cout << "-1\n";
    else for(int x:topo) cout << x << "\n";
    return 0;
}

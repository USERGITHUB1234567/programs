#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int mod=1000000007;
int n,m,in[100005],f[100005];
vector<int>adj[100005],topo;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    f[1]=1;
    cin >> n >> m;
    queue<int>q;
    for(int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        in[v]++;
    }
    for(int i=1; i<=n; i++) if(in[i]==0) q.push(i);
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        topo.push_back(u);
        for(int v:adj[u]) {
            in[v]--;
            if(in[v]==0) {
                q.push(v);
            }
            f[v]+=f[u];
            f[v]%=mod;
        }
    }
    f[n]%=mod;
    cout << f[n];
}

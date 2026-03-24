#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;
const int inf=2e9;
vector<int>adj[200005],topo,tr;
int in[200005],pre[200005],f[200005],n,m;
void trace(int i)
{
    if(i==-1) return;
    tr.push_back(i);
    trace(pre[i]);
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    fill(f,f+100005,-inf);
    f[1]=1;
    pre[1]=-1;
    queue<int>q;
    cin >> n >> m;
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
            if(f[u]!=-inf && f[v]<f[u]+1) {
                f[v]=f[u]+1;
                pre[v]=u;
            }
            in[v]--;
            if(in[v]==0) q.push(v);
        }
    }
    if(f[n]==-inf) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    trace(n);
    cout << f[n] << "\n";
    for(int i=tr.size()-1; i>=0; i--) cout << tr[i] << " ";
}
